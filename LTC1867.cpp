#include <MCP3208.h>
#include "SPI.h"

MCP3208::MCP3208(uint8_t CS_PIN) {
	
  cspin = CS_PIN;  
  
}

bool MCP3208::init() {
	
    uint16_t test = 0;
	
	pinMode(cspin, OUTPUT);
	
    	digitalWrite(cspin, HIGH);
	
	SPI.begin();
	
	// this may not be the best way but if everything is 0, maybe ADAC is not working?
	test = analogRead(CH0);
	test += analogRead(CH1);
	test += analogRead(CH2);
	test += analogRead(CH3);
	test += analogRead(CH4);
	test += analogRead(CH5);
	test += analogRead(CH6);
	test += analogRead(CH7);
	
	/*
	Serial.print(test);
	Serial.print(",");	
	Serial.print(analogRead(CH0) * 3.3 / 4096.0, 3);
	Serial.print(",");
	Serial.print(analogRead(CH1) * 3.3 / 4096.0, 3);
	Serial.print(",");
	Serial.print(analogRead(CH2) * 3.3 / 4096.0, 3);
	Serial.print(",");
	Serial.print(analogRead(CH3) * 3.3 / 4096.0, 3);
	Serial.print(",");
	Serial.print(analogRead(CH4) * 3.3 / 4096.0, 3);
	Serial.print(",");
	Serial.print(analogRead(CH5) * 3.3 / 4096.0, 3);
	Serial.print(",");
	Serial.print(analogRead(CH6) * 3.3 / 4096.0, 3);
	Serial.print(",");
	Serial.print(analogRead(CH7) * 3.3 / 4096.0, 3);
	Serial.println();
	*/

	if (test == 0){
		return false;
	}	

    return true;
}


bool MCP3208::digitalRead(uint8_t pin) {
	if (analogRead(pin) > DIGITAL_LIMIT) {
		return true;
	}
	return false;
}
	

uint16_t MCP3208::analogRead(uint8_t pin) {
	
	address = 0b01100000 | ((pin & 0b111) << 2);	
	
	SPI.beginTransaction(SPISettings(SPI_SPEED, MSBFIRST, SPI_MODE0));	
	
	digitalWrite(cspin, LOW);
	
	SPI.transfer(address);
	
	uint8_t b1 = SPI.transfer(0x00);
	uint8_t b2 = SPI.transfer(0x00);
	
	digitalWrite(cspin, HIGH);
	
	SPI.endTransaction();
	
	return (b1 << 4) | (b2 >> 4);
}
