
<b><h2><center>Library for the LTC1867, a 16 bit analog to digital converter from Microchip</center></h1></b>

This library is itended for microcontroller applications using Teensy (3.x to 4.x),  ESP's, and Arduinos where additional analog inputs are needed. This chip does NOT run faster than a Teensy 4.0 and from basic testing does NOT offer any better conrtrol over noise. This library implements only single ended inputs.

Perfomance is as follows
<table>
  <tr>
    <th>Data</th>
    <th>MCP3208</th>
    <th>Teensy 4.0</th>
  </tr>
  <tr>
    <td>analogRead</td>
    <td> 17 uS</td>
    <td>  26 uS</td>
  </tr>
</table>

Implentation of this library is straightforward

1. include the library
<br>
#include "LTC1867.h"
2. create an object instance(s)
<br>
LTC1867 MyADC(CS_PIN);
5. initialize the object(s)
<br>
MyADC.init(); // object attempts to return true if successful
7. call object.analogRead(channel)
<br>
uint16_t thing = MyADC.analogRead(CH0);
<br>
<br>
Optionally you can
1. change the VRef (see the data sheet for how to override the internal voltage regulator
  <br>
  object.setVRef(value);

2. Automatically convert the output to a voltage
   <br>
   object.getVolts(channel);

3. Automatically read and average several data points
   <br>
   object.analogReadAveraging(count) where count can be 1 to 1000
   

<br>
Typical wiring, note the use of a buffer to shift the output of MISO (DO) to be compatible with 3v3 MCU's

![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/TypicalWiring.jpg)
<br>
<br>
<br>
Noise comparison from the LTC1867 (16 bit), a Cortex M4 (16 bit) and an ESP32 (12 bit as 16 bit is not available). Note that no input filtering was used in this test. shown are 1 average per point and sandwitched between and upper and lower guardrails. The ADC noise performace is improvement over the cortex M4 chip, the ESP32 suffers.
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/Comparison.jpg)
<br>
<br>
Noise from from the LTC1867 (16 bit), a Cortex M4 (16 bit) using analogRead() and analogReadAveraging(). Note that no input filtering was used in this test. Shown are 10 averages per point and sandwitched between and upper and lower guardrail.
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/16bit_10averages.jpg)
<br>






