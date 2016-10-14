# PFGAnalysis
This package performs a framework for analyzing HcalTupleTrees (https://github.com/HCALPFG/HcalTupleMaker). It is similar to https://github.com/HCALPFG/HcalTupleAnalyzer, but uses python instead of ROOT macros. 

The idea is to have an analysis specified in a single file, rather than having a .C macro, a .txt file specifying the inputs, and another .txt file specifying the TTree names as in HcalTupleAnalyzer. An full example analysis is at scripts/ChannelAnalysis.py. Here's a quick example:

import HCALPFG.PFGAnalysis.hcal_analysis as hcal_analysis
def MyAnalysis(hcal_analysis.HcalAnalysis):
	def __init__(self):
		super(MyAnalysis, self).__init__()

	def start(self):
		# Define histograms here

	def run(self, max_nevents=-1, first_event=0):
		# Loop over events and fill histograms here

		if max_nevents > 0:
			limit_nevents = min(max_nevents, self._chain.GetEntries())
		else:
			limit_nevents = self._chain.GetEntries()
		for entry in xrange(first_event, limit_nevents):
			self._data.GetEntry(entry)
			for i in xrange(self._data.Digis("HBHEDigi")().GetSize()):
				ieta  = self._data.Digi("HBHEDigi")(i).ieta()
				iphi  = self._data.Digi("HBHEDigi")(i).iphi()
				depth = self._data.Digi("HBHEDigi")(i).depth()
				adcTotal = self._data.Digi("HBHEDigi")(i).adcTotal()
				print "This digis has ieta={}, iphi={}, depth={}, adcTotal={}".format(ieta, iphi, depth, adcTotal)

	def finish(self):
		# Save output stuff here

if __name__ == "__main__":
	analysis = MyAnalysis()
	analysis.add_file("input_file.root")
	analysis.start()
	analysis.run()
	analysis.finish()
