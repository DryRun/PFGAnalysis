import os
import sys
from abc import ABCMeta, abstractmethod
import time
import datetime
import ROOT
from ROOT import *

ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/HcalData.h\"")
ROOT.gSystem.Load("/home/dryu/HCAL/CMSSW_8_0_8_patch1/lib/slc6_amd64_gcc530/libHCALPFGPFGAnalysis.so")
ROOT.gROOT.ProcessLine('template HBHEDigi HcalData::Digi<HBHEDigi>(int i);') # Unfortunate hack needed for pyroot to recognize templated member functions

class HcalAnalysis(object):
	__metaclass__ = ABCMeta
	def __init__(self, tree_name="hcalTupleTree/tree"):
		self._files = []
		self._chain = ROOT.TChain(tree_name)
		self._data = HcalData(self._chain)
		self._detectors = ["HBHE", "HF", "HO"]
		self._detector_volumes = {
			"HBHE":{
				"ieta":[-29,29],
				"iphi":[1,72],
				"depth":[1,4]
			},
			"HF":{
				"ieta":[-41,-29] + [29,41],
				"iphi":[1,72],
				"depth":[1,2]
			},
			"HO":{
				"ieta":[-29,29],
				"iphi":[1,72],
				"depth":[4,4]
			}
		}
		self._ts_start = -1

	def add_file(self, filename):
		self._chain.Add(filename)
		self._files.append(filename)

	def start_timer(self):
		self._ts_start = time.time()
		print "[HcalAnalysis::start_timer] INFO : Start time: {}".format(datetime.datetime.fromtimestamp(self._ts_start).strftime('%Y-%m-%d %H:%M:%S'))

	def print_progress(self, this_event, first_event, last_event, print_every):
		if this_event % print_every == 0:
			print "[HcalAnalysis::print_progress] INFO : Processing event {} / {}".format(this_event + 1, last_event)
			if this_event != first_event:
				if self._ts_start > 0 :
					elapsed_time = time.time() - self._ts_start
					estimated_completion = self._ts_start + (1. * elapsed_time * (last_event - first_event) / (this_event - first_event))
					m, s = divmod(elapsed_time, 60)
					h, m = divmod(m, 60)
					print "[HcalAnalysis::print_progress] INFO : \tElapsed time: {} : {} : {:.2}".format(round(h, 0), round(m, 0), s)
					print "[HcalAnalysis::print_progress] INFO : \tEstimated finish time: {}".format(datetime.datetime.fromtimestamp(estimated_completion).strftime('%Y-%m-%d %H:%M:%S'))
				else:
					print "[HcalAnalysis::print_progress] INFO : \tFor time estimates, call self.start_timer() right before starting the event loop"


	# Anything before looping over the tree.
	# Histogram definitions go here.
	@abstractmethod
	def start(self):
		pass

	# Main event loop.
	# Fill histograms here. 
	@abstractmethod
	def run(self, max_nevents=-1, first_event=0, nprint=-1):
		pass

	# Anything after looping over the tree.
	# Histogram postprocessing and output go here.
	@abstractmethod
	def finish(self):
		pass

