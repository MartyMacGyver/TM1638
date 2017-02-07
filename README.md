TM1638 Demos and Examples
======

Modified to work better with fast devices like ESP32

The TM1638 is basically a slow SPI device (< 500kHz) in DIO mode. The clock uses the equivalent of SPI mode 3 (normally high, clocks data on the rising edge).

To make this work with fast devices, the shift clocking is slowed with a small delay (on the order of a microsecond) and inverted accordingly. (The delay above has more of an impact than the clock sense appears to for the devices I've tested - the rising edge of the clock is most important.)

wiring_shift_mod is a modified version of wiring_shift which is part of Arduino under LGPL.

Connecting the TM1638 to Arduino and Arduino-like devices:

For VCC Use the native voltage level of the microcontroller (the TM1638 tolerates 3.3V or 5V):
  - If it's a 3.3V microcontroller like the Arduino Due or the Espressif ESP8266 or ESP32 simply use 3.3V for VCC
  - If it's is a microcontroller that uses 5V for power AND signalling, use that
  - NEVER use a 5V peripheral with a 3.3V device without an appropriate level shifter!

Connect the STB, CLK, and DIO pins to the appropriate pins on your microcontroller:
  - The original examples for Arduino used pins 7 (STB), 9 (CLK), 8 (DIO), but other pins will work as well.
  - The current examples were modified for the ESP32 using pins 4 (STB), 16 (CLK), 17 (DIO). Again, others pins will work too, just don't use pins that are reserved for special functions.

See the documentation folder for the datasheet for the TM1638 (translated), sourced from http://www.titanmec.com/index.php/product/view/id/303/typeid/59.html

Original code: https://github.com/moozzyk/TM1638

Blog post: http://blog.3d-logic.com/2015/01/10/using-a-tm1638-based-board-with-arduino/

Related discussions: http://www.microchip.com/forums/m821930.aspx

Video: https://www.youtube.com/watch?v=b8O9RTXvbNQ
