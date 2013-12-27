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
