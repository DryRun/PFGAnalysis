#include "HCALPFG/PFGAnalysis/interface/HESample.h"

HESample::HESample():
  HcalSample()
{}

HESample::HESample(Collection& c, unsigned short i, short j):
  HcalSample(c, i, j)
{}

int    HESample::rawId()      {return m_collection->GetData()->QIE11DigiRawID     ->at(m_raw_index);}
int    HESample::linkError()  {return m_collection->GetData()->QIE11DigiLinkError ->at(m_raw_index);}
int    HESample::capIdError() {return m_collection->GetData()->QIE11DigiCapIDError->at(m_raw_index);}
int    HESample::flags()      {return m_collection->GetData()->QIE11DigiFlags     ->at(m_raw_index);}
int    HESample::ntdc()       {return m_collection->GetData()->QIE11DigiNTDC      ->at(m_raw_index);}
float HESample::timeFC()         {return m_collection->GetData()->QIE11DigiTimeFC    ->at(m_raw_index);}
float HESample::timeTDC()        {return m_collection->GetData()->QIE11DigiTimeTDC   ->at(m_raw_index);}
int    HESample::soi()        {return m_collection->GetData()->QIE11DigiSOI       ->at(m_raw_index)[m_timeslice];}
int    HESample::adc()        {return m_collection->GetData()->QIE11DigiADC       ->at(m_raw_index)[m_timeslice];}
float HESample::fc()         {return m_collection->GetData()->QIE11DigiFC        ->at(m_raw_index)[m_timeslice];}
float HESample::pedFC()         {return m_collection->GetData()->QIE11DigiPedFC        ->at(m_raw_index)[m_timeslice];}
float HESample::allFC()         {return fc() + pedFC();}
int    HESample::tdc()        {return m_collection->GetData()->QIE11DigiTDC       ->at(m_raw_index)[m_timeslice];}
int    HESample::capId()      {return m_collection->GetData()->QIE11DigiCapID     ->at(m_raw_index)[m_timeslice];}