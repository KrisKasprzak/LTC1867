/*
	The MIT License (MIT)

	library writen by Kris Kasprzak

	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

	On a personal note, if you develop an application or product using this library and make millions of dollars, I'm happy for you!

	revisions: see .h file
*/

#include "SPI.h"
#include "LTC1867.h"


LTC1867::LTC1867(int CS_PIN) {
	
  cspin = CS_PIN;  
  
}

bool LTC1867::init() {
	
	uint16_t test = 0;

	SPI.begin();

	pinMode(cspin, OUTPUT);

	digitalWrite(cspin, HIGH);
	delay(20);	

	CH = CH0;	
	UNI = UNIPOLAR;
	SLP = AWAKE;
	counter = 1;
	vref = 2.5f;
	
	// this may not be a good test since CH0 may be grounded, but it's better than nothing...
	test = analogRead(CH0);
	
	if (test == 0){
		return false;
	}
	else{
		return true;
	}

}



uint16_t LTC1867::analogRead(uint8_t Channel) {
	
	CH = Channel;
	buildControlByte();
	if (counter == 1){
		return readBits();
	}
	
	else {
		uint32_t sum = 0;
		for (uint16_t i = 0; i < counter; i++){
			sum = sum + (uint32_t) readBits();
		}
		
		sum = sum/counter;
		return sum;
	}
}


uint16_t LTC1867::readBits() {
	
	if (SLP == SLEEP){
		setSleepMode(AWAKE);
		delay(60); // data sheet says to wait 60 ma, not sure the is the correct implementation of wake
	}
	
	SPI.beginTransaction(SPISettings(SPI_SPEED, MSBFIRST, SPI_MODE0));

	digitalWrite(cspin, HIGH);
	delayMicroseconds(4);
	digitalWrite(cspin, LOW);	
	Data[1] = SPI.transfer(CBYTE);
	Data[0] = SPI.transfer(0x00);
	digitalWrite(cspin, HIGH);
	delayMicroseconds(4);
	digitalWrite(cspin, LOW);
	Data[1] = SPI.transfer(CBYTE);
	Data[0] = SPI.transfer(0x00);
	digitalWrite(cspin, HIGH);
	SPI.endTransaction();
	return uint16_t ((Data[1] << 8) | Data[0]);

}

void LTC1867::buildControlByte() {
	
	//7			6		5		4		3			2		1		0
	//ySD		yOS		yS1		yS0		yCOM		UNI		SLP 	not used
	
	// ydd is part of the ChannelData (CH)
	// shifting everything over 1 more to start at bit 7
	CBYTE = 0;	
	CBYTE = CH << 3;
	CBYTE = CBYTE | (UNI << 2);
	CBYTE = CBYTE | (SLP << 1);
	
}


void LTC1867::setSleepMode(uint8_t Mode){
	SLP = Mode;
	if (Mode > 1){
		SLP = 1;
	}
	
}

void LTC1867::setVRef(float VRef = 2.5f){
	vref = VRef;
	if (VRef < 0.0){
		vref = 2.5f;
	}
	
}
		
float LTC1867::getVolts(uint8_t Channel){
	return analogRead(Channel) * vref / 65536.0f;
}
		

 void LTC1867::analogReadAveraging(uint16_t Counter){
	 counter = Counter;
	 
	if (Counter < 1){
		counter = 1;
	}
		if (Counter >1000){
		counter = 1000;
	}
	
}
