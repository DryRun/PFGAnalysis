#ifndef AnalysisChannel_cc
#define AnalysisChannel_cc

#include "HCALPFG/PFGAnalysis/interface/AnalysisChannel.h"

AnalysisChannel::AnalysisChannel() {}

AnalysisChannel::~AnalysisChannel() {}

void AnalysisChannel::SlaveBegin(TTree *tree) {
	// Branch loading
	tree->SetBranchStatus("*", 0);
	tree->SetBranchStatus("bx", 1);
	tree->SetBranchStatus("event", 1);
	tree->SetBranchStatus("ls", 1);
	tree->SetBranchStatus("run", 1);
	for (auto& it_detector : detectors_) {
		if (it_detector == pfg::kHFP || it_detector == pfg::kHFM) {
			tree->SetBranchStatus("*HF*", 1);
		} else if (it_detector == pfg::kHBHE) {
			tree->SetBranchStatus("*HBHE*", 1);
		} else if (it_detector == pfg::kHO) {
			tree->SetBranchStatus("*HO*", 1);
		}
	}

	for (auto& it_detector : detectors_) {
		histograms_[it_detector] = new Root::HistogramManager();
		histograms_[it_detector]->AddPrefix("h_" + pfg::detector_strings[it_detector] + "_");
		histograms_[it_detector]->AddTH2F("adcTotal", "adcTotal", 
			"IEta", pfg::detector_volumes[it_detector].ieta.second - pfg::detector_volumes[it_detector].ieta.first + 1, pfg::detector_volumes[it_detector].ieta.first - 0.5, pfg::detector_volumes[it_detector].ieta.second + 0.5, 
			"IPhi", pfg::detector_volumes[it_detector].iphi.second - pfg::detector_volumes[it_detector].iphi.first + 1, pfg::detector_volumes[it_detector].iphi.first - 0.5, pfg::detector_volumes[it_detector].iphi.second + 0.5
		);
	}
}

Bool_t AnalysisChannel::Process(Long64_t entry) {
	this->GetEntry(entry);
	if (std::find(detectors_.begin(), detectors_.end(), pfg::kHBHE) != detectors_.end()) {
		int n_digis = 
	}
}



#endif
