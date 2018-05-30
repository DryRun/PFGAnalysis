#include "HCALPFG/PFGAnalysis/interface/IDTypes.h"
#include "HCALPFG/PFGAnalysis/interface/Cell.h"
#include "HCALPFG/PFGAnalysis/interface/HOSample.h"
#include "HCALPFG/PFGAnalysis/interface/HODigi.h"
#include "HCALPFG/PFGAnalysis/interface/HFSample.h"
#include "HCALPFG/PFGAnalysis/interface/HFDigi.h"
#include "HCALPFG/PFGAnalysis/interface/HcalTupleTree.h"
#include "HCALPFG/PFGAnalysis/interface/HcalSample.h"
#include "HCALPFG/PFGAnalysis/interface/HcalDigi.h"
#include "HCALPFG/PFGAnalysis/interface/HBHEDigi.h"
#include "HCALPFG/PFGAnalysis/interface/HBHESample.h"
#include "HCALPFG/PFGAnalysis/interface/HEDigi.h"
#include "HCALPFG/PFGAnalysis/interface/HESample.h"
#include "HCALPFG/PFGAnalysis/interface/PFGEnums.h"
#include "HCALPFG/PFGAnalysis/interface/Collection.h"
#include "HCALPFG/PFGAnalysis/interface/Object.h"
#include "HCALPFG/PFGAnalysis/interface/HcalData.h"
#include "HCALPFG/PFGAnalysis/interface/RBXMap.h"

#ifdef __CINT__
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HODigi.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HFSample.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HFDigi.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HcalTupleTree.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HcalSample.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HcalDigi.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HBHEDigi.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HBHESample.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HEDigi.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HESample.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/PFGEnums.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/Collection.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/Object.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/HcalData.h";
#pragma extra_include "HCALPFG/PFGAnalysis/interface/RBXMap.h";
#endif

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;

#endif

#ifdef __CINT__
#pragma link C++ class IDTypes+;
#pragma link C++ class Cell+;
#pragma link C++ class HOSample+;
#pragma link C++ class HODigi+;
#pragma link C++ class HFSample+;
#pragma link C++ class HFDigi+;
#pragma link C++ class HcalTupleTree+;
#pragma link C++ class HcalSample+;
#pragma link C++ class HcalDigi+;
#pragma link C++ class HBHEDigi+;
#pragma link C++ class HBHESample+;
#pragma link C++ class HEDigi+;
#pragma link C++ class HESample+;
#pragma link C++ namespace pfg+;
#pragma link C++ class Collection+;
#pragma link C++ class Object+;
#pragma link C++ class HcalData+;
#pragma link C++ class RBXMap+;

#pragma link C++ function Collection::GetConstituent<HBHEDigi>+;
#pragma link C++ function Collection::GetConstituent<HEDigi>+;
#pragma link C++ function Collection::GetConstituent<HFDigi>+;
#pragma link C++ function Collection::GetConstituent<HODigi>+;
#pragma link C++ function HcalData::Digis<HBHEDigi>+;
#pragma link C++ function HcalData::Digis<HEDigi>+;
#pragma link C++ function HcalData::Digis<HFDigi>+;
#pragma link C++ function HcalData::Digis<HODigi>+;
#pragma link C++ function HcalData::Digi<HBHEDigi>+;
#pragma link C++ function HcalData::Digi<HEDigi>+;
#pragma link C++ function HcalData::Digi<HFDigi>+;
#pragma link C++ function HcalData::Digi<HODigi>+;

#endif
