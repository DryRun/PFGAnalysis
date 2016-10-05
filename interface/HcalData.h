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


 /**
  * @brief      Class for exposing HCAL data from HcalTupleTree (github.com/HCALPFG/HcalTupleMaker) in pyroot. Digi data is available through the various Digi objects. Data can also be directly accessed in the usual TTree::MakeSelector way.
  */
 

class HcalData : public HcalTupleTree {
public:

	HcalData(TTree *tree=0);

	~HcalData();

	Int_t GetEntry(Long64_t entry);

	/**
	 * @brief      Returns a collection of digis based on the template class (HBHEDigi, HFDigi, or HODigi).
	 * @return     Collection of digis.
	 */
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

	/**
	 * Returns a single digi. Type is determined from the template class.	
	 * @param  i Index of digi
	 * @return   Digi
	 */
	template <class T>
	T Digi(int i) {
		Collection* collection = Digis<T>();
		return collection->GetConstituent<T>(i);
	}

	/**
	 * Make a detector's data available through HcalData::Digi and HcalData::Digis.
	 * @param detector pfg::kHBHE, pfg::kHF, or pfg::kHO. 
	 */
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