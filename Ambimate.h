/*!
 * @file Ambimate.h
 *
 * This is the documentation for Adafruit's SGP30 driver for the
 * Arduino platform.  It is designed specifically to work with the
 * Adafruit SGP30 breakout: http://www.adafruit.com/products/3709
 *
 * These sensors use I2C to communicate, 2 pins (SCL+SDA) are required
 * to interface with the breakout.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Ladyada for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
*/

#include "Arduino.h"
#include <Wire.h>

// the i2c address
#define AMBIMATE_I2CADDR_DEFAULT 0x2A     ///< Ambimate has only one I2C address



/**************************************************************************/
/*!  Class that stores state and functions for interacting with SGP30 Gas Sensor */
/**************************************************************************/
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
