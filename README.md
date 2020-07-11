# ESP32 based UGV
Made using PlatformIO and being tested on a custom PCB for my final
year project: 3D Mapping using Stereo Vision. This board, along with
its firmware are simply handle two DC motors, their encoders and two servo motors. 
The motors are driven by DRV8840 chip, for which, a simple and easy to use library 
has been written and included.

MQTT added on June 5th. Receives 10-character commands from Nvidia Jetson TX2 
to operate motors and return distance traveled

Still working on distance calculations, had *some* progress with it, which is included in the latest commit

Contains main cpp file in src folder and DRV8840.h in include folder

Also might contain gluten.