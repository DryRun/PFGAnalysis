//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 22 14:11:47 2016 by ROOT version 5.34/32
// from TTree tree/
// found on file: test_uTCA.root // Root output of analysis_uHBHECommissioning_cfg.py
//////////////////////////////////////////////////////////

#ifndef HcalTupleTree_h
#define HcalTupleTree_h
using namespace std;

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class HcalTupleTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<float>   *HBHEDigiEta;
   vector<float>   *HBHEDigiPhi;
   vector<float>   *HBHEDigiRecEnergy;
   vector<float>   *HBHEDigiRecTime;
   vector<float>   *HODigiEta;
   vector<float>   *HODigiPhi;
   vector<float>   *HODigiRecEnergy;
   vector<float>   *HODigiRecTime;
   vector<vector<float> > *HBHEDigiAllFC;
   vector<vector<float> > *HBHEDigiEnergy;
   vector<vector<float> > *HBHEDigiFC;
   vector<vector<float> > *HBHEDigiGain;
   vector<vector<float> > *HBHEDigiNomFC;
   vector<vector<float> > *HBHEDigiPedFC;
   vector<vector<float> > *HBHEDigiRCGain;
   vector<vector<float> > *HODigiAllFC;
   vector<vector<float> > *HODigiEnergy;
   vector<vector<float> > *HODigiFC;
   vector<vector<float> > *HODigiGain;
   vector<vector<float> > *HODigiNomFC;
   vector<vector<float> > *HODigiPedFC;
   vector<vector<float> > *HODigiRCGain;
   vector<int>     *HBHEDigiDepth;
   vector<int>     *HBHEDigiElectronicsID;
   vector<int>     *HBHEDigiFiberIdleOffset;
   vector<int>     *HBHEDigiIEta;
   vector<int>     *HBHEDigiIPhi;
   int     HBHEDigiPresamples;
   vector<int>     *HBHEDigiRawID;
   int     HBHEDigiSize;
   vector<int>     *HBHEDigiSubdet;
   vector<int>     *HODigiDepth;
   vector<int>     *HODigiElectronicsID;
   vector<int>     *HODigiFiberIdleOffset;
   vector<int>     *HODigiIEta;
   vector<int>     *HODigiIPhi;
   int     HODigiPresamples;
   vector<int>     *HODigiRawID;
   int     HODigiSize;
   vector<int>     *HODigiSubdet;
   vector<int>     *HcalTriggerPrimitiveCompressedEtSOI;
   vector<int>     *HcalTriggerPrimitiveFineGrainSOI;
   vector<int>     *HcalTriggerPrimitiveIEta;
   vector<int>     *HcalTriggerPrimitiveIPhi;
   vector<int>     *HcalTriggerPrimitivePresamples;
   vector<int>     *HcalTriggerPrimitiveSize;
   vector<int>     *HcalUnpackerBadDigiDepth;
   vector<int>     *HcalUnpackerBadDigiIEta;
   vector<int>     *HcalUnpackerBadDigiIPhi;
   vector<int>     *HcalUnpackerBadDigiSubdet;
   vector<vector<int> > *HBHEDigiADC;
   vector<vector<int> > *HBHEDigiCapID;
   vector<vector<int> > *HBHEDigiDV;
   vector<vector<int> > *HBHEDigiER;
   vector<vector<int> > *HBHEDigiFiber;
   vector<vector<int> > *HBHEDigiFiberChan;
   vector<vector<int> > *HBHEDigiLADC;
   vector<vector<int> > *HBHEDigiRaw;
   vector<vector<int> > *HODigiADC;
   vector<vector<int> > *HODigiCapID;
   vector<vector<int> > *HODigiDV;
   vector<vector<int> > *HODigiER;
   vector<vector<int> > *HODigiFiber;
   vector<vector<int> > *HODigiFiberChan;
   vector<vector<int> > *HODigiLADC;
   vector<vector<int> > *HODigiRaw;
   vector<vector<int> > *HcalTriggerPrimitiveCompressedEt;
   vector<vector<int> > *HcalTriggerPrimitiveFineGrain;
   vector<vector<int> > *HcalTriggerPrimitiveHBHEDigiIndex;
   vector<vector<int> > *HcalTriggerPrimitiveHFDigiIndex;
   vector<double>  *QIE10DigiTimeFC;
   vector<double>  *QIE10DigiTimeTDC;
   vector<double>  *QIE11DigiTimeFC;
   vector<double>  *QIE11DigiTimeTDC;
   vector<vector<double> > *QIE10DigiFC;
   vector<vector<double> > *QIE10DigiPedFC;
   vector<vector<double> > *QIE11DigiFC;
   vector<vector<double> > *QIE11DigiPedFC;
   int     QIE10DigiPresamples;
   int     QIE10DigiSize;
   int     QIE11DigiPresamples;
   int     QIE11DigiSize;
   vector<float>   *QIE10DigiEta;
   vector<float>   *QIE10DigiPhi;
   vector<float>   *QIE11DigiEta;
   vector<float>   *QIE11DigiPhi;
   vector<int>     *QIE10DigiDepth;
   vector<int>     *QIE10DigiFlags;
   vector<int>     *QIE10DigiIEta;
   vector<int>     *QIE10DigiIPhi;
   vector<int>     *QIE10DigiLinkError;
   vector<int>     *QIE10DigiRawID;
   vector<int>     *QIE10DigiSubdet;
   //vector<int>     *QIE10DigiCapIDError;
   vector<int>     *QIE11DigiCapIDError;
   vector<int>     *QIE11DigiDepth;
   vector<int>     *QIE11DigiFlags;
   vector<int>     *QIE11DigiIEta;
   vector<int>     *QIE11DigiIPhi;
   vector<int>     *QIE11DigiLinkError;
   vector<int>     *QIE10DigiNTDC;
   vector<int>     *QIE11DigiNTDC;
   vector<int>     *QIE11DigiRawID;
   vector<int>     *QIE11DigiSubdet;
   vector<vector<int> > *QIE10DigiADC;
   vector<vector<int> > *QIE10DigiCapID;
   vector<vector<int> > *QIE10DigiOK;
   vector<vector<int> > *QIE10DigiSOI;
   vector<vector<int> > *QIE10DigiTDC;
   vector<vector<int> > *QIE11DigiADC;
   vector<vector<int> > *QIE11DigiCapID;
   vector<vector<int> > *QIE11DigiSOI;
   vector<vector<int> > *QIE11DigiTDC;
   vector<float>   *HFPhase1RecHitCharge;
   vector<float>   *HFPhase1RecHitEnergy;
   vector<float>   *HFPhase1RecHitEta;
   vector<float>   *HFPhase1RecHitPhi;
   vector<vector<float> > *HFPhase1RecHitQie10Charge;
   vector<vector<float> > *HFPhase1RecHitQie10Energy;
   vector<vector<float> > *HFPhase1RecHitQie10Time;
   vector<int>     *HFPhase1RecHitDepth;
   vector<int>     *HFPhase1RecHitIEta;
   vector<int>     *HFPhase1RecHitIPhi;
   vector<vector<int> > *HFPhase1RecHitQie10Soi;
   
   UInt_t          bx;
   UInt_t          event;
   UInt_t          ls;
   UInt_t          run;
   UInt_t          HcalUnpackerAnyValid;
   UInt_t          HcalUnpackerBSYSpigots;
   UInt_t          HcalUnpackerBadQualityDigis;
   UInt_t          HcalUnpackerEmptySpigots;
   UInt_t          HcalUnpackerErrorFree;
   UInt_t          HcalUnpackerHasCalib;
   UInt_t          HcalUnpackerNZS;
   UInt_t          HcalUnpackerOFWSpigots;
   UInt_t          HcalUnpackerSpigotFormatErrors;
   UInt_t          HcalUnpackerTotalDigis;
   UInt_t          HcalUnpackerTotalHOTPDigis;
   UInt_t          HcalUnpackerTotalTPDigis;

   // List of branches
   TBranch        *b_HBHEDigiEta;   //!
   TBranch        *b_HBHEDigiPhi;   //!
   TBranch        *b_HBHEDigiRecEnergy;   //!
   TBranch        *b_HBHEDigiRecTime;   //!
   TBranch        *b_HFDigiEta;   //!
   TBranch        *b_HFDigiPhi;   //!
   TBranch        *b_HFDigiRecEnergy;   //!
   TBranch        *b_HFDigiRecTime;   //!
   TBranch        *b_HODigiEta;   //!
   TBranch        *b_HODigiPhi;   //!
   TBranch        *b_HODigiRecEnergy;   //!
   TBranch        *b_HODigiRecTime;   //!
   TBranch        *b_HBHEDigiAllFC;   //!
   TBranch        *b_HBHEDigiEnergy;   //!
   TBranch        *b_HBHEDigiFC;   //!
   TBranch        *b_HBHEDigiGain;   //!
   TBranch        *b_HBHEDigiNomFC;   //!
   TBranch        *b_HBHEDigiPedFC;   //!
   TBranch        *b_HBHEDigiRCGain;   //!
   TBranch        *b_HFDigiAllFC;   //!
   TBranch        *b_HFDigiEnergy;   //!
   TBranch        *b_HFDigiFC;   //!
   TBranch        *b_HFDigiGain;   //!
   TBranch        *b_HFDigiNomFC;   //!
   TBranch        *b_HFDigiPedFC;   //!
   TBranch        *b_HFDigiRCGain;   //!
   TBranch        *b_HODigiAllFC;   //!
   TBranch        *b_HODigiEnergy;   //!
   TBranch        *b_HODigiFC;   //!
   TBranch        *b_HODigiGain;   //!
   TBranch        *b_HODigiNomFC;   //!
   TBranch        *b_HODigiPedFC;   //!
   TBranch        *b_HODigiRCGain;   //!
   TBranch        *b_HBHEDigiDepth;   //!
   TBranch        *b_HBHEDigiElectronicsID;   //!
   TBranch        *b_HBHEDigiFiberIdleOffset;   //!
   TBranch        *b_HBHEDigiIEta;   //!
   TBranch        *b_HBHEDigiIPhi;   //!
   TBranch        *b_HBHEDigiPresamples;   //!
   TBranch        *b_HBHEDigiRawID;   //!
   TBranch        *b_HBHEDigiSize;   //!
   TBranch        *b_HBHEDigiSubdet;   //!
   TBranch        *b_HODigiDepth;   //!
   TBranch        *b_HODigiElectronicsID;   //!
   TBranch        *b_HODigiFiberIdleOffset;   //!
   TBranch        *b_HODigiIEta;   //!
   TBranch        *b_HODigiIPhi;   //!
   TBranch        *b_HODigiPresamples;   //!
   TBranch        *b_HODigiRawID;   //!
   TBranch        *b_HODigiSize;   //!
   TBranch        *b_HODigiSubdet;   //!
   TBranch        *b_HcalTriggerPrimitiveCompressedEtSOI;   //!
   TBranch        *b_HcalTriggerPrimitiveFineGrainSOI;   //!
   TBranch        *b_HcalTriggerPrimitiveIEta;   //!
   TBranch        *b_HcalTriggerPrimitiveIPhi;   //!
   TBranch        *b_HcalTriggerPrimitivePresamples;   //!
   TBranch        *b_HcalTriggerPrimitiveSize;   //!
   TBranch        *b_HcalUnpackerBadDigiDepth;   //!
   TBranch        *b_HcalUnpackerBadDigiIEta;   //!
   TBranch        *b_HcalUnpackerBadDigiIPhi;   //!
   TBranch        *b_HcalUnpackerBadDigiSubdet;   //!
   TBranch        *b_HBHEDigiADC;   //!
   TBranch        *b_HBHEDigiCapID;   //!
   TBranch        *b_HBHEDigiDV;   //!
   TBranch        *b_HBHEDigiER;   //!
   TBranch        *b_HBHEDigiFiber;   //!
   TBranch        *b_HBHEDigiFiberChan;   //!
   TBranch        *b_HBHEDigiLADC;   //!
   TBranch        *b_HBHEDigiRaw;   //!
   TBranch        *b_HODigiADC;   //!
   TBranch        *b_HODigiCapID;   //!
   TBranch        *b_HODigiDV;   //!
   TBranch        *b_HODigiER;   //!
   TBranch        *b_HODigiFiber;   //!
   TBranch        *b_HODigiFiberChan;   //!
   TBranch        *b_HODigiLADC;   //!
   TBranch        *b_HODigiRaw;   //!
   TBranch        *b_HcalTriggerPrimitiveCompressedEt;   //!
   TBranch        *b_HcalTriggerPrimitiveFineGrain;   //!
   TBranch        *b_HcalTriggerPrimitiveHBHEDigiIndex;   //!
   TBranch        *b_HcalTriggerPrimitiveHFDigiIndex;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_event;   //!
   TBranch        *b_ls;   //!
   TBranch        *b_run;   //!
   TBranch        *b_HcalUnpackerAnyValid;   //!
   TBranch        *b_HcalUnpackerBSYSpigots;   //!
   TBranch        *b_HcalUnpackerBadQualityDigis;   //!
   TBranch        *b_HcalUnpackerEmptySpigots;   //!
   TBranch        *b_HcalUnpackerErrorFree;   //!
   TBranch        *b_HcalUnpackerHasCalib;   //!
   TBranch        *b_HcalUnpackerNZS;   //!
   TBranch        *b_HcalUnpackerOFWSpigots;   //!
   TBranch        *b_HcalUnpackerSpigotFormatErrors;   //!
   TBranch        *b_HcalUnpackerTotalDigis;   //!
   TBranch        *b_HcalUnpackerTotalHOTPDigis;   //!
   TBranch        *b_HcalUnpackerTotalTPDigis;   //!
   TBranch *b_QIE10DigiSize; //!
   TBranch *b_QIE10DigiPresamples; //!
   TBranch *b_QIE11DigiSize; //!
   TBranch *b_QIE11DigiPresamples; //!
   TBranch        *b_QIE10DigiTimeFC;   //!
   TBranch        *b_QIE10DigiTimeTDC;   //!
   TBranch        *b_QIE11DigiTimeFC;   //!
   TBranch        *b_QIE11DigiTimeTDC;   //!
   TBranch        *b_QIE10DigiFC;   //!
   TBranch        *b_QIE10DigiPedFC;   //!
   TBranch        *b_QIE11DigiFC;   //!
   TBranch        *b_QIE11DigiPedFC;   //!
   TBranch        *b_QIE10DigiEta;   //!
   TBranch        *b_QIE10DigiPhi;   //!
   TBranch        *b_QIE11DigiEta;   //!
   TBranch        *b_QIE11DigiPhi;   //!
   TBranch        *b_QIE10DigiDepth;   //!
   TBranch        *b_QIE10DigiFlags;   //!
   TBranch        *b_QIE10DigiIEta;   //!
   TBranch        *b_QIE10DigiIPhi;   //!
   TBranch        *b_QIE10DigiLinkError;   //!
   TBranch        *b_QIE10DigiRawID;   //!
   TBranch        *b_QIE10DigiSubdet;   //!
   //TBranch        *b_QIE10DigiCapIDError;   //!
   TBranch        *b_QIE11DigiCapIDError;   //!
   TBranch        *b_QIE11DigiDepth;   //!
   TBranch        *b_QIE11DigiFlags;   //!
   TBranch        *b_QIE11DigiIEta;   //!
   TBranch        *b_QIE11DigiIPhi;   //!
   TBranch        *b_QIE11DigiLinkError;   //!
   TBranch        *b_QIE10DigiNTDC;   //!
   TBranch        *b_QIE11DigiNTDC;   //!
   TBranch        *b_QIE11DigiRawID;   //!
   TBranch        *b_QIE11DigiSubdet;   //!
   TBranch        *b_QIE10DigiADC;   //!
   TBranch        *b_QIE10DigiCapID;   //!
   TBranch        *b_QIE10DigiOK;   //!
   TBranch        *b_QIE10DigiSOI;   //!
   TBranch        *b_QIE10DigiTDC;   //!
   TBranch        *b_QIE11DigiADC;   //!
   TBranch        *b_QIE11DigiCapID;   //!
   TBranch        *b_QIE11DigiSOI;   //!
   TBranch        *b_QIE11DigiTDC;   //!
   TBranch        *b_HFPhase1RecHitCharge;   //!
   TBranch        *b_HFPhase1RecHitEnergy;   //!
   TBranch        *b_HFPhase1RecHitEta;   //!
   TBranch        *b_HFPhase1RecHitPhi;   //!
   TBranch        *b_HFPhase1RecHitQie10Charge;   //!
   TBranch        *b_HFPhase1RecHitQie10Energy;   //!
   TBranch        *b_HFPhase1RecHitQie10Time;   //!
   TBranch        *b_HFPhase1RecHitDepth;   //!
   TBranch        *b_HFPhase1RecHitIEta;   //!
   TBranch        *b_HFPhase1RecHitIPhi;   //!
   TBranch        *b_HFPhase1RecHitQie10Soi;   //!

   HcalTupleTree(TTree *tree=0);
   virtual ~HcalTupleTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HcalTupleTree_cxx
