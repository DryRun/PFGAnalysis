#ifndef HE_DIGI_H
#define HE_DIGI_H

#include "HCALPFG/PFGAnalysis/interface/HcalDigi.h"
#include "HCALPFG/PFGAnalysis/interface/HESample.h"

class HEDigi : public HcalDigi {

 public:
  HEDigi();
  HEDigi(Collection& c, unsigned short i, short j = 0);
  
  int   ieta          ();
  int   iphi          ();
  float eta           ();
  float phi           ();
  int   depth         ();
  int   subdet        ();
  int   size          ();
  int   presamples    ();
  int   rawId         ();
  int   electronicsId ();
  float fc            (int i);
  int   adc           (int i);
  int   tdc           (int i);
  int   linkError     ();
  int   capIdError    ();
  int   capid         (int i);
  int   timeFC        ();
  int   timeTDC       ();
  int   ntdc          ();
  int   flags         ();
  int   soi           (int i);

  // Unused base class methods that need to be overwritten...
  float energy() {return 0;}
  float recHitTime () {return 0;}
  int   dv    (int i) {return 0;}
  int   er    (int i) {return 0;}
  
  
  int getRawIndex () { return m_raw_index; }

  HESample operator[] ( int i ){
    return HESample( *m_collection, m_raw_index, i );
  }
  
};

#endif 
