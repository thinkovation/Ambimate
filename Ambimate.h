/*!
 * @file Ambimate.h
 *
 * This is a first go at a library for the TE Ambimate sensor module for
 * Arduino platform.  See https://www.te.com/usa-en/products/sensors/multi-sensor-modules.html?tab=pgp-story
 *
 * These sensors use I2C to communicate, 2 pins (SCL+SDA) are required
 * to interface with the breakout.
 *
 * Written by Gary Barnett
 *
 * MIT License
 *
*/

#include "Arduino.h"
#include <Wire.h>

// the i2c address
#define AMBIMATE_I2CADDR_DEFAULT 0x2A     ///< Ambimate has only one I2C address

class Ambimate {
 public:
  Ambimate();
  boolean begin(TwoWire *theWire = NULL);
  boolean Measure(void);
  boolean HasGas(void);
  
  unsigned char opt_sensors;
  uint16_t TVOC;

uint16_t eCO2;
float HUM;
float TEMP;
float VOLTS;
uint16_t LUM;
uint16_t AUDIO;
boolean EVENT;

 private:
  TwoWire *_i2c;
  uint8_t _i2caddr;
  
  
  
};
