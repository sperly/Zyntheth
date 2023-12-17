#pragma once

#include "Arduino.h"
#include "ILI9341_t3n.h"
#include "SdFat.h"
#include "valuecontainer.hpp"

#define BUFFPIXEL 80

class GFX
{
 public:
    static void DrawBMP(ValueContainer& vc, const char* filename, uint16_t x, uint16_t y, ILI9341_t3n& lcd);
    static void DrawButton(uint16_t x, uint16_t y, uint16_t width, uint16_t height, String text, uint8_t text_size, ILI9341_t3n& lcd);

 private:
    static uint16_t read16(FsFile& f);
    static uint32_t read32(FsFile& f);
};
