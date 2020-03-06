#include <Arduino.h>
#include <DRV8840.h>

// Motor Driver IN
unsigned const char M1RST = 19;
unsigned const char M1PWM = 04;
unsigned const char M1PHASE = 16;
unsigned const char M1SLEEP = 18;
unsigned const char M1DECAY = 17;
unsigned const char M2RST = 27;
unsigned const char M2PWM = 14;
unsigned const char M2PHASE = 32;
unsigned const char M2SLEEP = 26;
unsigned const char M2DECAY = 33;

//Motor Driver OUT
unsigned const char ENCODER_1A = 36;
unsigned const char ENCODER_1B = 39;
unsigned const char ENCODER_2A = 34;
unsigned const char ENCODER_2B = 35;
unsigned const char M1FAULT = 05;
unsigned const char M2FAULT = 25;

// PWM
unsigned const char PWM1 = 0;
unsigned const char PWM2 = 1;
unsigned const int freq = 5000;
unsigned const char resolution = 8;

DRV8840 M1(M1PWM, M1PHASE, M1DECAY, M1SLEEP, M1RST, ENCODER_1A, ENCODER_1B);
DRV8840 M2(M2PWM, M2PHASE, M2DECAY, M2SLEEP, M2RST, ENCODER_2A, ENCODER_2B);

int distance1 = 0 ; int distance2 = 0;

void encoderRead1();
void encoderRead2();

void setup()
{
  Serial.begin(9600);

  pinMode(M1FAULT, INPUT);
  pinMode(M2FAULT, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_1A), encoderRead1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_2A), encoderRead2, CHANGE);

  // PWM Setup
  ledcSetup(PWM1, freq, resolution);
  ledcAttachPin(M1PWM, PWM1);
  ledcSetup(PWM2, freq, resolution);
  ledcAttachPin(M2PWM, PWM2);
}

void loop()
{
  M1.motorForward(255);
  M2.motorForward(255);
}

void encoderRead1()
{
  distance1 = M1.encoderRead();
  Serial.print(distance1);
}

void encoderRead2()
{
  distance2 = M2.encoderRead();
  Serial.print(distance2);
}