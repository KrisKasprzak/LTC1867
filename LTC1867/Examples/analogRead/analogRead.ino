/*

Simple example on using this library

connection
CAUTION MISO will output approx 4.8 volts and will destroy the input pin or a Teensy 4.x (pins are not 5v tolerant)

LTC1867         Teensy 3.2
Vdd             VIN (5.0)
GND             GND
SDI             MOSI (pin 11)
SDO             MISO (pin 12)
SCK             SCL (pin 13)
CS              PIN 10 (your choice)
Vref            not connected but 0.1 uf bypass cap to ground
REFCOMP         not connected but 0.1 uf and 10 uF bypass cap to ground
CH0             center of a 10K pot across 3v3 and GND

CAUTION MISO will output approx 4.8 volts and will destroy the input pin or a Teensy 4.x (pins are not 5v tolerant)

*/

#include "LTC1867.h"

#define CS_PIN 10

LTC1867 ADC(CS_PIN);  // my chip select pin

void setup() {

  Serial.begin(115200);

  Serial.print("ADC.init() success: ");  // just sets some defaults
  Serial.println(ADC.init());            // just sets some defaults

  // how to put the unit to sleep, if asleep and analogRead is called, unit will automaticall wake up and stay awake
  // meaning if you are going to use sleep mode, you will need to call it again after analogRead
  // ADC.setSleepMode(SLEEP);
  Serial.print("read time (us): ");
  uint32_t timer = micros();
  uint16_t bits = ADC.analogRead(CH0);
  Serial.println(micros() - timer);
}

void loop() {

  Serial.print(ADC.analogRead(CH0) * 3.3 / 65536.0, 3);
  Serial.print(",");
  Serial.print(ADC.analogRead(CH1) * 2.5 / 65536.0, 3);
  Serial.print(",");
  Serial.print(ADC.analogRead(CH2) * 2.5 / 65536.0, 3);
  Serial.print(",");
  Serial.print(ADC.analogRead(CH3) * 2.5 / 65536.0, 3);
  Serial.print(",");
  Serial.print(ADC.analogRead(CH4) * 2.5 / 65536.0, 3);
  Serial.print(",");
  Serial.print(ADC.analogRead(CH5) * 2.5 / 65536.0, 3);
  Serial.print(",");
  Serial.print(ADC.analogRead(CH6) * 2.5 / 65536.0, 3);
  Serial.print(",");
  Serial.print(ADC.analogRead(CH7) * 2.5 / 65536.0, 3);

  Serial.println();
  delay(100);
}
