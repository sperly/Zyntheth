#pragma once

#include "Arduino.h"
#include "ILI9341_t3.h"
#include "SD.h"

#define BUFFPIXEL 80

class GFX
{
 public:
    static void DrawBMP(const char* filename, uint16_t x, uint16_t y, ILI9341_t3& lcd);

 private:
    static uint16_t read16(File& f);
    static uint32_t read32(File& f);
};
