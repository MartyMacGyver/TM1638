/*
  wiring_shift_mod.c - clocked shift functions

  Based on Arduino's wiring_shift.c

  Original work Copyright 2005-2006 David A. Mellis
  Modified work Copyright 2017 Martin F. Falatic

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#include "wiring_private.h"
#include "wiring_shift_mod.h"

uint8_t shiftInMod(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t clock_type, uint16_t clock_delay_us) {
	uint8_t value = 0;
	uint8_t i;

  
	for (i = 0; i < 8; ++i) {
		digitalWrite(clockPin, (clock_type ? LOW : HIGH));
    		delayMicroseconds(clock_delay_us);
		if (bitOrder == LSBFIRST)
			value |= digitalRead(dataPin) << i;
		else
			value |= digitalRead(dataPin) << (7 - i);
		digitalWrite(clockPin, (clock_type ? HIGH : LOW));
    		delayMicroseconds(clock_delay_us);
	}
	return value;
}

void shiftOutMod(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t clock_type, uint16_t clock_delay_us, uint8_t val)
{
	uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST)
			digitalWrite(dataPin, !!(val & (1 << i)));
		else	
			digitalWrite(dataPin, !!(val & (1 << (7 - i))));
			
		digitalWrite(clockPin, (clock_type ? LOW : HIGH));
    		delayMicroseconds(clock_delay_us);
		digitalWrite(clockPin, (clock_type ? HIGH : LOW));
    		delayMicroseconds(clock_delay_us);		
	}
}

