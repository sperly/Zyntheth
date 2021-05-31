#pragma once

#include <SPI.h>

class SSD1322
{
 public:
    void Init();
    void WriteCommand(unsigned char Data);
    void WriteData(unsigned char Data);
    void Clear();
    void Set_Column_Address(unsigned char a, unsigned char b);
    void Set_Row_Address(unsigned char a, unsigned char b);
    void Fill_Block(unsigned char Data, unsigned char a, unsigned char b, unsigned char c, unsigned char d);
    void Grayscale();

 private:
    void writeByte(unsigned char Data);

    SPISettings spiSettingsSSD1322{1000000, MSBFIRST, SPI_MODE0};
};
