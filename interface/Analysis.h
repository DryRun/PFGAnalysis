#ifndef Analysis_h
#define Analysis_h

#include "FWCore/Framework/interface/global/EDAnalyzer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/StreamID.h"
#include "FWCore/Concurrency/interface/SerialTaskQueue.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "EventFilter/HcalRawToDigi/interface/HcalUnpacker.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"
#include "CalibFormats/HcalObjects/interface/HcalDbService.h"
#include "CalibFormats/HcalObjects/interface/HcalDbRecord.h"
#include "CalibFormats/HcalObjects/interface/HcalCoderDb.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "DataFormats/HcalDetId/interface/HcalGenericDetId.h"
#include "CondFormats/HcalObjects/interface/HcalElectronicsMap.h"

#include "DQM/HcalCommon/interface/Utilities.h"
#include "DQM/HcalCommon/interface/ElectronicsMap.h"

#include <string>
#include <map>
#include <vector>
#include <TTree.h>
#include <TSpectrum.h>
#include <TF1.h>
#include <TMath.h>

// Stream data container holds objects duplicated for each stream.
// This means basically any histogram that gets filled for each event
class AnalysisStreamData {
public:
	// Histograms and counters
	int _nevents;
	// TH1D *_example_hist;

	// Infrastructure
	// hcaldqm::electronicsmap::ElectronicsMap _ehashmap;

	// Accumulation method: for adding the streams back together at the end of the job
	inline void add(const AnalysisStreamData* data) {
		_nevents += data->_nevents;
		// _example_hist->Add(data->_example_hist);
	}

	inline void reset() {
		// this->_example_hist.Reset();
	}
};

class Analysis : public edm::global::EDAnalyzer<edm::StreamCache<AnalysisStreamData>, edm::RunSummaryCache<AnalysisStreamData>> {

public:
	edm::InputTag	_tagQIE10;
	edm::EDGetTokenT<QIE10DigiCollection> _tokQIE10;
	std::vector<FCDChannel> _channels;
	edm::Service<TFileService> _fs;
	mutable edm::SerialTaskQueue _queue; //queue is used to serialize access to output file

public:
	explicit Analysis(const edm::ParameterSet& ps);// : pset(iConfig) {}
	~Analysis();

 private:
	
	void beginJob();
	void beginRun(edm::Run const&, edm::EventSetup const&) {}
	void initializeStreamData(AnalysisStreamData*, edm::EventSetup const& es) const;
	std::shared_ptr<AnalysisStreamData> globalBeginRunSummary(edm::Run const&, edm::EventSetup const&) const;
	std::unique_ptr<AnalysisStreamData> beginStream(edm::StreamID) const;
	void streamBeginRun(edm::StreamID, edm::Run const&, edm::EventSetup const&) const;
	void analyze(edm::StreamID, const edm::Event&, const edm::EventSetup&) const;
	void streamEndRunSummary(edm::StreamID, edm::Run const&, edm::EventSetup const&, AnalysisStreamData*) const;
	void globalEndRunSummary(edm::Run const&, edm::EventSetup const&, AnalysisStreamData*) const;

	void endJob(){}
	void endRun(edm::Run const&, edm::EventSetup const&){}
	
};

#endif
