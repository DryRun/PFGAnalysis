#ifndef HF_SAMPLE_H
#define HF_SAMPLE_H

#include "HCALPFG/PFGAnalysis/interface/HcalSample.h"

class HFSample : public HcalSample {
  
 public:
  
  HFSample();
  HFSample(Collection& c, unsigned short i, short j);
  
  int    rawId();
  int    linkError();
  int    capIdError();

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

  int    flags();
  int    ntdc();
  float timeFC();
  float timeTDC();
  int    soi();
  int    tdc();

  int getRawIndex () { return m_raw_index; }
  int getTimeSlice() { return m_timeslice; }

};

#endif 
