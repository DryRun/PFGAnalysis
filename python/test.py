import os
import sys
import ROOT
from ROOT import *

ROOT.gInterpreter.Declare("#include \"HCALPFG/PFGAnalysis/interface/HcalData.h\"")
gSystem.Load("/home/dryu/HCAL/CMSSW_8_0_8_patch1/lib/slc6_amd64_gcc530/libHCALPFGPFGAnalysis.so")
ROOT.gROOT.ProcessLine('template HBHEDigi HcalData::Digi<HBHEDigi>(int i);')

ROOT.gInterpreter.Declare("#include \"MyTools/RootUtils/interface/HistogramManager.h\"")
gSystem.Load("/home/dryu/HCAL/CMSSW_8_0_8_patch1/lib/slc6_amd64_gcc530/libMyToolsRootUtils.so")

histograms = {}
histograms["HBHE"] = Root.HistogramManager()
histograms["HBHE"].AddPrefix("h_hbhe_")
histograms["HBHE"].AddTH2F("avg_adcTotal", "Average adcTotal", "IEta", 83, -41.5, 41.5, "IPhi", 72, 0.5, 72.5)

f_in = TFile("/home/dryu/data/HCAL/HCALPFG/LaserTag/hcalTupleTree.root", "READ")
t = f_in.Get("hcalTupleTree/tree")
data = HcalData(t)
data.AddDetector(pfg.kHBHE)
nevents = 0
for i in xrange(t.GetEntriesFast()):
	if i % 1000 == 0:
		print "Entry {}".format(i)
	data.GetEntry(i)
	nevents += 1
	for i in xrange(data.Digis("HBHEDigi")().GetSize()):
		histograms["HBHE"].GetTH2F("avg_adcTotal").Fill(data.Digi("HBHEDigi")(i).ieta(), data.Digi("HBHEDigi")(i).iphi(), data.Digi("HBHEDigi")(i).adcTotal())
f_in.Close()
histograms["HBHE"].GetTH2F("avg_adcTotal").Scale(1. / nevents)
f_out = TFile("/home/dryu/data/HCAL/HCALPFG/LaserTag/histograms.root", "RECREATE")
histograms["HBHE"].GetTH2F("avg_adcTotal").Write()
f_out.Close()