import os
import sys
import ROOT
import HCALPFG.PFGAnalysis.hcal_analysis as hcal_analysis
from math import ceil

ROOT.gInterpreter.Declare("#include \"MyTools/RootUtils/interface/HistogramManager.h\"")
ROOT.gSystem.Load("/home/dryu/HCAL/CMSSW_8_0_8_patch1/lib/slc6_amd64_gcc530/libMyToolsRootUtils.so")
ROOT.gROOT.SetBatch(ROOT.kTRUE);
ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)

class ChannelAnalysis(hcal_analysis.HcalAnalysis):
	def __init__(self):
		super(ChannelAnalysis, self).__init__()


	def start(self):
		self._histograms = ROOT.Root.HistogramManager()
		self._histograms.AddPrefix("h_hbhe_")
		for depth in xrange(self._detector_volumes["HBHE"]["depth"][0], self._detector_volumes["HBHE"]["depth"][1] + 1):
			self._histograms.AddTH2F("avg_adcTotal_d{}".format(depth), "Average adcTotal, depth {}".format(depth), 
				"IEta", self._detector_volumes["HBHE"]["ieta"][1] - self._detector_volumes["HBHE"]["ieta"][0] + 1, self._detector_volumes["HBHE"]["ieta"][0] - 0.5, self._detector_volumes["HBHE"]["ieta"][1] + 0.5,
				"IPhi", self._detector_volumes["HBHE"]["iphi"][1] - self._detector_volumes["HBHE"]["iphi"][0] + 1, self._detector_volumes["HBHE"]["iphi"][0] - 0.5, self._detector_volumes["HBHE"]["iphi"][1] + 0.5
			)
		self._processed_events = 0


	def run(self, max_nevents=-1, first_event=0):
		if max_nevents > 0:
			limit_nevents = min(max_nevents, self._chain.GetEntries())
		else:
			limit_nevents = self._chain.GetEntries()

		n_checkpoints = 20
		print_every = int(ceil(1. * limit_nevents / n_checkpoints))

		print "[ChannelAnalysis::run] INFO : Running loop over tree from event {} to {}".format(first_event, limit_nevents - 1)

		self.start_timer()
		for entry in xrange(first_event, limit_nevents):
			self.print_progress(entry, first_event, limit_nevents, print_every)
			self._processed_events += 1
			self._data.GetEntry(entry)

			# Make histograms specific to this event
			for depth in xrange(self._detector_volumes["HBHE"]["depth"][0], self._detector_volumes["HBHE"]["depth"][1] + 1):
				self._histograms.AddTH2F("adcTotal_d{}_event_{}".format(depth, self._data.event), "Average adcTotal, depth {}, event {}".format(depth, self._data.event), 
					"IEta", self._detector_volumes["HBHE"]["ieta"][1] - self._detector_volumes["HBHE"]["ieta"][0] + 1, self._detector_volumes["HBHE"]["ieta"][0] - 0.5, self._detector_volumes["HBHE"]["ieta"][1] + 0.5,
					"IPhi", self._detector_volumes["HBHE"]["iphi"][1] - self._detector_volumes["HBHE"]["iphi"][0] + 1, self._detector_volumes["HBHE"]["iphi"][0] - 0.5, self._detector_volumes["HBHE"]["iphi"][1] + 0.5
				)

			# Loop over digis
			for i in xrange(self._data.Digis("HBHEDigi")().GetSize()):
				ieta = self._data.Digi("HBHEDigi")(i).ieta()
				iphi = self._data.Digi("HBHEDigi")(i).iphi()
				depth = self._data.Digi("HBHEDigi")(i).depth()
				self._histograms.GetTH2F("avg_adcTotal_d{}".format(depth)).Fill(ieta, iphi, self._data.Digi("HBHEDigi")(i).adcTotal())
				self._histograms.GetTH2F("adcTotal_d{}_event_{}".format(depth, self._data.event)).Fill(ieta, iphi, self._data.Digi("HBHEDigi")(i).adcTotal())


	def finish(self):
		for depth in xrange(self._detector_volumes["HBHE"]["depth"][0], self._detector_volumes["HBHE"]["depth"][1] + 1):
			self._histograms.GetTH2F("avg_adcTotal_d{}".format(depth)).Scale(1. / self._processed_events)

		print "[ChannelAnalysis::finish] INFO : Saving histograms to {}".format("/home/dryu/HCAL/data/HCALPFG/LaserTag/histograms.root")
		f_out = ROOT.TFile("/home/dryu/HCAL/data/HCALPFG/LaserTag/histograms.root", "RECREATE")
		self._histograms.SaveAll(f_out)

def make_plots(filename):
	f = ROOT.TFile(filename)
	dir_list = ROOT.gDirectory.GetListOfKeys()
	for key in dir_list:
		obj = key.ReadObj()
		if key.GetClassName() == "TH2F":
			hist_name = obj.GetName()
			canvas_name = hist_name.replace("h_", "c_")
			c = ROOT.TCanvas(canvas_name, canvas_name, 800, 600)
			obj.Draw("colz")
			c.SaveAs("/home/dryu/HCAL/data/HCALPFG/LaserTag/figures/{}.pdf".format(c.GetName()))


if __name__ == "__main__":
	import argparse
	parser = argparse.ArgumentParser(description='Produce and plot ieta-iphi histograms to look for buggy events')
	parser.add_argument('--hist', action='store_true', help="Run over hcalTupleTree and produce histograms")
	parser.add_argument('--plots', action='store_true', help="Make plots from histograms")
	args = parser.parse_args()

	if args.hist:
		analysis = ChannelAnalysis()
		analysis.add_file("/home/dryu/HCAL/data/HCALPFG/LaserTag/hcalTupleTree.root ")
		analysis.start()
		analysis.run()
		analysis.finish()

	if args.plots:
		make_plots("/home/dryu/HCAL/data/HCALPFG/LaserTag/histograms.root")
