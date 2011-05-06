#include "PinDriver.h"
#include "LiquidCrystalExt.h"
#include "LiquidCrystalRus.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include "WProgram.h"

// except 0401 --> 0xa2 = Ё, 0451 --> 0xb5 = ё
PROGMEM prog_uchar utf_recode[] =
{
    0x41,0xa0,0x42,0xa1,0xe0,0x45,0xa3,0xa4,0xa5,0xa6,0x4b,0xa7,0x4d,0x48,0x4f,
    0xa8,0x50,0x43,0x54,0xa9,0xaa,0x58,0xe1,0xab,0xac,0xe2,0xad,0xae,0x62,0xaf,0xb0,0xb1,
    0x61,0xb2,0xb3,0xb4,0xe3,0x65,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0x6f,
    0xbe,0x70,0x63,0xbf,0x79,0xe4,0x78,0xe5,0xc0,0xc1,0xe6,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7
};


LiquidCrystalRus::LiquidCrystalRus(uint8_t rs, uint8_t enable,
  uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
  uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, PinDriver *pin_driver):
  LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7, pin_driver)
{
}


LiquidCrystalRus::LiquidCrystalRus(uint8_t rs, uint8_t rw, uint8_t enable,
  uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
  uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, PinDriver *pin_driver):
  LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7, pin_driver)
{
}


LiquidCrystalRus::LiquidCrystalRus(uint8_t rs, uint8_t rw, uint8_t enable,
  uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, PinDriver *pin_driver):
  LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, pin_driver)
{
}


LiquidCrystalRus::LiquidCrystalRus(uint8_t rs, uint8_t enable,
  uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, PinDriver *pin_driver):
  LiquidCrystal(rs, enable, d0, d1, d2, d3, pin_driver)
{
}


void LiquidCrystalRus::write(uint8_t value)
{
    uint8_t out_char = value;
    
    if (value >= 0x80) // UTF-8 handling
    {
        if (value >= 0xc0)
            utf_hi_char = value - 0xd0;
        else
        {
            value &= 0x3f;
            
            if (!utf_hi_char && value == 1)
                out_char = 0xa2; // Ё
            else if (utf_hi_char == 1 && value == 0x11)
                out_char = 0xb5; // ё
            else
                out_char = pgm_read_byte_near(utf_recode + value + (utf_hi_char << 6) - 0x10);

            LiquidCrystal::write(out_char);
        }    
    }
    else
        LiquidCrystal::write(out_char);
}
