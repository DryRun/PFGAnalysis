import os
import sys
import ROOT
import HCALPFG.PFGAnalysis.hcal_analysis as hcal_analysis
from math import ceil, floor

ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/HistogramManager.h\"")
ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/PFGEnums.h\"")
ROOT.gSystem.Load(os.path.expandvars("$CMSSW_BASE/lib/slc6_amd64_gcc530/libHCALPFGPFGAnalysis.so"))
ROOT.gROOT.SetBatch(ROOT.kTRUE);
ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)

class TemperatureAnalysis(hcal_analysis.HcalAnalysis):
	def __init__(self):
		super(TemperatureAnalysis, self).__init__()
		self._output_filename = "tmp.root"

	def set_output_filename(self, output_filename):
		self._output_filename = output_filename

	def start(self):
		#self._data.AddDetector(ROOT.pfg.kHB)
		self._data.AddDetector(ROOT.pfg.kHE)
		#self._data.AddDetector(ROOT.pfg.kHF)
		#self._data.AddDetector(ROOT.pfg.kHO)

		self._rbxes = [13, 14, 15]
		self._rbx_iphi = {
			13:[47,48,49,50],
			14:[51,52,53,54],
			15:[55,56,57,58],
		}

		self._runs = [315689, 315690]
		self._run_lses = {315689:[1000,1200], 315690:[1,50]}

		self._histograms = {}
		for run in runs:
			self._histograms[run] = ROOT.Root.HistogramManager()
			self._histograms[run].AddPrefix("h_run{}".format(run))
			for rbx in rbxes:
				self._histograms[run].AddTH2F("sumq_vs_ls_RBX{}".format(rbx), "sumq_vs_ls", "LS", run_lses[run][1]-run_lses[run][0]+1, run_lses[run][0]-0.5, run_lses[run][1]+0.5, "SumQ [fC]", 1000, 0., 1000.)

		self._processed_events = 0

	def run(self, max_nevents=-1, first_event=0):
		if max_nevents > 0:
			limit_nevents = min(max_nevents, self._chain.GetEntries())
		else:
			limit_nevents = self._chain.GetEntries()

		n_checkpoints = 20
		print_every = int(ceil(1. * limit_nevents / n_checkpoints))

		print "[TemperatureAnalysis::run] INFO : Running loop over tree from event {} to {}".format(first_event, limit_nevents - 1)

		self.start_timer()
		for entry in xrange(first_event, limit_nevents):
			self.print_progress(entry, first_event, limit_nevents, print_every)
			self._processed_events += 1
			self._data.GetEntry(entry)

			run = self._data.run
			ls = self._data.ls

			for i in xrange(self._data.Digis("HEDigi")().GetSize()):
				digi = self._data.Digi("HEDigi")(i)
				ieta = digi.ieta()
				iphi = digi.iphi()
				depth = digi.depth()

				# HEM only
				if ieta > 0:
					continue

				# RBX 13, 14, 15 only
				rbx = (((iphi + 2) % 72) + 4 - 1) / 4
				if not rbx in self._rbxes:
					continue

				sumq = digi.fcTotal()
				self._histograms[run].GetTH2F("sumq_vs_ls_RBX{}".format(rbx)).Fill(ls, sumq)


	def finish(self):
		print "[TemperatureAnalysis::finish] INFO : Saving histograms"
		f_out = ROOT.TFile("temperature_histograms.root", "RECREATE")
		for run, histogram_manager in self._histograms.iteritems():
			histogram_manager.SaveAll(f_out)

