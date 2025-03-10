
<b><h2><center>Library for the LTC1867, a 16 bit analog to digital converter from Analog Devices</center></h1></b>

This library is itended for microcontroller applications using Arduino, ESP, Teensy (3.x to 4.x) where additional analog inputs or higher resulution inputs are needed. This library supports all the features offered by the LTC1867 such as reading an input channel in single or differential mode, using GND or CH7 as the common pin, and putting the analog to digital converter to sleep to save power between infrequent reads.

Perfomance is as follows
<table>
  <tr>
    <th>Company</th>
    <th>Contact</th>
    <th>Country</th>
  </tr>
  <tr>
    <td>Alfreds Futterkiste</td>
    <td>Maria Anders</td>
    <td>Germany</td>
  </tr>
  <tr>
    <td>Centro comercial Moctezuma</td>
    <td>Francisco Chang</td>
    <td>Mexico</td>
  </tr>
  <tr>
    <td>Ernst Handel</td>
    <td>Roland Mendel</td>
    <td>Austria</td>
  </tr>
  <tr>
    <td>Island Trading</td>
    <td>Helen Bennett</td>
    <td>UK</td>
  </tr>
  <tr>
    <td>Laughing Bacchus Winecellars</td>
    <td>Yoshi Tannamuri</td>
    <td>Canada</td>
  </tr>
  <tr>
    <td>Magazzini Alimentari Riuniti</td>
    <td>Giovanni Rovelli</td>
    <td>Italy</td>
  </tr>
</table>

Implentation of this library is straightforward

1. include the library
2. create an object instance(s)
3. initialize the object(s)
4. call object.analogRead(channel).

<br>
<br>

Typical wiring, note the use of a buffer to shift the output of MISO (DO) to be compatible with 3v3 MCU's
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/TypicalWiring.jpg)
<br>
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/2.5VRef.jpg)
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/LTCvsTeens32-12bx21.jpg)
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/LTCvsTeensy32-16b.jpg)





