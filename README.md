Accelerometer
=============

This is a simple Arduino library that makes it easy to access the accelerometer sensor on the 9DOF Stick.

Basic Example: 

```c++
#include <Wire.h>
#include <Accelerometer.h>

Accelerometer accel;

void setup() {
  Serial.begin(9600);  
  accel.init();      
}

void loop() {
  accel.update();
  Serial.print("x: ");  
  Serial.print(accel.x());  
  Serial.print(" y: ");  
  Serial.print(accel.y());  
  Serial.print(" z: ");  
  Serial.println(accel.z());    
  delay(200);  
}
```
