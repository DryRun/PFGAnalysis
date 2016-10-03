#ifndef AnalysisChannel_cc
#define AnalysisChannel_cc

#include "HCALPFG/PFGAnalysis/interface/AnalysisChannel.h"

AnalysisChannel::AnalysisChannel() {}

AnalysisChannel::~AnalysisChannel() {}

void AnalysisChannel::SlaveBegin(TTree *tree) {
	for (auto& it_detector : detectors_){
		histograms_[it_detector] = new Root::HistogramManager();
		histograms_[it_detector]->AddPrefix("h_" + detector_strings_[it_detector] + "_");

		histograms_[it_detector]->AddTH2F("adcTotal", "adcTotal", "IEta", range_ieta[it_detector].second - range_ieta[it_detector].first + 1, range_ieta[it_detector].first - 0.5, range_ieta[it_detector].second + 0.5, "IPhi", range_iphi[it_detector].second - range_iphi[it_detector].first + 1, range_iphi[it_detector].first - 0.5, range_iphi[it_detector].second + 0.5);
	}
	
}

Bool_t AnalysisChannel::Process(Long64_t entry) {
	this->GetEntry(entry);

}



#endif
