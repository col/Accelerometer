/*
  Accelerometer.h - Library for accessing the accelerometer sensor in a 9DOF Stick.
  Created by Colin Harris, December 27, 2013.
*/

#ifndef Accelerometer_h
#define Accelerometer_h

#include "Arduino.h"
#include <Wire.h>

// Accelerometer (ADXL345)
#define ACCEL_ADDRESS (0xA6 >> 1)

//There are 6 data registers, they are sequential starting 
//with the LSB of X.  We'll read all 6 in a burst and won't
//address them individually
#define ACCEL_REGISTER_XLSB (0x32)

//Need to set power control bit to wake up the adxl345
#define ACCEL_REGISTER_PWRCTL (0x2D)
#define ACCEL_PWRCTL_MEASURE (1 << 3)

class Accelerometer {

	public:
		void init();
		void update();
		int x();
		int y();
		int z();

	private:
		int _data[3];
		void i2c_write(int address, byte reg, byte data);
		void i2c_read(int address, byte reg, int count, byte* data);

};

#endif