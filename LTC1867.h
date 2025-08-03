/*
The MIT License (MIT)

library writen by Kris Kasprzak

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permissionotice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. InO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

On a personal note, if you develop an application or product using this library
and make millions of dollars, I'm happy for you!

rev	date			author				change
1.0	7-29-2025		kasprzak			initial code
1.1	8-1-2025		kasprzak			added digitalRead


*/


#ifndef _MCP3208_H
#define _MCP3208_H

#if (ARDUINO >= 100) 
# include <Arduino.h>
#else
# include <WProgram.h>
#endif

#define MPC3208_VER 1.1

#define CH0 0
#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4
#define CH5 5
#define CH6 6
#define CH7 7

#define SPI_SPEED    1000000

#define DIGITAL_LIMIT 2500 // consider 2 volts or higher


class MCP3208 {

    public:
	
        MCP3208(uint8_t CS_PIN);  
		
        bool init();
		
        uint16_t analogRead(uint8_t pin);	
		bool digitalRead(uint8_t pin);		
		
	private:
		uint8_t address = 0;
        uint8_t cspin = 0;

};
#endif