HcalTupleTree::HcalTupleTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test_uTCA.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test_uTCA.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("test_uTCA.root:/HcalTupleTree");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

HcalTupleTree::~HcalTupleTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HcalTupleTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HcalTupleTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HcalTupleTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   HBHEDigiEta = 0;
   HBHEDigiPhi = 0;
   HBHEDigiRecEnergy = 0;
   HBHEDigiRecTime = 0;
   HODigiEta = 0;
   HODigiPhi = 0;
   HODigiRecEnergy = 0;
   HODigiRecTime = 0;
   HBHEDigiAllFC = 0;
   HBHEDigiEnergy = 0;
   HBHEDigiFC = 0;
   HBHEDigiGain = 0;
   HBHEDigiNomFC = 0;
   HBHEDigiPedFC = 0;
   HBHEDigiRCGain = 0;
   HODigiAllFC = 0;
   HODigiEnergy = 0;
   HODigiFC = 0;
   HODigiGain = 0;
   HODigiNomFC = 0;
   HODigiPedFC = 0;
   HODigiRCGain = 0;
   HBHEDigiDepth = 0;
   HBHEDigiElectronicsID = 0;
   HBHEDigiFiberIdleOffset = 0;
   HBHEDigiIEta = 0;
   HBHEDigiIPhi = 0;
   HBHEDigiPresamples = 0;
   HBHEDigiRawID = 0;
   HBHEDigiSize = 0;
   HBHEDigiSubdet = 0;
   HODigiDepth = 0;
   HODigiElectronicsID = 0;
   HODigiFiberIdleOffset = 0;
   HODigiIEta = 0;
   HODigiIPhi = 0;
   HODigiPresamples = 0;
   HODigiRawID = 0;
   HODigiSize = 0;
   HODigiSubdet = 0;
   HcalTriggerPrimitiveCompressedEtSOI = 0;
   HcalTriggerPrimitiveFineGrainSOI = 0;
   HcalTriggerPrimitiveIEta = 0;
   HcalTriggerPrimitiveIPhi = 0;
   HcalTriggerPrimitivePresamples = 0;
   HcalTriggerPrimitiveSize = 0;
   HcalUnpackerBadDigiDepth = 0;
   HcalUnpackerBadDigiIEta = 0;
   HcalUnpackerBadDigiIPhi = 0;
   HcalUnpackerBadDigiSubdet = 0;
   HBHEDigiADC = 0;
   HBHEDigiCapID = 0;
   HBHEDigiDV = 0;
   HBHEDigiER = 0;
   HBHEDigiFiber = 0;
   HBHEDigiFiberChan = 0;
   HBHEDigiLADC = 0;
   HBHEDigiRaw = 0;
   HODigiADC = 0;
   HODigiCapID = 0;
   HODigiDV = 0;
   HODigiER = 0;
   HODigiFiber = 0;
   HODigiFiberChan = 0;
   HODigiLADC = 0;
   HODigiRaw = 0;
   HcalTriggerPrimitiveCompressedEt = 0;
   HcalTriggerPrimitiveFineGrain = 0;
   HcalTriggerPrimitiveHBHEDigiIndex = 0;
   HcalTriggerPrimitiveHFDigiIndex = 0;
   QIE10DigiSize = 0;
   QIE10DigiPresamples = 0;
   QIE11DigiSize = 0;
   QIE11DigiPresamples = 0;
   QIE10DigiTimeFC = 0;
   QIE10DigiTimeTDC = 0;
   QIE11DigiTimeFC = 0;
   QIE11DigiTimeTDC = 0;
   QIE10DigiFC = 0;
   QIE10DigiPedFC = 0;
   QIE11DigiFC = 0;
   QIE11DigiPedFC = 0;
   QIE10DigiEta = 0;
   QIE10DigiPhi = 0;
   QIE11DigiEta = 0;
   QIE11DigiPhi = 0;
   QIE10DigiDepth = 0;
   QIE10DigiFlags = 0;
   QIE10DigiIEta = 0;
   QIE10DigiIPhi = 0;
   QIE10DigiLinkError = 0;
   QIE10DigiRawID = 0;
   QIE10DigiSubdet = 0;
   //QIE10DigiCapIDError = 0;
   QIE11DigiCapIDError = 0;
   QIE11DigiDepth = 0;
   QIE11DigiFlags = 0;
   QIE11DigiIEta = 0;
   QIE11DigiIPhi = 0;
   QIE11DigiLinkError = 0;
   QIE10DigiNTDC = 0;
   QIE11DigiNTDC = 0;
   QIE11DigiRawID = 0;
   QIE11DigiSubdet = 0;
   QIE10DigiADC = 0;
   QIE10DigiCapID = 0;
   QIE10DigiOK = 0;
   QIE10DigiSOI = 0;
   QIE10DigiTDC = 0;
   QIE11DigiADC = 0;
   QIE11DigiCapID = 0;
   QIE11DigiSOI = 0;
   QIE11DigiTDC = 0;
   HFPhase1RecHitCharge = 0;
   HFPhase1RecHitEnergy = 0;
   HFPhase1RecHitEta = 0;
   HFPhase1RecHitPhi = 0;
   HFPhase1RecHitQie10Charge = 0;
   HFPhase1RecHitQie10Energy = 0;
   HFPhase1RecHitQie10Time = 0;
   HFPhase1RecHitDepth = 0;
   HFPhase1RecHitIEta = 0;
   HFPhase1RecHitIPhi = 0;
   HFPhase1RecHitQie10Soi = 0;
   
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("HBHEDigiEta", &HBHEDigiEta, &b_HBHEDigiEta);
   fChain->SetBranchAddress("HBHEDigiPhi", &HBHEDigiPhi, &b_HBHEDigiPhi);
   fChain->SetBranchAddress("HBHEDigiRecEnergy", &HBHEDigiRecEnergy, &b_HBHEDigiRecEnergy);
   fChain->SetBranchAddress("HBHEDigiRecTime", &HBHEDigiRecTime, &b_HBHEDigiRecTime);
   fChain->SetBranchAddress("HODigiEta", &HODigiEta, &b_HODigiEta);
   fChain->SetBranchAddress("HODigiPhi", &HODigiPhi, &b_HODigiPhi);
   fChain->SetBranchAddress("HODigiRecEnergy", &HODigiRecEnergy, &b_HODigiRecEnergy);
   fChain->SetBranchAddress("HODigiRecTime", &HODigiRecTime, &b_HODigiRecTime);
   fChain->SetBranchAddress("HBHEDigiAllFC", &HBHEDigiAllFC, &b_HBHEDigiAllFC);
   fChain->SetBranchAddress("HBHEDigiEnergy", &HBHEDigiEnergy, &b_HBHEDigiEnergy);
   fChain->SetBranchAddress("HBHEDigiFC", &HBHEDigiFC, &b_HBHEDigiFC);
   fChain->SetBranchAddress("HBHEDigiGain", &HBHEDigiGain, &b_HBHEDigiGain);
   fChain->SetBranchAddress("HBHEDigiNomFC", &HBHEDigiNomFC, &b_HBHEDigiNomFC);
   fChain->SetBranchAddress("HBHEDigiPedFC", &HBHEDigiPedFC, &b_HBHEDigiPedFC);
   fChain->SetBranchAddress("HBHEDigiRCGain", &HBHEDigiRCGain, &b_HBHEDigiRCGain);
   fChain->SetBranchAddress("HODigiAllFC", &HODigiAllFC, &b_HODigiAllFC);
   fChain->SetBranchAddress("HODigiEnergy", &HODigiEnergy, &b_HODigiEnergy);
   fChain->SetBranchAddress("HODigiFC", &HODigiFC, &b_HODigiFC);
   fChain->SetBranchAddress("HODigiGain", &HODigiGain, &b_HODigiGain);
   fChain->SetBranchAddress("HODigiNomFC", &HODigiNomFC, &b_HODigiNomFC);
   fChain->SetBranchAddress("HODigiPedFC", &HODigiPedFC, &b_HODigiPedFC);
   fChain->SetBranchAddress("HODigiRCGain", &HODigiRCGain, &b_HODigiRCGain);
   fChain->SetBranchAddress("HBHEDigiDepth", &HBHEDigiDepth, &b_HBHEDigiDepth);
   fChain->SetBranchAddress("HBHEDigiElectronicsID", &HBHEDigiElectronicsID, &b_HBHEDigiElectronicsID);
   fChain->SetBranchAddress("HBHEDigiFiberIdleOffset", &HBHEDigiFiberIdleOffset, &b_HBHEDigiFiberIdleOffset);
   fChain->SetBranchAddress("HBHEDigiIEta", &HBHEDigiIEta, &b_HBHEDigiIEta);
   fChain->SetBranchAddress("HBHEDigiIPhi", &HBHEDigiIPhi, &b_HBHEDigiIPhi);
   fChain->SetBranchAddress("HBHEDigiPresamples", &HBHEDigiPresamples, &b_HBHEDigiPresamples);
   fChain->SetBranchAddress("HBHEDigiRawID", &HBHEDigiRawID, &b_HBHEDigiRawID);
   fChain->SetBranchAddress("HBHEDigiSize", &HBHEDigiSize, &b_HBHEDigiSize);
   fChain->SetBranchAddress("HBHEDigiSubdet", &HBHEDigiSubdet, &b_HBHEDigiSubdet);
   fChain->SetBranchAddress("HODigiDepth", &HODigiDepth, &b_HODigiDepth);
   fChain->SetBranchAddress("HODigiElectronicsID", &HODigiElectronicsID, &b_HODigiElectronicsID);
   fChain->SetBranchAddress("HODigiFiberIdleOffset", &HODigiFiberIdleOffset, &b_HODigiFiberIdleOffset);
   fChain->SetBranchAddress("HODigiIEta", &HODigiIEta, &b_HODigiIEta);
   fChain->SetBranchAddress("HODigiIPhi", &HODigiIPhi, &b_HODigiIPhi);
   fChain->SetBranchAddress("HODigiPresamples", &HODigiPresamples, &b_HODigiPresamples);
   fChain->SetBranchAddress("HODigiRawID", &HODigiRawID, &b_HODigiRawID);
   fChain->SetBranchAddress("HODigiSize", &HODigiSize, &b_HODigiSize);
   fChain->SetBranchAddress("HODigiSubdet", &HODigiSubdet, &b_HODigiSubdet);
   fChain->SetBranchAddress("HcalTriggerPrimitiveCompressedEtSOI", &HcalTriggerPrimitiveCompressedEtSOI, &b_HcalTriggerPrimitiveCompressedEtSOI);
   fChain->SetBranchAddress("HcalTriggerPrimitiveFineGrainSOI", &HcalTriggerPrimitiveFineGrainSOI, &b_HcalTriggerPrimitiveFineGrainSOI);
   fChain->SetBranchAddress("HcalTriggerPrimitiveIEta", &HcalTriggerPrimitiveIEta, &b_HcalTriggerPrimitiveIEta);
   fChain->SetBranchAddress("HcalTriggerPrimitiveIPhi", &HcalTriggerPrimitiveIPhi, &b_HcalTriggerPrimitiveIPhi);
   fChain->SetBranchAddress("HcalTriggerPrimitivePresamples", &HcalTriggerPrimitivePresamples, &b_HcalTriggerPrimitivePresamples);
   fChain->SetBranchAddress("HcalTriggerPrimitiveSize", &HcalTriggerPrimitiveSize, &b_HcalTriggerPrimitiveSize);
   fChain->SetBranchAddress("HcalUnpackerBadDigiDepth", &HcalUnpackerBadDigiDepth, &b_HcalUnpackerBadDigiDepth);
   fChain->SetBranchAddress("HcalUnpackerBadDigiIEta", &HcalUnpackerBadDigiIEta, &b_HcalUnpackerBadDigiIEta);
   fChain->SetBranchAddress("HcalUnpackerBadDigiIPhi", &HcalUnpackerBadDigiIPhi, &b_HcalUnpackerBadDigiIPhi);
   fChain->SetBranchAddress("HcalUnpackerBadDigiSubdet", &HcalUnpackerBadDigiSubdet, &b_HcalUnpackerBadDigiSubdet);
   fChain->SetBranchAddress("HBHEDigiADC", &HBHEDigiADC, &b_HBHEDigiADC);
   fChain->SetBranchAddress("HBHEDigiCapID", &HBHEDigiCapID, &b_HBHEDigiCapID);
   fChain->SetBranchAddress("HBHEDigiDV", &HBHEDigiDV, &b_HBHEDigiDV);
   fChain->SetBranchAddress("HBHEDigiER", &HBHEDigiER, &b_HBHEDigiER);
   fChain->SetBranchAddress("HBHEDigiFiber", &HBHEDigiFiber, &b_HBHEDigiFiber);
   fChain->SetBranchAddress("HBHEDigiFiberChan", &HBHEDigiFiberChan, &b_HBHEDigiFiberChan);
   fChain->SetBranchAddress("HBHEDigiLADC", &HBHEDigiLADC, &b_HBHEDigiLADC);
   fChain->SetBranchAddress("HBHEDigiRaw", &HBHEDigiRaw, &b_HBHEDigiRaw);
   fChain->SetBranchAddress("HODigiADC", &HODigiADC, &b_HODigiADC);
   fChain->SetBranchAddress("HODigiCapID", &HODigiCapID, &b_HODigiCapID);
   fChain->SetBranchAddress("HODigiDV", &HODigiDV, &b_HODigiDV);
   fChain->SetBranchAddress("HODigiER", &HODigiER, &b_HODigiER);
   fChain->SetBranchAddress("HODigiFiber", &HODigiFiber, &b_HODigiFiber);
   fChain->SetBranchAddress("HODigiFiberChan", &HODigiFiberChan, &b_HODigiFiberChan);
   fChain->SetBranchAddress("HODigiLADC", &HODigiLADC, &b_HODigiLADC);
   fChain->SetBranchAddress("HODigiRaw", &HODigiRaw, &b_HODigiRaw);
   fChain->SetBranchAddress("HcalTriggerPrimitiveCompressedEt", &HcalTriggerPrimitiveCompressedEt, &b_HcalTriggerPrimitiveCompressedEt);
   fChain->SetBranchAddress("HcalTriggerPrimitiveFineGrain", &HcalTriggerPrimitiveFineGrain, &b_HcalTriggerPrimitiveFineGrain);
   fChain->SetBranchAddress("HcalTriggerPrimitiveHBHEDigiIndex", &HcalTriggerPrimitiveHBHEDigiIndex, &b_HcalTriggerPrimitiveHBHEDigiIndex);
   fChain->SetBranchAddress("HcalTriggerPrimitiveHFDigiIndex", &HcalTriggerPrimitiveHFDigiIndex, &b_HcalTriggerPrimitiveHFDigiIndex);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("ls", &ls, &b_ls);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("HcalUnpackerAnyValid", &HcalUnpackerAnyValid, &b_HcalUnpackerAnyValid);
   fChain->SetBranchAddress("HcalUnpackerBSYSpigots", &HcalUnpackerBSYSpigots, &b_HcalUnpackerBSYSpigots);
   fChain->SetBranchAddress("HcalUnpackerBadQualityDigis", &HcalUnpackerBadQualityDigis, &b_HcalUnpackerBadQualityDigis);
   fChain->SetBranchAddress("HcalUnpackerEmptySpigots", &HcalUnpackerEmptySpigots, &b_HcalUnpackerEmptySpigots);
   fChain->SetBranchAddress("HcalUnpackerErrorFree", &HcalUnpackerErrorFree, &b_HcalUnpackerErrorFree);
   fChain->SetBranchAddress("HcalUnpackerHasCalib", &HcalUnpackerHasCalib, &b_HcalUnpackerHasCalib);
   fChain->SetBranchAddress("HcalUnpackerNZS", &HcalUnpackerNZS, &b_HcalUnpackerNZS);
   fChain->SetBranchAddress("HcalUnpackerOFWSpigots", &HcalUnpackerOFWSpigots, &b_HcalUnpackerOFWSpigots);
   fChain->SetBranchAddress("HcalUnpackerSpigotFormatErrors", &HcalUnpackerSpigotFormatErrors, &b_HcalUnpackerSpigotFormatErrors);
   fChain->SetBranchAddress("HcalUnpackerTotalDigis", &HcalUnpackerTotalDigis, &b_HcalUnpackerTotalDigis);
   fChain->SetBranchAddress("HcalUnpackerTotalHOTPDigis", &HcalUnpackerTotalHOTPDigis, &b_HcalUnpackerTotalHOTPDigis);
   fChain->SetBranchAddress("HcalUnpackerTotalTPDigis", &HcalUnpackerTotalTPDigis, &b_HcalUnpackerTotalTPDigis);
   fChain->SetBranchAddress("QIE10DigiSize", &QIE10DigiSize, &b_QIE10DigiSize);
   fChain->SetBranchAddress("QIE10DigiPresamples", &QIE10DigiPresamples, &b_QIE10DigiPresamples);
   fChain->SetBranchAddress("QIE11DigiSize", &QIE11DigiSize, &b_QIE11DigiSize);
   fChain->SetBranchAddress("QIE11DigiPresamples", &QIE11DigiPresamples, &b_QIE11DigiPresamples);
   fChain->SetBranchAddress("QIE10DigiTimeFC", &QIE11DigiTimeFC, &b_QIE11DigiTimeFC);
   fChain->SetBranchAddress("QIE10DigiTimeTDC", &QIE11DigiTimeTDC, &b_QIE11DigiTimeTDC);
   fChain->SetBranchAddress("QIE11DigiTimeFC", &QIE11DigiTimeFC, &b_QIE11DigiTimeFC);
   fChain->SetBranchAddress("QIE11DigiTimeTDC", &QIE11DigiTimeTDC, &b_QIE11DigiTimeTDC);
   fChain->SetBranchAddress("QIE10DigiFC", &QIE10DigiFC, &b_QIE10DigiFC);
   fChain->SetBranchAddress("QIE10DigiPedFC", &QIE10DigiPedFC, &b_QIE10DigiPedFC);
   fChain->SetBranchAddress("QIE11DigiFC", &QIE11DigiFC, &b_QIE11DigiFC);
   fChain->SetBranchAddress("QIE11DigiPedFC", &QIE11DigiPedFC, &b_QIE11DigiPedFC);
   fChain->SetBranchAddress("QIE10DigiEta", &QIE10DigiEta, &b_QIE10DigiEta);
   fChain->SetBranchAddress("QIE10DigiPhi", &QIE10DigiPhi, &b_QIE10DigiPhi);
   fChain->SetBranchAddress("QIE11DigiEta", &QIE11DigiEta, &b_QIE11DigiEta);
   fChain->SetBranchAddress("QIE11DigiPhi", &QIE11DigiPhi, &b_QIE11DigiPhi);
   fChain->SetBranchAddress("QIE10DigiDepth", &QIE10DigiDepth, &b_QIE10DigiDepth);
   fChain->SetBranchAddress("QIE10DigiFlags", &QIE10DigiFlags, &b_QIE10DigiFlags);
   fChain->SetBranchAddress("QIE10DigiIEta", &QIE10DigiIEta, &b_QIE10DigiIEta);
   fChain->SetBranchAddress("QIE10DigiIPhi", &QIE10DigiIPhi, &b_QIE10DigiIPhi);
   fChain->SetBranchAddress("QIE10DigiLinkError", &QIE10DigiLinkError, &b_QIE10DigiLinkError);
   fChain->SetBranchAddress("QIE10DigiRawID", &QIE10DigiRawID, &b_QIE10DigiRawID);
   fChain->SetBranchAddress("QIE10DigiSubdet", &QIE10DigiSubdet, &b_QIE10DigiSubdet);
   //fChain->SetBranchAddress("QIE10DigiCapIDError", &QIE10DigiCapIDError, &b_QIE10DigiCapIDError);
   fChain->SetBranchAddress("QIE11DigiCapIDError", &QIE11DigiCapIDError, &b_QIE11DigiCapIDError);
   fChain->SetBranchAddress("QIE11DigiDepth", &QIE11DigiDepth, &b_QIE11DigiDepth);
   fChain->SetBranchAddress("QIE11DigiFlags", &QIE11DigiFlags, &b_QIE11DigiFlags);
   fChain->SetBranchAddress("QIE11DigiIEta", &QIE11DigiIEta, &b_QIE11DigiIEta);
   fChain->SetBranchAddress("QIE11DigiIPhi", &QIE11DigiIPhi, &b_QIE11DigiIPhi);
   fChain->SetBranchAddress("QIE11DigiLinkError", &QIE11DigiLinkError, &b_QIE11DigiLinkError);
   fChain->SetBranchAddress("QIE10DigiNTDC", &QIE10DigiNTDC, &b_QIE10DigiNTDC);
   fChain->SetBranchAddress("QIE11DigiNTDC", &QIE11DigiNTDC, &b_QIE11DigiNTDC);
   fChain->SetBranchAddress("QIE11DigiRawID", &QIE11DigiRawID, &b_QIE11DigiRawID);
   fChain->SetBranchAddress("QIE11DigiSubdet", &QIE11DigiSubdet, &b_QIE11DigiSubdet);
   fChain->SetBranchAddress("QIE10DigiADC", &QIE10DigiADC, &b_QIE10DigiADC);
   fChain->SetBranchAddress("QIE10DigiCapID", &QIE10DigiCapID, &b_QIE10DigiCapID);
   fChain->SetBranchAddress("QIE10DigiOK", &QIE10DigiOK, &b_QIE10DigiOK);
   fChain->SetBranchAddress("QIE10DigiSOI", &QIE10DigiSOI, &b_QIE10DigiSOI);
   fChain->SetBranchAddress("QIE10DigiTDC", &QIE10DigiTDC, &b_QIE10DigiTDC);
   fChain->SetBranchAddress("QIE11DigiADC", &QIE11DigiADC, &b_QIE11DigiADC);
   fChain->SetBranchAddress("QIE11DigiCapID", &QIE11DigiCapID, &b_QIE11DigiCapID);
   fChain->SetBranchAddress("QIE11DigiSOI", &QIE11DigiSOI, &b_QIE11DigiSOI);
   fChain->SetBranchAddress("QIE11DigiTDC", &QIE11DigiTDC, &b_QIE11DigiTDC);

   fChain->SetBranchAddress("HFPhase1RecHitCharge", &HFPhase1RecHitCharge, &b_HFPhase1RecHitCharge);
   fChain->SetBranchAddress("HFPhase1RecHitEnergy", &HFPhase1RecHitEnergy, &b_HFPhase1RecHitEnergy);
   fChain->SetBranchAddress("HFPhase1RecHitEta", &HFPhase1RecHitEta, &b_HFPhase1RecHitEta);
   fChain->SetBranchAddress("HFPhase1RecHitPhi", &HFPhase1RecHitPhi, &b_HFPhase1RecHitPhi);
   fChain->SetBranchAddress("HFPhase1RecHitQie10Charge", &HFPhase1RecHitQie10Charge, &b_HFPhase1RecHitQie10Charge);
   fChain->SetBranchAddress("HFPhase1RecHitQie10Energy", &HFPhase1RecHitQie10Energy, &b_HFPhase1RecHitQie10Energy);
   fChain->SetBranchAddress("HFPhase1RecHitQie10Time", &HFPhase1RecHitQie10Time, &b_HFPhase1RecHitQie10Time);
   fChain->SetBranchAddress("HFPhase1RecHitDepth", &HFPhase1RecHitDepth, &b_HFPhase1RecHitDepth);
   fChain->SetBranchAddress("HFPhase1RecHitIEta", &HFPhase1RecHitIEta, &b_HFPhase1RecHitIEta);
   fChain->SetBranchAddress("HFPhase1RecHitIPhi", &HFPhase1RecHitIPhi, &b_HFPhase1RecHitIPhi);
   fChain->SetBranchAddress("HFPhase1RecHitQie10Soi", &HFPhase1RecHitQie10Soi, &b_HFPhase1RecHitQie10Soi);   Notify();
}

Bool_t HcalTupleTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HcalTupleTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HcalTupleTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HcalTupleTree_cxx

