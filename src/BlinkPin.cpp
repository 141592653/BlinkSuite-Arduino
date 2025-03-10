/*
	The MIT License (MIT)
	
	Copyright (c) 2019 Lance A. Endres
	
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
*/

#include "BlinkPin.h"
BlinkPin::BlinkPin() : 
	BlinkBase()
{
}

BlinkPin::BlinkPin(unsigned int pin, unsigned int delay,  unsigned int percentProba) :
	BlinkBase(pin, delay,percentProba)
{
}

BlinkPin::BlinkPin(unsigned int pin, unsigned int delays[], unsigned int numberOfDelays,  unsigned int percentProba) :
	BlinkBase(pin, delays, numberOfDelays, percentProba)
{
}

void BlinkPin::begin()
{
	// If we are debugging, print info.
	#ifdef BLINKDEBUG
		Serial.println("[Blink] Setting pin modes.");
	#endif

	for (unsigned int i = 0; i < _numberOfPins; i++)
	{
		pinMode(_pins[i], OUTPUT);
		digitalWrite(_pins[i], _startLevel);
	}

	BlinkBase::begin();
}

void BlinkPin::setPins(uint8_t level)
{
	for (unsigned int i = 0; i < _numberOfPins; i++)
	{
		digitalWrite(_pins[i], level);
	}	
}

void BlinkPin::updatePins()
{
	uint8_t level = getActiveLevel();

	for (unsigned int i = 0; i < _numberOfPins; i++)
	{
		#ifdef BLINKDEBUG
			// Print the state of a pin.
			printPinState(i, level);
		#endif
		digitalWrite(_pins[i], level);
	}
}