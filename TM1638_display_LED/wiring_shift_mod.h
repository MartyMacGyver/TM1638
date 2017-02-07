
#ifndef wiring_shift_mod_h
#define wiring_shift_mod_h

#define CLOCK_NORMAL 0
#define CLOCK_INVERT 1

void shiftOutMod(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t clock_type, uint16_t clock_delay_us, uint8_t val);
uint8_t shiftInMod(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t clock_type, uint16_t clock_delay_us);

#endif
