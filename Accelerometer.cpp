/*
  Accelerometer.cpp - Library for accessing the accelerometer sensor in a 9DOF Stick.
  Created by Colin Harris, December 27, 2013.
*/

#include "Accelerometer.h"

void Accelerometer::init() {
  	i2c_write(ACCEL_ADDRESS, ACCEL_REGISTER_PWRCTL, ACCEL_PWRCTL_MEASURE);
  	//Check to see if it worked!
  	byte data = 0;
  	i2c_read(ACCEL_ADDRESS, ACCEL_REGISTER_PWRCTL, 1, &data);  	
  	if( (unsigned int)data != 8 ) {
  		Serial.println("Failed to initialise the accelerometer!");
  	}
}

void Accelerometer::update() {
	byte bytes[6];
  	memset(bytes,0,6);

  	//read 6 bytes from the ADXL345
  	i2c_read(ACCEL_ADDRESS, ACCEL_REGISTER_XLSB, 6, bytes);

  	//now unpack the bytes
  	for (int i=0;i<3;++i) {
    	_data[i] = (int)bytes[2*i] + (((int)bytes[2*i + 1]) << 8);
  	}
}

int Accelerometer::x() {
	return (int)_data[0];
}

int Accelerometer::y() {
	return (int)_data[1];
}

int Accelerometer::z() {
	return (int)_data[2];
}

// TODO: These methods should be extracted.

void Accelerometer::i2c_write(int address, byte reg, byte data) {
  // Send output register address
  Wire.beginTransmission(address);
  Wire.write(reg);
  // Connect to device and send byte
  Wire.write(data); // low byte
  Wire.endTransmission();
}

void Accelerometer::i2c_read(int address, byte reg, int count, byte* data) {
  int i = 0;

  // Send input register address
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();

  // Connect to device and request bytes
  Wire.beginTransmission(address);
  Wire.requestFrom(address,count);
  while(Wire.available()) { 
    // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    data[i] = c;
    i++;
  }
  Wire.endTransmission();
}