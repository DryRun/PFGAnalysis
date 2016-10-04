#ifndef HBHE_UTCA_H
#define HBHE_UTCA_H

#include "HcalDigi.h"
#include "HBHEUTCASample.h"

class HBHEUTCA : public HcalDigi {

 public:
  HBHEUTCA();
  HBHEUTCA(Collection& c, unsigned short i, short j = 0);
  
  float energy() ;
  float recHitTime  () ;
  int   ieta  () ;
  int   iphi  () ;
  int   depth () ;
  int   size  () ;
  int   presamples() ;
  int   rawId        () ;
  int   electronicsId() ;
  float fc (int i);
  int adc(int i);
  int dv (int i);
  int er (int i);
  int capid (int i);
  
  int getRawIndex () { return m_raw_index; }

  HBHEUTCASample operator[] ( int i ){
    return HBHEUTCASample( *m_collection, m_raw_index, i );
  }
  
};

#endif 
