#ifndef HcalData_cc
#define HcalData_cc

#include "HCALPFG/PFGAnalysis/interface/HcalData.h"

HcalData::HcalData(TTree *tree) : HcalTupleTree(tree) {
	AddDetector(pfg::kHB);
	AddDetector(pfg::kHE);
	AddDetector(pfg::kHF);
	//AddDetector(pfg::kHO);
}

HcalData::~HcalData() {
	digis_.clear();
}

Int_t HcalData::GetEntry(Long64_t entry) {
	// Clear previous event
	digis_.clear();

	// Load new event
	Int_t ret = fChain->GetEntry(entry);
	for (auto& it_detector : detectors_) {
		size_t n_digis = 0;
		if (it_detector == pfg::kHB) {
			n_digis = HBHEDigiIEta->size();
		} else if (it_detector == pfg::kHE) {
			n_digis = QIE11DigiIEta->size();
		} else if (it_detector == pfg::kHF) {
			n_digis = QIE10DigiIEta->size();
		} else if (it_detector == pfg::kHO) {
			n_digis = HODigiIEta->size();
		}

		digis_[it_detector] = new Collection(*this, n_digis);
	}

	return ret;
}



#endif