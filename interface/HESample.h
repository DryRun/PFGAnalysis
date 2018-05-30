#ifndef HE_SAMPLE_H
#define HE_SAMPLE_H

#include "HCALPFG/PFGAnalysis/interface/HcalSample.h"

class HESample : public HcalSample {
  
 public:
  
  HESample();
  HESample(Collection& c, unsigned short i, short j);
  
  int    rawId();
  int    linkError();
  int    capIdError();
  int    flags();
  int    ntdc();
  float timeFC();
  float timeTDC();
  int    soi();
  int    adc();
  float fc();
  float pedFC();
  int    tdc();
  int    capId();
  float allFC();

  int getRawIndex () { return m_raw_index; }
  int getTimeSlice() { return m_timeslice; }

  // Dummy methods that are required to be overridden
  float energy()    {return 0;}
  float gain()      {return 0;}
  float nomFC()     {return 0;}
  float rcGain()    {return 0;}
  int   capid()     {return 0;}
  int   dv()        {return 0;}
  int   er()        {return 0;}
  int   fiber()     {return 0;}
  int   fiberChan() {return 0;}
  int   raw()       {return 0;}

};

#endif 
