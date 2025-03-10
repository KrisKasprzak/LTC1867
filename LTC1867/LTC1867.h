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

  On a personal note, if you develop an application or product using this library 
  and make millions of dollars, I'm happy for you!

	rev		date			author				change
	1.0		3/2025			kasprzak			initial code


*/

#ifndef LTC1867_MENU_H
#define LTC1867_MENU_H

// define SPI_SPEED 16000000
#define SPI_SPEED 40000000


// differentail ended channels (Common = GND)
#define CH0_CH1_GND 0b00000 
#define CH2_CH3_GND 0b00010 
#define CH4_CH5_GND 0b00100 
#define CH6_CH7_GND 0b00110 
#define CH1_CH0_GND 0b01000 
#define CH3_CH2_GND 0b01010 
#define CH5_CH4_GND 0b01100 
#define CH7_CH6_GND 0b01110 

// single ended channels (Common = GND)
#define CH0 0b10000
#define CH2 0b10010
#define CH4 0b10100
#define CH6 0b10110
#define CH1 0b11000
#define CH3 0b11010
#define CH5 0b11100
#define CH7 0b11110

// single ended channels (Common = CH7/COM)
#define CH0_CH7 0b10001 
#define CH2_CH7 0b10011 
#define CH4_CH7 0b10101 
#define CH6_CH7 0b10111 
#define CH1_CH7 0b11001 
#define CH3_CH7 0b11011 
#define CH5_CH7 0b11101 

// SLP bit
#define SLEEP 1
#define AWAKE 0

// UNI / Bipolar bit
#define UNIPOLAR 1
#define BIPOLAR 0


#if ARDUINO >= 100
	 #include "Arduino.h"
	 #include "Print.h"
#else
	
#endif

#ifdef __cplusplus
	
#endif

#include <SPI.h>  
#define LTC1867_VER 1.0

class  LTC1867 {
		
	public:

		LTC1867(int CS_PIN);
		
		bool init();
		
		uint16_t analogRead(uint8_t Channel);	
		
		void setSleepMode(uint8_t Mode);
		
	private:

		uint8_t cspin = 0;
		uint8_t CH = 0;
		uint8_t UNI = 0;
		uint8_t SLP = 0;
		uint8_t CBYTE = 0;
		uint8_t Data[2] = {0,0};

		void buildControlByte();
		
		
		
};



#endif
