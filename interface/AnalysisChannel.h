#ifndef AnalysisChannel_h
#define AnalysisChannel_h

#include "HCALPFG/PFGAnalysis/interface/AnalysisBase.h"
#include "MyTools/RootUtils/interface/HistogramManager.h"

class AnalysisChannel : public AnalysisBase {

public:
	AnalysisChannel();
	~AnalysisChannel();
	void SlaveBegin(TTree *tree);
	Bool_t Process(Long64_t entry);

	inline void AddDetector(pfg::Detector_t detector) {
		detectors_.push_back(detector);
	}

private:
	std::vector<pfg::Detector_t> detectors_;
	std::map<pfg::Detector_t, Root::HistogramManager*> histograms_;

};


#endif