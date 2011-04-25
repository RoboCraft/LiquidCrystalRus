/* This is header file for LiquidCrystalRus library which adds support
 * for cyrillic characters to LiquidCrystal library for Arduino.
 * It's been originally developed by Ilya Danilov
 * (http://www.blogger.com/profile/11932466603117832284),
 * and was rewritten to support modern versions of LiquidCrystal.
 *
 * (C) 2011 Artyom Borisovskiy, bytefu@gmail.com
 */

#ifndef LIQUIDCRYSTALRUS_H
#define LIQUIDCRYSTALRUS_H

#include <inttypes.h>

class LiquidCrystalRus : public LiquidCrystal
{
public:
    LiquidCrystalRus(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
        LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)
    {
    }
    
    LiquidCrystalRus(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
        LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
    {
    }
    
    LiquidCrystalRus(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
        LiquidCrystal(rs, rw, enable, d0, d1, d2, d3)
    {
    }
    
    LiquidCrystalRus(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
        LiquidCrystal(rs, enable, d0, d1, d2, d3)
    {
    }

    virtual void write(uint8_t);
  
private:
    uint8_t utf_hi_char; // UTF-8 high part
};

#endif // LIQUIDCRYSTALRUS_H
