#include "HCALPFG/PFGAnalysis/interface/HFSample.h"

HFSample::HFSample():
  HcalSample()
{}

HFSample::HFSample(Collection& c, unsigned short i, short j):
  HcalSample(c, i, j)
{}

int    HFSample::rawId()      {return m_collection->GetData()->QIE10DigiRawID     ->at(m_raw_index);}
int    HFSample::linkError()  {return m_collection->GetData()->QIE10DigiLinkError ->at(m_raw_index);}
int    HFSample::capIdError() {return 0;}

float HFSample::allFC()     {return fc() + pedFC();}
float HFSample::energy()    {return 0;}
float HFSample::gain()      {return 0;}
float HFSample::fc()        {return m_collection -> GetData() -> QIE10DigiFC        -> at(m_raw_index)[m_timeslice];}
float HFSample::nomFC()     {return 0.;}
float HFSample::pedFC()     {return m_collection -> GetData() -> QIE10DigiPedFC     -> at(m_raw_index)[m_timeslice];}
float HFSample::rcGain()    {return 0.;}

int   HFSample::adc()       {return m_collection -> GetData() -> QIE10DigiADC       -> at(m_raw_index)[m_timeslice];}
int   HFSample::capid()     {return m_collection -> GetData() -> QIE10DigiCapID     -> at(m_raw_index)[m_timeslice];}
int   HFSample::dv()        {return 0;}
int   HFSample::er()        {return 0;}
int   HFSample::fiber()     {return 0;}
int   HFSample::fiberChan() {return 0;}
int   HFSample::raw()       {return 0;}

int    HFSample::flags()      {return m_collection->GetData()->QIE10DigiFlags     ->at(m_raw_index);}
int    HFSample::ntdc()       {return m_collection->GetData()->QIE10DigiNTDC      ->at(m_raw_index);}
float HFSample::timeFC()         {return m_collection->GetData()->QIE10DigiTimeFC    ->at(m_raw_index);}
float HFSample::timeTDC()        {return m_collection->GetData()->QIE10DigiTimeTDC   ->at(m_raw_index);}
int    HFSample::soi()        {return m_collection->GetData()->QIE10DigiSOI       ->at(m_raw_index)[m_timeslice];}
int    HFSample::tdc()        {return m_collection->GetData()->QIE10DigiTDC       ->at(m_raw_index)[m_timeslice];}
