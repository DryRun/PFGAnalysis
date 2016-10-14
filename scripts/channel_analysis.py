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

		self._interesting_events = []
		self._interesting_events.append(7572462) # Laser event
		self._interesting_events.append(7574778) # Last laser event before it turned off
		self._interesting_events.append(7572594) # Weird whole-HBHE event

		self._interesting_channels = []
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(20, 20, 1))
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(-20, 20, 1))
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(20, 20, 2))
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(-20, 20, 2))
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(20, 20, 3))
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(-20, 20, 3))
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(20, 20, 4))
		self._interesting_channels.append(ROOT.pfg.ChannelIndex(-20, 20, 4))

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
				self._histograms.AddTH2F("adcTotal_d{}_event_{}_bx_{}_ls_{}".format(depth, self._data.event, self._data.bx, self._data.ls), 
					"Average adcTotal, depth {}, event {}, bx {}".format(depth, self._data.event, self._data.bx), 
					"IEta", self._detector_volumes["HBHE"]["ieta"][1] - self._detector_volumes["HBHE"]["ieta"][0] + 1, self._detector_volumes["HBHE"]["ieta"][0] - 0.5, self._detector_volumes["HBHE"]["ieta"][1] + 0.5,
					"IPhi", self._detector_volumes["HBHE"]["iphi"][1] - self._detector_volumes["HBHE"]["iphi"][0] + 1, self._detector_volumes["HBHE"]["iphi"][0] - 0.5, self._detector_volumes["HBHE"]["iphi"][1] + 0.5
				)

			# Loop over digis
			for i in xrange(self._data.Digis("HBHEDigi")().GetSize()):
				ieta  = self._data.Digi("HBHEDigi")(i).ieta()
				iphi  = self._data.Digi("HBHEDigi")(i).iphi()
				depth = self._data.Digi("HBHEDigi")(i).depth()
				self._histograms.GetTH2F("avg_adcTotal_d{}".format(depth)).Fill(ieta, iphi, self._data.Digi("HBHEDigi")(i).adcTotal())
				self._histograms.GetTH2F("adcTotal_d{}_event_{}_bx_{}_ls_{}".format(depth, self._data.event, self._data.bx, self._data.ls)).Fill(ieta, iphi, self._data.Digi("HBHEDigi")(i).adcTotal())

				# Interesting events and channels
				if self._data.event in self._interesting_events:
					for channel in self._interesting_channels:
						if channel.ieta == ieta and channel.iphi == iphi and channel.depth == depth:
							hname = "adc_ts_event_{}_ieta_{}_iphi_{}_depth_{}".format(self._data.event, ieta, iphi, depth)
							self._histograms.AddTH1F(hname, hname, "TS", 11, -0.5, 10.5)
							for ts in xrange(self._data.Digi("HBHEDigi")(i).size()):
								self._histograms.GetTH1F(hname).SetBinContent(ts, self._data.Digi("HBHEDigi")(i).adc(ts))

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
		analysis = ChannelAnalysis()
		analysis.add_file("/home/dryu/HCAL/data/HCALPFG/LaserTag/hcalTupleTree_big.root ")
		analysis.start()
		analysis.run()
		analysis.finish()

	if args.plots:
		make_plots("/home/dryu/HCAL/data/HCALPFG/LaserTag/histograms.root")
