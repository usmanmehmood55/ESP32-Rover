#include <Arduino.h>
#include <DRV8840.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "WiFi Name";
const char *password = "WiFi Password";
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

// global variables for odometry
int delta_dist_M1 = 0;             // change in distance for M1
int delta_dist_M2 = 0;             // change in distance for M1
int delta_theta = 0;               // change in theta of robot
int delta_dist = 0;                // change in distance of robot
unsigned const char baseline = 22; // baseline of tyres

void encoderRead1();
void encoderRead2();
int getCoordinates();
void setup_wifi();
void callback(char *topic, byte *message, unsigned int length);
void reconnect();
void motorBehaviour(String MV_CMD, int DST_CMD);

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
  // put this in a function
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
  int delta_dist_M1 = M1.getDistance();
  int delta_dist_M2 = M2.getDistance();
  if (delta_dist_M1 >= 100)
  {
    delta_dist_M1 = 0;
    delta_dist_M2 = 0;
  }
  else
  {
    delta_theta = (delta_dist_M1 - delta_dist_M1) / baseline;
    delta_dist = delta_theta * baseline / 2;
  }
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

  if (String(topic) == "ESP_CMD" && length == 10)
  {
    /*
      Incoming message is a movement command and movement distance.
      First the robot will rotate, then it will translate
      in case of rotation, the distance will be in form of angle
      FWD, BCK, LFT, RIT, STP
      movement command is 3 characters and distance command has 7 characters
    */

    String MV_CMD;
    for (int i = 0; i < 3; i++)
    {
      Serial.print((char)message[i]);
      MV_CMD += (char)message[i];
    }

    int DST_CMD = 0;
    String DST_string;
    for (int i = 3; i < 10; i++)
    {
      Serial.print(" ");
      Serial.print((char)message[i]);
      DST_string += (char)message[i]; // MUST be appended as a string
    }
    DST_CMD = DST_string.toInt(); // converts string to int

    Serial.println();
    Serial.print("MV = ");
    Serial.print(MV_CMD);
    Serial.print("   DST = ");
    Serial.print(DST_CMD);
    delay(1000);
    Serial.println();
    motorBehaviour(MV_CMD, DST_CMD);
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
      client.subscribe("ESP_CMD");
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

void motorBehaviour(String MV_CMD, int DST_CMD)
{
  if (MV_CMD == "FWD")
  {
    Serial.print("Forward");
    while (getCoordinates() < DST_CMD)
    {
      M1.motorForward(255);
      M2.motorForward(255);
      Serial.println(getCoordinates());
    }
    M1.motorStop();
    M2.motorStop();
    Serial.println(getCoordinates());
  }
  else if (MV_CMD == "BCK")
  {
    Serial.print("Backward");
    while (getCoordinates() + DST_CMD > DST_CMD)
    {
      M1.motorBackward(255);
      M2.motorBackward(255);
    }
    M1.motorStop();
    M2.motorStop();
  }
  else if (MV_CMD == "RIT")
  {
    Serial.print("Right");
    while (getCoordinates() > DST_CMD)
    {
      M1.motorForward(255);
      M2.motorBackward(255);
    }
    M1.motorStop();
    M2.motorStop();
  }
  else if (MV_CMD == "LFT")
  {
    Serial.print("Left");
    while (getCoordinates() > DST_CMD)
    {
      M1.motorBackward(255);
      M2.motorForward(255);
    }
    M1.motorStop();
    M2.motorStop();
  }
  else
  {
    Serial.print("Stop");
    M1.motorStop();
    M2.motorStop();
  }
  Serial.println();
}