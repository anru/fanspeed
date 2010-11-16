/*
  FanSpeed.cpp - Library for reading fan speed.
  Created by Andrey Rublev, November 10, 2010.
*/

#include "WProgram.h"
#include "FanSpeed.h"

#define CHK(x,y) (x & (1<<y))

void FanSpeedBase::init(int pin, bool useInternalResistor = true)
{
    pinMode(pin, INPUT);
    if (useInternalResistor && pin != 13) {
        digitalWrite(pin, HIGH);
    }
    _pin = pin;
    _counter = 0;
}

unsigned long FanSpeedBase::getPulseCounter()
{
    return _counter;
}

void FanSpeedBase::reset()
{
    _counter = 0;
}

FanSpeed::FanSpeed(int pin, bool useInternalResistor)
{
    init(pin, useInternalResistor);
    bit = _pin;
    if (_pin > 7) {
        bit -= 8;
    }
}

void FanSpeed::process()
{
    pinn = PIND;
    if (_pin > 7) {
        pinn = PINB;
    }
    
    pulseState = pinn & _BV(bit);
    if (pulseState && (prevPulseState != pulseState)) {
        _counter++;
    }
    prevPulseState = pulseState;
}


FanSpeedInt::FanSpeedInt(int pin, bool useInternalResistor)
{
    init(pin, useInternalResistor);
}

void FanSpeedInt::process()
{
    _counter++;
}
