/*
  FanSpeed.h - Library for reading fan speed.
  Created by Andrey Rublev, November 10, 2010.
*/
#ifndef FanSpeed_h
#define FanSpeed_h

#include "WProgram.h"

class FanSpeedBase
{
  public:
    virtual unsigned long process();
    unsigned long getPulseCounter();
    void reset();
  protected:
    void init(int pin, bool useInternalResistor);
    int _pin;
    volatile unsigned long _counter;
};

class FanSpeed: public FanSpeedBase
{
  public:
    FanSpeed(int pin, bool useInternalResistor = true); 
    unsigned long process();
  private:
    bool pulseState;
    bool prevPulseState;
};


class FanSpeedInt: public FanSpeedBase
{
  public:
    FanSpeedInt(int pin, bool useInternalResistor = true);
    unsigned long process();
};

#endif
