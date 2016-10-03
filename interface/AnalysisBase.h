//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Sep 30 08:35:07 2016 by ROOT version 6.06/01
// from TTree AnalysisBase/
// found on file: hcalTupleTree.root
//////////////////////////////////////////////////////////

#ifndef AnalysisBase_h
#define AnalysisBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class AnalysisBase : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderArray<float> HBHEDigiEta = {fReader, "HBHEDigiEta"};
   TTreeReaderArray<float> HBHEDigiPhi = {fReader, "HBHEDigiPhi"};
   TTreeReaderArray<float> HBHEDigiRecEnergy = {fReader, "HBHEDigiRecEnergy"};
   TTreeReaderArray<float> HBHEDigiRecTime = {fReader, "HBHEDigiRecTime"};
   TTreeReaderArray<float> HFDigiEta = {fReader, "HFDigiEta"};
   TTreeReaderArray<float> HFDigiPhi = {fReader, "HFDigiPhi"};
   TTreeReaderArray<float> HFDigiRecEnergy = {fReader, "HFDigiRecEnergy"};
   TTreeReaderArray<float> HFDigiRecTime = {fReader, "HFDigiRecTime"};
   TTreeReaderArray<vector<float>> HBHEDigiAllFC = {fReader, "HBHEDigiAllFC"};
   TTreeReaderArray<vector<float>> HBHEDigiEnergy = {fReader, "HBHEDigiEnergy"};
   TTreeReaderArray<vector<float>> HBHEDigiFC = {fReader, "HBHEDigiFC"};
   TTreeReaderArray<vector<float>> HBHEDigiGain = {fReader, "HBHEDigiGain"};
   TTreeReaderArray<vector<float>> HBHEDigiNomFC = {fReader, "HBHEDigiNomFC"};
   TTreeReaderArray<vector<float>> HBHEDigiPedFC = {fReader, "HBHEDigiPedFC"};
   TTreeReaderArray<vector<float>> HBHEDigiRCGain = {fReader, "HBHEDigiRCGain"};
   TTreeReaderArray<vector<float>> HFDigiAllFC = {fReader, "HFDigiAllFC"};
   TTreeReaderArray<vector<float>> HFDigiEnergy = {fReader, "HFDigiEnergy"};
   TTreeReaderArray<vector<float>> HFDigiFC = {fReader, "HFDigiFC"};
   TTreeReaderArray<vector<float>> HFDigiGain = {fReader, "HFDigiGain"};
   TTreeReaderArray<vector<float>> HFDigiNomFC = {fReader, "HFDigiNomFC"};
   TTreeReaderArray<vector<float>> HFDigiPedFC = {fReader, "HFDigiPedFC"};
   TTreeReaderArray<vector<float>> HFDigiRCGain = {fReader, "HFDigiRCGain"};
   TTreeReaderArray<int> FEDBCN = {fReader, "FEDBCN"};
   TTreeReaderArray<int> FEDNumber = {fReader, "FEDNumber"};
   TTreeReaderArray<int> FEDORN = {fReader, "FEDORN"};
   TTreeReaderArray<int> FEDSize = {fReader, "FEDSize"};
   TTreeReaderArray<int> HBHEDigiDepth = {fReader, "HBHEDigiDepth"};
   TTreeReaderArray<int> HBHEDigiElectronicsID = {fReader, "HBHEDigiElectronicsID"};
   TTreeReaderArray<int> HBHEDigiFiberIdleOffset = {fReader, "HBHEDigiFiberIdleOffset"};
   TTreeReaderArray<int> HBHEDigiIEta = {fReader, "HBHEDigiIEta"};
   TTreeReaderArray<int> HBHEDigiIPhi = {fReader, "HBHEDigiIPhi"};
   TTreeReaderArray<int> HBHEDigiPresamples = {fReader, "HBHEDigiPresamples"};
   TTreeReaderArray<int> HBHEDigiRawID = {fReader, "HBHEDigiRawID"};
   TTreeReaderArray<int> HBHEDigiSize = {fReader, "HBHEDigiSize"};
   TTreeReaderArray<int> HBHEDigiSubdet = {fReader, "HBHEDigiSubdet"};
   TTreeReaderArray<int> HFDigiDepth = {fReader, "HFDigiDepth"};
   TTreeReaderArray<int> HFDigiElectronicsID = {fReader, "HFDigiElectronicsID"};
   TTreeReaderArray<int> HFDigiFiberIdleOffset = {fReader, "HFDigiFiberIdleOffset"};
   TTreeReaderArray<int> HFDigiIEta = {fReader, "HFDigiIEta"};
   TTreeReaderArray<int> HFDigiIPhi = {fReader, "HFDigiIPhi"};
   TTreeReaderArray<int> HFDigiPresamples = {fReader, "HFDigiPresamples"};
   TTreeReaderArray<int> HFDigiRawID = {fReader, "HFDigiRawID"};
   TTreeReaderArray<int> HFDigiSize = {fReader, "HFDigiSize"};
   TTreeReaderArray<int> HFDigiSubdet = {fReader, "HFDigiSubdet"};
   TTreeReaderArray<vector<int>> HBHEDigiADC = {fReader, "HBHEDigiADC"};
   TTreeReaderArray<vector<int>> HBHEDigiCapID = {fReader, "HBHEDigiCapID"};
   TTreeReaderArray<vector<int>> HBHEDigiDV = {fReader, "HBHEDigiDV"};
   TTreeReaderArray<vector<int>> HBHEDigiER = {fReader, "HBHEDigiER"};
   TTreeReaderArray<vector<int>> HBHEDigiFiber = {fReader, "HBHEDigiFiber"};
   TTreeReaderArray<vector<int>> HBHEDigiFiberChan = {fReader, "HBHEDigiFiberChan"};
   TTreeReaderArray<vector<int>> HBHEDigiLADC = {fReader, "HBHEDigiLADC"};
   TTreeReaderArray<vector<int>> HBHEDigiRaw = {fReader, "HBHEDigiRaw"};
   TTreeReaderArray<vector<int>> HFDigiADC = {fReader, "HFDigiADC"};
   TTreeReaderArray<vector<int>> HFDigiCapID = {fReader, "HFDigiCapID"};
   TTreeReaderArray<vector<int>> HFDigiDV = {fReader, "HFDigiDV"};
   TTreeReaderArray<vector<int>> HFDigiER = {fReader, "HFDigiER"};
   TTreeReaderArray<vector<int>> HFDigiFiber = {fReader, "HFDigiFiber"};
   TTreeReaderArray<vector<int>> HFDigiFiberChan = {fReader, "HFDigiFiberChan"};
   TTreeReaderArray<vector<int>> HFDigiLADC = {fReader, "HFDigiLADC"};
   TTreeReaderArray<vector<int>> HFDigiRaw = {fReader, "HFDigiRaw"};
   TTreeReaderValue<UInt_t> bx = {fReader, "bx"};
   TTreeReaderValue<UInt_t> event = {fReader, "event"};
   TTreeReaderValue<UInt_t> ls = {fReader, "ls"};
   TTreeReaderValue<UInt_t> run = {fReader, "run"};


   AnalysisBase(TTree * /*tree*/ =0) { }
   virtual ~AnalysisBase() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(AnalysisBase,0);

};

#endif

#ifdef AnalysisBase_cxx
void AnalysisBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new AnalysisBase or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t AnalysisBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef AnalysisBase_cxx
