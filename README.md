# BioDataDUO

This BioDataDUO provides a cheap yet inexpensive way to collect biodata relative to skin conductivity bursts (GSR), and information from a photoplethysmograph.  The code is made with detection of signals relevant to emotional physiology, but could likely be adapted to suit many needs.

The code will allow you to provide a serial port with information relative to bursts of galvanic skin activity, as well as pulse, amplitude of pulse signal, as well as whether the subject has experienced changes in these signals over time.

# BASIC SETUP

Code verified on Arduino 1.8.1 

https://www.arduino.cc/

on a Teensy 3.2 microcontroller

https://www.pjrc.com/teensy/

But you should be able to run this code on most Arduino ide-friendly microcontrollers

See attached diagram for the circuit I used for __GSR__ using the MCP 6002 chip.

To gather __pulse data__ I use the [Pulse Sensor] (https://pulsesensor.com/)


# LIBRARIES USED

* [Chrono](https://github.com/SofaPirate/Chrono) by SofaPirate  

* [Average](https://github.com/MajenkoLibraries/Average) by MajenkoLibraries  

* [Elapsed Millis](https://playground.arduino.cc/Code/ElapsedMillis) by Paul Stoffregen 


# CUSTOMIZATION OF CODE

Change these inputs to the pins that you want

* __GSR input is set to pin A6__
* __Pulse Sensor input is set to pin A8__

These variables above are found until __processGsr__ and __processHeart__ tabs/files respectively.

* __GSR LED output is set to pin 4__
* __Heart LED output is set to pin 5__

These remaining variables are found in the base GSR-PulseSensor tab/file.

Serial is initially set to 115200

# AUTHORS

* [Erin Gee](http://www.eringee.net)
* [Martin Peach](https://puredata.info/Members/martinrp/OSCobjects)
* [Thomas Ouellet-Fredericks](https://github.com/thomasfredericks)

# COPYING
Released under GNU GPL 3.0 License.  Copyright Erin Gee 2017.
