# Ambimate
An Arduino compatible library for the TI Ambimate Sensor.

This is a first stab at an Arduino friendly library for the TE Ambimate sensor (see https://www.te.com/usa-en/products/sensors/multi-sensor-modules.html?tab=pgp-story)

# USAGE

Try the example in the examples folder.

Essentially - Place this lib in a folder called "Ambimate" in your local Arduino libraries folder, then include it in your sketch.

When you initialise it, it can create an I2C instance using the defaults, or you can create usine the Wire lib, and pass the Wire object to it. 
