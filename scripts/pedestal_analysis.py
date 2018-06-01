import os
import sys
import ROOT
import HCALPFG.PFGAnalysis.hcal_analysis as hcal_analysis
from math import ceil

ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/HistogramManager.h\"")
ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/PFGEnums.h\"")
ROOT.gSystem.Load(os.path.expandvars("$CMSSW_BASE/lib/slc6_amd64_gcc530/libHCALPFGPFGAnalysis.so"))
ROOT.gROOT.SetBatch(ROOT.kTRUE);
ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)

class PedestalAnalysis(hcal_analysis.HcalAnalysis):
	def __init__(self):
		super(PedestalAnalysis, self).__init__()


	def start(self):
		self._data.AddDetector(ROOT.pfg.kHB)
		self._data.AddDetector(ROOT.pfg.kHE)
		#self._data.AddDetector(ROOT.pfg.kHF)
		#self._data.AddDetector(ROOT.pfg.kHO)

		self._subdet_histograms = {}
		for subdet in ["HB", "HE"]: # , "HF", "HO"
			self._subdet_histograms[subdet] = ROOT.Root.HistogramManager()
			self._subdet_histograms[subdet].AddPrefix("h_{}_".format(subdet))
			self._subdet_histograms[subdet].AddTH1F("occupancy_bx", "occupancy_bx", "BX", 3564, -0.5, 3564-0.5)
			self._subdet_histograms[subdet].AddTH1F("occupancy_cut_bx", "occupancy_cut_bx", "BX", 3564, -0.5, 3564-0.5)
			self._subdet_histograms[subdet].AddTH1F("sumq", "sumq", "#Sigma_{TS} q_{TS} [fC]", 1000, 0., 1000.)
		self._processed_events = 0

	def run(self, max_nevents=-1, first_event=0):
		if max_nevents > 0:
			limit_nevents = min(max_nevents, self._chain.GetEntries())
		else:
			limit_nevents = self._chain.GetEntries()

		n_checkpoints = 20
		print_every = int(ceil(1. * limit_nevents / n_checkpoints))

		print "[PedestalAnalysis::run] INFO : Running loop over tree from event {} to {}".format(first_event, limit_nevents - 1)

		self.start_timer()
		for entry in xrange(first_event, limit_nevents):
			self.print_progress(entry, first_event, limit_nevents, print_every)
			self._processed_events += 1
			self._data.GetEntry(entry)

			bx = self._data.bx
			print self._data.fChain.bx
			print bx

			for i in xrange(self._data.Digis("HBHEDigi")().GetSize()):
				digi = self._data.Digi("HBHEDigi")(i)
				ieta = digi.ieta()
				iphi = digi.iphi()
				depth = digi.depth()
				sumq = digi.fcTotal()
				self._subdet_histograms["HB"].GetTH1F("occupancy_bx").Fill(bx)
				if (sumq > 25.):
					self._subdet_histograms["HB"].GetTH1F("occupancy_cut_bx").Fill(bx)
				self._subdet_histograms["HB"].GetTH1F("sumq").Fill(sumq)

			for i in xrange(self._data.Digis("HEDigi")().GetSize()):
				digi = self._data.Digi("HEDigi")(i)
				ieta = digi.ieta()
				iphi = digi.iphi()
				depth = digi.depth()
				sumq = digi.fcTotal()
				self._subdet_histograms["HE"].GetTH1F("occupancy_bx").Fill(bx)
				if (sumq > 25.):
					self._subdet_histograms["HE"].GetTH1F("occupancy_cut_bx").Fill(bx)
				self._subdet_histograms["HE"].GetTH1F("sumq").Fill(sumq)

			for i in xrange(self._data.Digis("HFDigi")().GetSize()):
				digi = self._data.Digi("HFDigi")(i)
				ieta = digi.ieta()
				iphi = digi.iphi()
				depth = digi.depth()
				sumq = digi.fcTotal()
				self._subdet_histograms["HF"].GetTH1F("occupancy_bx").Fill(bx)
				if (sumq > 25.):
					self._subdet_histograms["HF"].GetTH1F("occupancy_cut_bx").Fill(bx)
				self._subdet_histograms["HF"].GetTH1F("sumq").Fill(sumq)

	def finish(self):
		print "[PedestalAnalysis::finish] INFO : Saving histograms"
		f_out = ROOT.TFile("test_output.root", "RECREATE")
		for subdet, histogram_manager in self._subdet_histograms.iteritems():
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
	parser.add_argument('--hist', action='store_true', help="Run over hcalTupleTree and produce histograms")
	parser.add_argument('--plots', action='store_true', help="Make plots from histograms")
	args = parser.parse_args()

	if args.hist:
		analysis = PedestalAnalysis()
		analysis.add_file("test_input.root")
		analysis.start()
		analysis.run()
		analysis.finish()

	if args.plots:
		make_plots("/home/dryu/HCAL/data/HCALPFG/LaserTag/histograms.root")
