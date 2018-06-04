import os
import sys
import ROOT
import HCALPFG.PFGAnalysis.hcal_analysis as hcal_analysis
from math import ceil, floor

ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/HistogramManager.h\"")
ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/PFGEnums.h\"")
ROOT.gSystem.Load(os.path.expandvars("$CMSSW_BASE/lib/$SCRAM_ARCH/libHCALPFGPFGAnalysis.so"))
ROOT.gROOT.SetBatch(ROOT.kTRUE)
ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)
from MyTools.RootUtils.seaborn_colors import SeabornColors
seaborn_colors = SeabornColors()
seaborn_colors.load_palette("Blues_d", palette_dir=os.path.expandvars("$CMSSW_BASE/src/MyTools/RootUtils/python/seaborn_palettes"))
seaborn_colors.load_palette("Reds_d", palette_dir=os.path.expandvars("$CMSSW_BASE/src/MyTools/RootUtils/python/seaborn_palettes"))
seaborn_colors.load_palette("Oranges_d", palette_dir=os.path.expandvars("$CMSSW_BASE/src/MyTools/RootUtils/python/seaborn_palettes"))
seaborn_colors.load_palette("Greens_d", palette_dir=os.path.expandvars("$CMSSW_BASE/src/MyTools/RootUtils/python/seaborn_palettes"))
seaborn_colors.load_palette("Purples_d", palette_dir=os.path.expandvars("$CMSSW_BASE/src/MyTools/RootUtils/python/seaborn_palettes"))

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
		for run in self._runs:
			self._histograms[run] = ROOT.Root.HistogramManager()
			self._histograms[run].AddPrefix("h_run{}".format(run))
			for rbx in self._rbxes:
				self._histograms[run].AddTH2F("sumq_vs_ls_RBX{}".format(rbx), "sumq_vs_ls", "LS", self._run_lses[run][1]-self._run_lses[run][0]+1, self._run_lses[run][0]-0.5, self._run_lses[run][1]+0.5, "SumQ [fC]", 1000, 0., 1000.)

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
		f_out = ROOT.TFile(self._output_filename, "RECREATE")
		for run, histogram_manager in self._histograms.iteritems():
			histogram_manager.SaveAll(f_out)

def make_plots(filename):
	import datetime
	from ls_timestamps import ls_timestamps
	f = ROOT.TFile(filename)
	rbxes = [13, 14, 15]
	runs = [315689, 315690]
	colors = {
		13:seaborn_colors.get_root_color("Greens_d", 3),
		14:seaborn_colors.get_root_color("Blues_d", 3),
		15:seaborn_colors.get_root_color("Reds_d", 3),
	}

	hists = {}
	profs = {}
	graphs = {}
	graphs_ls = {}
	for run in runs:
		hists[run] = {}
		profs[run] = {}
		graphs[run] = {}
		graphs_ls[run] = {}
		c = ROOT.TCanvas("c_sumq_vs_time_{}".format(run), "SumQ vs LS", 800, 600)
		l = ROOT.TLegend(0.6, 0.7, 0.8, 0.88)
		l.SetFillStyle(0)
		l.SetBorderSize(0)
		for rbx in rbxes:
			hists[run][rbx] = f.Get("h_run{}sumq_vs_ls_RBX{}".format(run, rbx))
			#hists[run][rbx].GetXaxis().SetTimeDisplay(1)
			#for bin in xrange(1, hists[run][rbx].GetXaxis().GetNbins() + 1):
			#	#ls = hists[run][rbx].GetXaxis().GetBinCenter(bin)
			#	#timestr = datetime.datetime.utcfromtimestamp(ls_timestamps[run][ls]).strftime('%H:%M:%S')
			#	#print timestr
			#	#hists[run][rbx].GetXaxis().SetBinLabel(bin, ls_timestamps[run][ls])
			profs[run][rbx] = hists[run][rbx].ProfileX()

			graphs[run][rbx] = ROOT.TGraphErrors(profs[run][rbx].GetNbinsX())
			graphs_ls[run][rbx] = ROOT.TGraphErrors(profs[run][rbx].GetNbinsX())
			for bin in xrange(1, profs[run][rbx].GetXaxis().GetNbins() + 1):
				ls = int(profs[run][rbx].GetXaxis().GetBinCenter(bin))
				ts_start = ls_timestamps[run][ls]
				if ls+1 in ls_timestamps[run]:
					ts_end = ls_timestamps[run][ls+1]
				else:
					ts_end = ts_start + 23.
				ts = (ts_start + ts_end) / 2.
				graphs[run][rbx].SetPoint(bin-1, ts, profs[run][rbx].GetBinContent(bin))
				graphs[run][rbx].SetPointError(bin-1, (ts_start - ts_end) / 2., profs[run][rbx].GetBinError(bin))
				graphs_ls[run][rbx].SetPoint(bin-1, ls, profs[run][rbx].GetBinContent(bin))
				graphs_ls[run][rbx].SetPointError(bin-1, 0.5, profs[run][rbx].GetBinError(bin))

			graphs[run][rbx].GetHistogram().GetXaxis().SetTimeDisplay(1)
			graphs[run][rbx].GetHistogram().GetXaxis().SetTimeFormat("%H:%M")
			graphs[run][rbx].GetHistogram().GetXaxis().SetTimeOffset(0, "GMT")

			graphs[run][rbx].SetMarkerStyle(20 + rbx - 13)
			graphs[run][rbx].SetMarkerColor(colors[rbx])
			graphs[run][rbx].SetLineColor(colors[rbx])

			graphs_ls[run][rbx].SetMarkerStyle(20 + rbx - 13)
			graphs_ls[run][rbx].SetMarkerColor(colors[rbx])
			graphs_ls[run][rbx].SetLineColor(colors[rbx])
			l.AddEntry(graphs[run][rbx], "RBX {}".format(rbx), "lp")
			if rbx == rbxes[0]:
				graphs[run][rbx].GetHistogram().SetMinimum(540)
				graphs[run][rbx].GetHistogram().SetMaximum(580)
				graphs[run][rbx].GetHistogram().GetXaxis().SetTitle("Time (UTC)")
				graphs[run][rbx].GetHistogram().GetYaxis().SetTitle("SumQ")
				graphs[run][rbx].Draw("ap")
			else:
				graphs[run][rbx].Draw("p")
		l.Draw()
		c.SaveAs("/uscms/home/dryu/DQM/Studies/temperature/{}.pdf".format(c.GetName()))

		c_ls = ROOT.TCanvas("c_sumq_vs_ls_{}".format(run), "SumQ vs LS", 800, 600)
		for rbx in rbxes:
			if rbx == rbxes[0]:
				graphs_ls[run][rbx].GetHistogram().SetMinimum(540)
				graphs_ls[run][rbx].GetHistogram().SetMaximum(580)
				graphs_ls[run][rbx].GetHistogram().GetXaxis().SetTitle("Time (UTC)")
				graphs_ls[run][rbx].GetHistogram().GetYaxis().SetTitle("SumQ")
				graphs_ls[run][rbx].Draw("ap")
			else:
				graphs_ls[run][rbx].Draw("p")
		l.Draw()
		c_ls.SaveAs("/uscms/home/dryu/DQM/Studies/temperature/{}.pdf".format(c_ls.GetName()))

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

		job_command = "python $CMSSW_BASE/src/HCALPFG/PFGAnalysis/scripts/temperature_analysis.py --hist --files $this_input_files_string --output_name temperature_csubjob$1.root"

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
		make_plots("/uscms/home/dryu/DQM/Studies/temperature/temperature_histograms.root")
