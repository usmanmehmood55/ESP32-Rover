#include <Arduino.h>
#include <DRV8840.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "Imran 2";
const char *password = "9272imran";
const char *mqtt_server = "192.168.100.93";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];

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
// 
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
int getCoordinates();
void setup_wifi();
void callback(char *topic, byte *message, unsigned int length);
void reconnect();

void setup()
{
  Serial.begin(9600);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

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
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000)
  {
    lastMsg = now;
  }


  Serial.println();
  if (M1.getDistance() <= 5000)
  {
    M1.motorForward(255);
  }
  else
  {
    M1.motorStop();
  }
  Serial.print("  ");
  if (M2.getDistance() <= 5000)
  {
    M2.motorForward(255);
  }
  else
  {
    M2.motorStop();
  }
  Serial.print(M1.getDistance());
  Serial.print(M2.getDistance());
}



void IRAM_ATTR encoderRead1() // Use if ISR inside DRV8840.h does not run
{
  M1.encoderRead();
}

void IRAM_ATTR encoderRead2()
{
  M2.encoderRead();
}

int getCoordinates()
{
  
}

void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "test")
  {
    Serial.print("Changing output to ");
    if (messageTemp == "on")
    {
      Serial.println("on");
    }
    else if (messageTemp == "off")
    {
      Serial.println("off");
    }
  }
}

void reconnect() // Loop runs until reconnected to MQTT broker
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client"))
    {
      Serial.println("connected");
      // Subscribe
      client.subscribe("test");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000); // Wait 5 seconds before retrying
    }
  }
}