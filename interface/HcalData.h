#ifndef HcalData_h
#define HcalData_h

#include <typeinfo>
#include "HCALPFG/PFGAnalysis/interface/HcalTupleTree.h"
#include "HCALPFG/PFGAnalysis/interface/PFGEnums.h"
#include "HCALPFG/PFGAnalysis/interface/Collection.h"
#include "HCALPFG/PFGAnalysis/interface/Object.h"
#include "HCALPFG/PFGAnalysis/interface/HBHEDigi.h"
#include "HCALPFG/PFGAnalysis/interface/HFDigi.h"
#include "HCALPFG/PFGAnalysis/interface/HODigi.h"
#include "HCALPFG/PFGAnalysis/interface/Object.h"

class HcalData : public HcalTupleTree {
public:

	HcalData(TTree *tree=0);

	~HcalData();

	Int_t GetEntry(Long64_t entry);

	template <class T>
	Collection* Digis() {
		Collection* collection = 0;
		if (typeid(T) == typeid(HBHEDigi)) {
			collection = digis_.at(pfg::kHBHE);
		} else if (typeid(T) == typeid(HFDigi)) {
			collection = digis_.at(pfg::kHF);
		} else if (typeid(T) == typeid(HODigi)) {
			collection = digis_.at(pfg::kHO);
		}
		return collection;
	}

	template <class T>
	T Digi(int i) {
		Collection* collection = Digis<T>();
		return collection->GetConstituent<T>(i);
	}

	inline void AddDetector(pfg::Detector_t detector) {
		detectors_.push_back(detector);
	}

private:
	std::vector<pfg::Detector_t> detectors_;
	std::map<pfg::Detector_t, Collection*> digis_;

};

//template HBHEDigi HcalData::Digi<HBHEDigi>(int i);
//template HFDigi HcalData::Digi<HFDigi>(int i);
//template HODigi HcalData::Digi<HODigi>(int i);
//template Collection* HcalData::Digis<HBHEDigi>();
//template Collection* HcalData::Digis<HFDigi>();
//template Collection* HcalData::Digis<HODigi>();

#endif