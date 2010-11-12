/*
  FanSpeed.cpp - Library for reading fan speed.
  Created by Andrey Rublev, November 10, 2010.
*/

#include "WProgram.h"
#include "FanSpeed.h"

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
}

unsigned long FanSpeed::process()
{
    pulseState = digitalRead(_pin);
    if ((pulseState == HIGH) && (prevPulseState != pulseState)) {
        _counter++;
    }
    prevPulseState = pulseState;
    return _counter;
}


FanSpeedInt::FanSpeedInt(int pin, bool useInternalResistor)
{
    init(pin, useInternalResistor);
}

unsigned long FanSpeedInt::process()
{
    _counter++;
    return _counter;
}
