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
unsigned const char PWMchannel_0 = 0;
unsigned const char PWMchannel_1 = 1;
unsigned const int freq = 5000;
unsigned const char resolution = 8;

DRV8840 M1(
    M1PWM,
    PWMchannel_0,
    M1PHASE,
    M1DECAY,
    M1SLEEP,
    M1RST,
    ENCODER_1A,
    ENCODER_1B);

DRV8840 M2(
    M2PWM,
    PWMchannel_1,
    M2PHASE,
    M2DECAY,
    M2SLEEP,
    M2RST,
    ENCODER_2A,
    ENCODER_2B);

int distance1 = 0;
int distance2 = 0;

void encoderRead1();
void encoderRead2();

void setup()
{
  Serial.begin(115200);

  pinMode(M1FAULT, INPUT);
  pinMode(M2FAULT, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_1B), encoderRead1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_2B), encoderRead2, CHANGE);

  // PWM Setup
  ledcSetup(PWMchannel_0, freq, resolution);
  ledcAttachPin(M1PWM, PWMchannel_0);
  ledcSetup(PWMchannel_1, freq, resolution);
  ledcAttachPin(M2PWM, PWMchannel_1);

  M1.getData();
  M2.getData();
  Serial.println();
  Serial.println("Setup Complete!");
}

void loop()
{
  M1.motorForward(255); 
  Serial.print(M1.getDistance());
  Serial.print("    ");
  M2.motorForward(255); 
  Serial.print(M1.getDistance());
  Serial.println();
}

// Use if ISR inside DRV8840.h does not run
void IRAM_ATTR encoderRead1()
{
  M1.encoderRead();
}

void IRAM_ATTR encoderRead2()
{
  M2.encoderRead();
}