def make_plots(filename):
	f = ROOT.TFile(filename)
	dir_list = ROOT.gDirectory.GetListOfKeys()
	for key in dir_list:
		if key.GetClassName() == "TH2F":
			hist = key.ReadObj()
			hist_name = hist.GetName()
			if "adcTotal" in hist_name:
				canvas_name = "c_" + hist_name[2:]
				c = ROOT.TCanvas(canvas_name, canvas_name, 800, 600)
				c.SetLogz()
				hist.SetMaximum(128*10);
				hist.Draw("colz")
				c.SaveAs("/home/dryu/HCAL/data/HCALPFG/LaserTag/figures/{}.pdf".format(c.GetName()))

		elif key.GetClassName() == "TH1F":
			hist = key.ReadObj()
			hist_name = hist.GetName()
			if "adc_ts" in hist_name:
				canvas_name = "c_" + hist_name[2:]
				c = ROOT.TCanvas(canvas_name, canvas_name, 800, 600)
				hist.SetMaximum(128);
				hist.GetYaxis().SetTitle("ADC")
				hist.Draw()
				c.SaveAs("/home/dryu/HCAL/data/HCALPFG/LaserTag/figures/{}.pdf".format(c.GetName()))



if __name__ == "__main__":
	import argparse
	parser = argparse.ArgumentParser(description='Produce and plot ieta-iphi histograms to look for buggy events')
	parser.add_argument('--hist', action='store_true', help="Test make histograms over hard-coded test input file")
	parser.add_argument('--plots', action='store_true', help="Make plots from histograms")
	# For running on condor
	parser.add_argument('--hist_condor', action='store_true', help="Make histograms on condor")
	parser.add_argument('--files', type=str, default="test_input.root", help="Input file name(s), comma separated")
	parser.add_argument('--output_name', type=str, default="test_output.root", help="Output file name")
	args = parser.parse_args()

	# List of all input files on eos
	all_input_file_basenames = ["tree_48.root","tree_18.root","tree_31.root","tree_13.root","tree_38.root","tree_37.root","tree_47.root","tree_28.root","tree_42.root","tree_22.root","tree_46.root","tree_45.root","tree_44.root","tree_25.root","tree_26.root","tree_27.root","tree_10.root","tree_43.root","tree_32.root","tree_30.root","tree_36.root","tree_40.root","tree_24.root","tree_16.root","tree_34.root","tree_7.root","tree_19.root","tree_15.root","tree_41.root","tree_3.root","tree_8.root","tree_33.root","tree_21.root","tree_11.root","tree_2.root","tree_14.root","tree_39.root","tree_6.root","tree_12.root","tree_9.root","tree_17.root","tree_23.root","tree_35.root","tree_4.root","tree_5.root","tree_29.root","tree_1.root","tree_20.root"]
	eos_prefix = "root://cmseos.fnal.gov//store/user/dryu/ZeroBias/Run2018A-v1_RAW_20180531_172711/180531_152741/0000/"
	all_input_files = ["{}/{}".format(eos_prefix, x) for x in all_input_file_basenames]

	input_files = args.files.split(",")
	if args.hist:
		analysis = TemperatureAnalysis()
		for input_file in input_files:
			analysis.add_file(input_file)
		analysis.set_output_filename(args.output_name)
		analysis.start()
		analysis.run()
		analysis.finish()

	if args.hist_condor:
		import time
		hadd_scripts = []
		start_directory = os.getcwd()
		job_tag = "job_{}".format(int(floor(time.time())))
		submission_directory = os.path.expandvars("$HOME/nobackup/DQM/pedestal/condor/{}".format(job_tag))
		os.system("mkdir -pv {}".format(submission_directory))
		os.chdir(submission_directory)

		files_per_job = 1
		n_jobs = len(all_input_files)
		#n_jobs = int(math.ceil(1. * len(sample_files[sample]) / files_per_job))

		job_script_path = "{}/run_csubjob.sh".format(submission_directory)
		job_script = open(job_script_path, 'w')
		job_script.write("#!/bin/bash\n")
		#job_script.write("which python\n")
		#job_script.write("python --version\n")
		#job_script.write("ls -lrth /cvmfs/cms.cern.ch/slc6_amd64_gcc530/cms/cmssw/\n")
		job_script.write("input_files=( " + " ".join(all_input_files) + " )\n")
		job_script.write("files_per_job=" + str(files_per_job) + "\n")
		job_script.write("first_file_index=$(($1*$files_per_job))\n")
		job_script.write("max_file_index=$((${#input_files[@]}-1))\n")
		job_script.write("if [ $(($first_file_index+$files_per_job-1)) -gt $max_file_index ]; then\n")
		job_script.write("	files_per_job=$(($max_file_index-$first_file_index+1))\n")
		job_script.write("fi\n")
		job_script.write("declare -a this_input_files=(${input_files[@]:$first_file_index:$files_per_job})\n")
		job_script.write("function join { local IFS=\"$1\"; shift; echo \"$*\"; }\n")
		job_script.write("this_input_files_string=\"$(join , ${this_input_files[@]})\"\n")
		job_script.write("echo \"Input files:\"\n")
		job_script.write("echo $this_input_files_string\n")

		job_command = "python $CMSSW_BASE/src/HCALPFG/PFGAnalysis/scripts/temperature_analysis.py --hist --files $this_input_files_string --output_name temperature_csubjob$1"

		job_command += " 2>&1\n"
		job_script.write(job_command)

		# Check if the output file exists
		#job_script.write("for f in ./InputHistograms*_csubjob$1*root; do\n")
		#job_script.write("\t[ -e \"$f\" ] && echo \"1\" > jobstatus_csubjob$1.txt || echo \"0\" > jobstatus_csubjob$1.txt \n")
		#job_script.write("\tbreak\n")
		#job_script.write("done\n")

		#job_script.write("if ls InputHistograms*{}_csubjob$1*root 1> /dev/null 2&>1; then\n".format(sample))
		#job_script.write("\techo \"1\" > jobstatus_csubjob$1.txt\n")
		#job_script.write("else\n")
		#job_script.write("\techo\"0\" > jobstatus_csubjob$1.txt\n")
		#job_script.write("fi\n")

		job_script.close()
		submission_command = "csub {} --cmssw --no_retar -n {}".format(job_script_path, n_jobs)
		print submission_command

		# Save csub command for resubmission attempts
		submission_script_path = "{}/csub_command.sh".format(submission_directory)
		submission_script = open(submission_script_path, "w")
		submission_script.write("#!/bin/bash\n")
		submission_script.write(submission_command + "\n")
		submission_script.close()

		# Submit jobs
		os.system(submission_command)


		#hadd_scripts.append("{}/hadd.sh".format(submission_directory))
		#hadd_script = open("{}/hadd.sh".format(submission_directory), "w")
		#hadd_script.write("#!/bin/bash\n")
		#hadd_script.write("for f in ./jobstatus_csubjob*.txt; do\n")
		#hadd_script.write("\tif grep -Fxq \"0\" $f; then\n")
		#hadd_script.write("\t\techo \"Subjob failure in $f\"\n")
		#hadd_script.write("\tfi\n")
		#hadd_script.write("done\n")
		#hadd_script.write(os.path.expandvars("hadd $HOME/DAZSLE/data/LimitSetting/InputHistograms_{}_{}.root {}/InputHistograms*csubjob*root\n".format(sample, args.jet_type, submission_directory)))
		#hadd_script.close()
		os.chdir(start_directory)
	# One hadd script to rule them all
	#master_hadd_script_path = os.path.expandvars("$HOME/DAZSLE/data/LimitSetting/condor/master_hadd_{}".format(args.jet_type))
	#if not args.all:
	#	master_hadd_script_path += "_" + str(int(floor(time.time())))
	#master_hadd_script_path += ".sh"
	#master_hadd_script = open(master_hadd_script_path, "w")
	#master_hadd_script.write("#!/bin/bash\n")
	#for hadd_script_path in hadd_scripts:
	#	master_hadd_script.write("source " + hadd_script_path + "\n")
	#master_hadd_script.close()		
		

	if args.plots:
		make_plots("/home/dryu/HCAL/data/HCALPFG/LaserTag/histograms.root")
