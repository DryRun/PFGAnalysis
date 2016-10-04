#ifndef HBHE_UTCA_SAMPLE_H
#define HBHE_UTCA_SAMPLE_H

#include "HcalSample.h"

class HBHEUTCASample : public HcalSample {
  
 public:
  
  HBHEUTCASample();
  HBHEUTCASample(Collection& c, unsigned short i, short j);
  
  float allFC()     ;
  float energy()    ;
  float gain()      ;
  float fc()        ;
  float nomFC()     ;
  float pedFC()     ;
  float rcGain()    ;

  int   adc()       ;
  int   capid()     ;
  int   dv()        ;
  int   er()        ;
  int   fiber()     ;
  int   fiberChan() ;
  int   raw()       ;

  int getRawIndex () { return m_raw_index; }
  int getTimeSlice() { return m_timeslice; }

};

#endif 