#include "MyTools/RootUtils/interface/IDTypes.h"
#include "MyTools/RootUtils/interface/Cell.h"
#include "MyTools/RootUtils/interface/HOSample.h"
#include "MyTools/RootUtils/interface/HODigi.h"
#include "MyTools/RootUtils/interface/HFSample.h"
#include "MyTools/RootUtils/interface/HFDigi.h"
#include "MyTools/RootUtils/interface/HcalTupleTree.h"
#include "MyTools/RootUtils/interface/HcalSample.h"
#include "MyTools/RootUtils/interface/HcalDigi.h"
#include "MyTools/RootUtils/interface/HBHEDigi.h"
#include "MyTools/RootUtils/interface/HBHESample.h"
#include "MyTools/RootUtils/interface/PFGEnums.h"
#include "MyTools/RootUtils/interface/Collection.h"
#include "MyTools/RootUtils/interface/Object.h"
#include "MyTools/RootUtils/interface/HcalData.h"
#include "MyTools/RootUtils/interface/HLTFilterObjectCollectionHelper.h"
#include "MyTools/RootUtils/interface/HLTFilterObject.h"
#include "MyTools/RootUtils/interface/HFUTCASample.h"
#include "MyTools/RootUtils/interface/HFUTCA.h"
#include "MyTools/RootUtils/interface/HBHEUTCASample.h"
#include "MyTools/RootUtils/interface/HBHEUTCA.h"
#include "MyTools/RootUtils/interface/RBXMap.h"

#ifdef __CINT__
#pragma extra_include "MyTools/RootUtils/interface/HODigi.h"
#pragma extra_include "MyTools/RootUtils/interface/HFSample.h"
#pragma extra_include "MyTools/RootUtils/interface/HFDigi.h"
#pragma extra_include "MyTools/RootUtils/interface/HcalTupleTree.h"
#pragma extra_include "MyTools/RootUtils/interface/HcalSample.h"
#pragma extra_include "MyTools/RootUtils/interface/HcalDigi.h"
#pragma extra_include "MyTools/RootUtils/interface/HBHEDigi.h"
#pragma extra_include "MyTools/RootUtils/interface/HBHESample.h"
#pragma extra_include "MyTools/RootUtils/interface/PFGEnums.h"
#pragma extra_include "MyTools/RootUtils/interface/Collection.h"
#pragma extra_include "MyTools/RootUtils/interface/Object.h"
#pragma extra_include "MyTools/RootUtils/interface/HcalData.h"
#pragma extra_include "MyTools/RootUtils/interface/HLTFilterObjectCollectionHelper.h"
#pragma extra_include "MyTools/RootUtils/interface/HLTFilterObject.h"
#pragma extra_include "MyTools/RootUtils/interface/HFUTCASample.h"
#pragma extra_include "MyTools/RootUtils/interface/HFUTCA.h"
#pragma extra_include "MyTools/RootUtils/interface/HBHEUTCASample.h"
#pragma extra_include "MyTools/RootUtils/interface/HBHEUTCA.h"
#pragma extra_include "MyTools/RootUtils/interface/RBXMap.h"
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
#pragma link C++ namespace pfg+;
#pragma link C++ class Collection+;
#pragma link C++ class Object+;
#pragma link C++ class HcalData+;
#pragma link C++ class HLTFilterObjectCollectionHelper+;
#pragma link C++ class HLTFilterObject+;
#pragma link C++ class HFUTCASample+;
#pragma link C++ class HFUTCA+;
#pragma link C++ class HBHEUTCASample+;
#pragma link C++ class HBHEUTCA+;
#pragma link C++ class RBXMap+;

#pragma link C++ function Collection::GetConstituent<HBHEDigi>+;
#pragma link C++ function Collection::GetConstituent<HFDigi>+;
#pragma link C++ function Collection::GetConstituent<HODigi>+;
#pragma link C++ function HcalData::Digis<HBHEDigi>+;
#pragma link C++ function HcalData::Digis<HFDigi>+;
#pragma link C++ function HcalData::Digis<HODigi>+;
#pragma link C++ function HcalData::Digi<HBHEDigi>+;
#pragma link C++ function HcalData::Digi<HFDigi>+;
#pragma link C++ function HcalData::Digi<HODigi>+;

#endif
