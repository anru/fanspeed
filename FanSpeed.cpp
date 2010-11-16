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
    counter = 0;
}


void FanSpeedBase::reset()
{
    counter = 0;
}

FanSpeed::FanSpeed(int pin, bool useInternalResistor)
{
    init(pin, useInternalResistor);
    bit = _pin;
    if (_pin > 7) {
        bit -= 8;
    }
    bit = _BV(bit);
}

void FanSpeed::process()
{
    register uint8_t pinn = PIND;
    if (_pin > 7) {
        pinn = PINB;
    }
    
    pulseState = pinn & bit;
    if ((pulseState ^ prevPulseState) & pulseState) {
        counter++;
    }
    prevPulseState = pulseState;
}


FanSpeedInt::FanSpeedInt(int pin, bool useInternalResistor)
{
    init(pin, useInternalResistor);
}

void FanSpeedInt::process()
{
    counter++;
}

FanSpeedMultiD::FanSpeedMultiD(uint8_t pins, uint8_t states, FANCB cb)
{
    DDRD &= ~pins; // set selected pins to INPUT mode
    PORTD |= states;  // set pull-up resistors to selected pins
    
    state = 0;
    prevState = 0;
    bits = pins;
    callback = cb;
}

void FanSpeedMultiD::process()
{
    state = PIND & bits;
    register uint8_t stateMask = (state ^ prevState) & state;
    if (stateMask) {
        (*callback)(stateMask);
    }
    prevState = state;
}

FanSpeedMultiB::FanSpeedMultiB(uint8_t pins, uint8_t states, FANCB cb)
{
    DDRB &= ~pins; // set selected pins to INPUT mode
    PORTB |= states;  // set pull-up resistors to selected pins
    
    state = 0;
    prevState = 0;
    bits = pins;
    callback = cb;
}

void FanSpeedMultiB::process()
{
    state = PINB & bits;
    register uint8_t stateMask = (state ^ prevState) & state;
    if (stateMask) {
        (*callback)(stateMask);
    }
    prevState = state;
}