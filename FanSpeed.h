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
    virtual void process();
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
    void process();
  private:
    bool pulseState;
    bool prevPulseState;
    uint8_t bit;
    uint8_t pinn;
};


class FanSpeedInt: public FanSpeedBase
{
  public:
    FanSpeedInt(int pin, bool useInternalResistor = true);
    void process();
};

#endif
