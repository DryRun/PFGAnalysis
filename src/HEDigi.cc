#include "HCALPFG/PFGAnalysis/interface/HEDigi.h"

HEDigi::HEDigi():
  HcalDigi(){}

HEDigi::HEDigi(Collection& c, unsigned short i, short j ):
  HcalDigi(c,i){}

int   HEDigi::ieta          () {return m_collection -> GetData() -> QIE11DigiIEta          -> at(m_raw_index);}
int   HEDigi::iphi          () {return m_collection -> GetData() -> QIE11DigiIPhi          -> at(m_raw_index);}
float HEDigi::eta           () {return m_collection -> GetData() -> QIE11DigiEta           -> at(m_raw_index);}
float HEDigi::phi           () {return m_collection -> GetData() -> QIE11DigiPhi           -> at(m_raw_index);}
int   HEDigi::depth         () {return m_collection -> GetData() -> QIE11DigiDepth         -> at(m_raw_index);}
int   HEDigi::subdet        () {return m_collection -> GetData() -> QIE11DigiSubdet        -> at(m_raw_index);}
int   HEDigi::size          () {return m_collection -> GetData() -> QIE11DigiSize;}
int   HEDigi::presamples    () {return m_collection -> GetData() -> QIE11DigiPresamples;}
int   HEDigi::rawId         () {return m_collection -> GetData() -> QIE11DigiRawID         -> at(m_raw_index);}
int   HEDigi::electronicsId () {return -1; }
float HEDigi::fc            (int i) {return m_collection -> GetData() -> QIE11DigiFC            -> at(m_raw_index)[i];}
int   HEDigi::adc           (int i) {return m_collection -> GetData() -> QIE11DigiADC           -> at(m_raw_index)[i];}
int   HEDigi::tdc           (int i) {return m_collection -> GetData() -> QIE11DigiTDC           -> at(m_raw_index)[i];}
int   HEDigi::linkError     () {return m_collection -> GetData() -> QIE11DigiLinkError     -> at(m_raw_index);}
int   HEDigi::capIdError    () {return m_collection -> GetData() -> QIE11DigiCapIDError    -> at(m_raw_index);}
int   HEDigi::capid         (int i) {return m_collection -> GetData() -> QIE11DigiCapID         -> at(m_raw_index)[i];}
int   HEDigi::timeFC        () {return m_collection -> GetData() -> QIE11DigiTimeFC        -> at(m_raw_index);}
int   HEDigi::timeTDC       () {return m_collection -> GetData() -> QIE11DigiTimeTDC       -> at(m_raw_index);}
int   HEDigi::ntdc          () {return m_collection -> GetData() -> QIE11DigiNTDC          -> at(m_raw_index);}
int   HEDigi::flags         () {return m_collection -> GetData() -> QIE11DigiFlags         -> at(m_raw_index);}
int   HEDigi::soi           (int i) {return m_collection -> GetData() -> QIE11DigiSOI           -> at(m_raw_index)[i];}





