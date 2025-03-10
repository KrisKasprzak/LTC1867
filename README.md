
<b><h2><center>Library for the LTC1867, a 16 bit analog to digital converter from Analog Devices</center></h1></b>

[![GitHub All Releases](https://img.shields.io/github/downloads/atom/atom/total.svg)]()

[![GitHub All Releases](https://img.shields.io/github/downloads/KrisKasprzak/LTC1967/total.svg)]()

This library is itended for microcontroller applications using Arduino, ESP, Teensy (3.x to 4.x) where additional analog inputs or higher resulution inputs are needed. This library supports all the features offered by the LTC1867 such as reading an input channel in single or differential mode, using GND or CH7 as the common pin, and putting the analog to digital converter to sleep to save power between infrequent reads.

Perfomance is as follows
<table>
  <tr>
    <th>Data</th>
    <th>Teensy 3.2</th>
    <th>LTC1867</th>
  </tr>
  <tr>
    <td>analogRead</td>
    <td>176 uS</td>
    <td> 17 uS</td>
  </tr>
</table>

Implentation of this library is straightforward

1. include the library
2. create an object instance(s)
3. initialize the object(s)
4. call object.analogRead(channel)

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
<br>

Typical wiring, note the use of a buffer to shift the output of MISO (DO) to be compatible with 3v3 MCU's
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/TypicalWiring.jpg)
<br>
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/2.5VRef.jpg)
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/LTCvsTeens32-12bx21.jpg)
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/LTCvsTeensy32-16b.jpg)





