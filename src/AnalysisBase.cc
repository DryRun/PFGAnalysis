#define AnalysisBase_cxx
// The class definition in AnalysisBase.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the AnalysisBase starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the AnalysisBase, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the AnalysisBase,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("AnalysisBase.C")
// root> T->Process("AnalysisBase.C","some options")
// root> T->Process("AnalysisBase.C+")
//


#include "HCALPFG/PFGAnalysis/interface/AnalysisBase.h"
#include <TH2.h>
#include <TStyle.h>

void AnalysisBase::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The AnalysisBase argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void AnalysisBase::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The AnalysisBase argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t AnalysisBase::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the AnalysisBase (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded AnalysisBase is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);

   return kTRUE;
}

void AnalysisBase::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void AnalysisBase::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}