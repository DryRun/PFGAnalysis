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

private:
	std::map<pfg::Detector_t, Root::HistogramManager*> histograms_;

};


#endif