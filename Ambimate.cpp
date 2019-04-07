/*!
 * @file Ambimate.cpp
 *
 * @mainpage Ambimate gas sensor driver
 *
 * @section intro_sec Introduction
 *
 * This is the documentation for Gary Barnett's Ambimate driver for the
 * Arduino platform.  
 *
 * These sensors use I2C to communicate, 2 pins (SCL+SDA) are required
 * to interface with the breakout.

 *
 *
 * @section author Author
 * Written by Gary Barnett
 *
 * @section license License
 * MIT - See License file
 *
 */


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "Ambimate.h"

Ambimate::Ambimate() {
}

boolean Ambimate::begin(TwoWire *theWire) {
  _i2caddr = AMBIMATE_I2CADDR_DEFAULT;
  if (theWire == NULL) {
    _i2c = &Wire;
  } else {
    _i2c = theWire;
  }

  _i2c->begin();
  _i2c->beginTransmission(_i2caddr); // transmit to device
  _i2c->write(byte(0x82));       // sends instruction to read sensor options
  _i2c->endTransmission();       // stop transmitting
  if (_i2c->requestFrom(_i2caddr, 1) != 1)
    return false; 
      Serial.print("We're talking to a device!");
  opt_sensors = _i2c->read(); // receive a byte
  if (opt_sensors & 0x01)
    Serial.println(" + CO2");
  

  return true;
}
boolean Ambimate::HasGas(void){
  if (opt_sensors & 0x01)
    return true;
  return false;
}
boolean Ambimate::Measure(void){
  unsigned char buf[20];
   _i2c->beginTransmission(_i2caddr); // transmit to device
  // Device address is specified in datasheet
  _i2c->write(byte(0xC0));       // sends instruction to read sensors in next byte
  //if (opt_sensors & 0x01)       // If gas sensor is installed, include it in the data request
    _i2c->write(byte(0x7F));		// 0x7F indicates to read all connected sensors
  //else
  //  _i2c->write(byte(0x3F));    // exclude gas sensor from data request
 
  _i2c->endTransmission();       // stop transmitting
  // Delay to make sure all sensors are scanned by the AmbiMate
  delay(100);

  _i2c->beginTransmission(_i2caddr); // transmit to device
  _i2c->write(byte(0x00));       // sends instruction to read sensors in next byte
  _i2c->endTransmission();       // stop transmitting
  _i2c->requestFrom(_i2caddr, 15);   // request bytes from slave device

  // Acquire the Raw Data
  unsigned int i = 0;
  while (_i2c->available()) { // slave may send less than requested
    buf[i] = _i2c->read(); // receive a byte as character
    i++;
  }
unsigned int status = buf[0];
  TEMP = (buf[1] * 256.0 + buf[2]) / 10.0;
 
  HUM = (buf[3] * 256.0 + buf[4]) / 10.0;
  LUM = (buf[5] * 256.0 + buf[6]);
  AUDIO = (buf[7] * 256.0 + buf[8]);
  VOLTS = ((buf[9] * 256.0 + buf[10]) / 1024.0) * (3.3 / 0.330);
  eCO2 = (buf[11] * 256.0 + buf[12]);
  TVOC = (buf[13] * 256.0 + buf[14]);

  EVENT = false;
    if (status & 0x80)
      EVENT = true;
    if (status & 0x02)
      EVENT = true;
    if (status & 0x01)
      EVENT = true;
  
  return true;
}


 



