/*
  FanSpeed.h - Library for reading fan speed.
  Created by Andrey Rublev, November 10, 2010.
*/
#ifndef FanSpeed_h
#define FanSpeed_h

#include "WProgram.h"

typedef void (*FANCB)(uint8_t);

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
    uint8_t pulseState;
    uint8_t prevPulseState;
    uint8_t bit;
};



class FanSpeedInt: public FanSpeedBase
{
  public:
    FanSpeedInt(int pin, bool useInternalResistor = true);
    void process();
};

/**
 FanSpeedMultiD - for reading fan speed from ports 0-7 
*/
class FanSpeedMultiD
{
  public:
    FanSpeedMultiD(uint8_t pins, uint8_t states, FANCB cb);
    void process();
  protected:
    FANCB callback;
    uint8_t state;
    uint8_t prevState;
    
    uint8_t bits;
};


/**
 FanSpeedMultiB - for reading fan speed from ports 8-13 
*/
class FanSpeedMultiB
{
  public:
    FanSpeedMultiB(uint8_t pins, uint8_t states, FANCB cb);
    void process();
  protected:
    FANCB callback;
    uint8_t state;
    uint8_t prevState;
    
    uint8_t bits;
};

#endif
