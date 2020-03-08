/*
  DRV8840.h - Library for DRV8840 Brushed DC motor driver.
  Created by Usman Mehmood, March 3, 2020.
  Created for use in FYP: 3D Mapping using Stereo Vision.
  Only has definition of DRV8840 object. Functions are in DRV8840.cpp.
*/

#ifndef DRV8840_h
#define DRV8840_h

#include "Arduino.h"

class DRV8840
{
public:
    DRV8840(
        unsigned const char PWM_PIN,
        unsigned const char PHASE_PIN,
        unsigned const char DECAY_PIN,
        unsigned const char SLEEP_PIN,
        unsigned const char RST_PIN,
        unsigned const char ENC1_PIN,
        unsigned const char ENC2_PIN);

    void motorForward(unsigned char PWM_DUTY);
    void motorBackward(unsigned char PWM_DUTY);
    void motorStop();
    int encoderRead();

private:
    unsigned char 
        _PWM_PIN, _PHASE_PIN, _DECAY_PIN,
        _SLEEP_PIN, _RST_PIN, _ENC1_PIN, _ENC2_PIN;
    int DISTANCE1, DISTANCE2;
};

DRV8840::DRV8840(
    unsigned const char PWM_PIN,
    unsigned const char PHASE_PIN,
    unsigned const char DECAY_PIN,
    unsigned const char SLEEP_PIN,
    unsigned const char RST_PIN,
    unsigned const char ENC1_PIN,
    unsigned const char ENC2_PIN)
{
    pinMode(PWM_PIN, OUTPUT); _PWM_PIN = PWM_PIN;
    pinMode(PHASE_PIN, OUTPUT); _PHASE_PIN = PHASE_PIN;
    pinMode(DECAY_PIN, OUTPUT); _DECAY_PIN = DECAY_PIN;
    pinMode(SLEEP_PIN, OUTPUT); _SLEEP_PIN = SLEEP_PIN;
    pinMode(RST_PIN, OUTPUT); _RST_PIN = RST_PIN;
    pinMode(ENC1_PIN, INPUT); _ENC1_PIN = ENC1_PIN;
    pinMode(ENC2_PIN, INPUT); _ENC2_PIN = ENC2_PIN;
}

void DRV8840::motorBackward(unsigned char PWM_DUTY)
{
    digitalWrite(_RST_PIN, HIGH);
    digitalWrite(_SLEEP_PIN, HIGH);
    digitalWrite(_PHASE_PIN, HIGH);
    ledcWrite(_PWM_PIN, PWM_DUTY);
}

void DRV8840::motorForward(unsigned char PWM_DUTY)
{
    digitalWrite(_RST_PIN, HIGH);
    digitalWrite(_SLEEP_PIN, HIGH);
    digitalWrite(_PHASE_PIN, LOW);
    ledcWrite(_PWM_PIN, PWM_DUTY);
}

void DRV8840::motorStop()
{
    digitalWrite(_RST_PIN, LOW);
    digitalWrite(_SLEEP_PIN, LOW);
    digitalWrite(_DECAY_PIN, LOW);
}

int DRV8840::encoderRead()
{
    bool state = 0;
    int count = 0;
    if ( digitalRead(_ENC1_PIN) == digitalRead(_ENC2_PIN) )
    {
        state = !state;
        count++;
    }
    else
    {
        state = !state;
        count--;
    }
    // Insert relation between distance and count, return distance instead of count
    return count;
}

#endif