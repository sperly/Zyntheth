#include "SSD1322.hpp"

#define CS 14
#define DC 10

void SSD1322::writeByte(unsigned char Data)
{
    SPI1.beginTransaction(spiSettingsSSD1322);
    SPI1.transfer(Data);
    SPI1.endTransaction();
    delay(10);
}

void SSD1322::WriteCommand(unsigned char Data)
{
    digitalWrite(CS, LOW);
    digitalWrite(DC, LOW);
    writeByte(Data);
    digitalWrite(CS, HIGH);
    digitalWrite(DC, HIGH);
}
void SSD1322::WriteData(unsigned char Data)
{
    digitalWrite(CS, LOW);
    digitalWrite(DC, HIGH);
    writeByte(Data);
    digitalWrite(CS, HIGH);
}

void SSD1322::Init()
{
    WriteCommand(0xFD); /*SET COMMAND LOCK*/
    WriteData(0x12);    /* UNLOCK */
    WriteCommand(0xAE); /*DISPLAY OFF*/
    WriteCommand(0xB3); /*DIVIDE CLOCKRADIO/OSCILLATAR FREQUANCY*/
    WriteData(0x91);
    WriteCommand(0xCA); /*multiplex ratio*/
    WriteData(0x3F);    /*duty = 1/64*/
    WriteCommand(0xA2); /*set offset*/
    WriteData(0x00);
    WriteCommand(0xA1); /*start line*/
    WriteData(0x00);

    WriteCommand(0xA0); /*set remap*/
    WriteData(0x14);
    WriteData(0x11);
    /*WriteCommand(0xB5); //GPIO WriteCommand(0x00); */
    WriteCommand(0xAB); /*funtion selection*/
    WriteData(0x01);    /* selection external vdd */
    WriteCommand(0xB4); /* */
    WriteData(0xA0);
    WriteData(0xfd);
    WriteCommand(0xC1); /*set contrast current */
    WriteData(0x9f);
    WriteCommand(0xC7); /*master contrast current control*/
    WriteData(0x0f);
    /* WriteCommand(0xB9); GRAY TABLE*/
    WriteCommand(0xB1); /*SET PHASE LENGTH*/
    WriteData(0xE2);
    WriteCommand(0xD1); /**/
    WriteData(0x82);
    WriteData(0x20);
    WriteCommand(0xBB); /*SET PRE-CHANGE VOLTAGE*/
    WriteData(0x1F);
    WriteCommand(0xB6); /*SET SECOND PRE-CHARGE PERIOD*/
    WriteData(0x08);
    WriteCommand(0xBE); /* SET VCOMH */
    WriteData(0x07);
    WriteCommand(0xA6); /*normal display*/
    // clear();
    WriteCommand(0xAF); /*display ON*/
}

void SSD1322::Clear()
{
    unsigned char x, y;
    WriteCommand(0x15);
    WriteData(0x00);
    WriteData(0x77);

    WriteCommand(0x75);
    WriteData(0x00);
    WriteData(0x7f);
    WriteCommand(0x5C);
    for (y = 0; y < 128; y++)
    {
        for (x = 0; x < 120; x++)
        {
            WriteData(0x00);
            WriteData(0x00);
        }
    }
}

void SSD1322::Set_Column_Address(unsigned char a, unsigned char b)
{
    WriteCommand(0x15);
    WriteData(a); /*Default => 0x00*/
    WriteData(b); /*Default => 0x77*/
}

void SSD1322::Set_Row_Address(unsigned char a, unsigned char b)
{
    WriteCommand(0x75);
    WriteData(a); /*Default => 0x00 */
    WriteData(b); /*Default => 0x7F */
}

void SSD1322::Fill_Block(unsigned char Data, unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    unsigned char i, j;

    Set_Column_Address(0x1C + a, 0x1C + b);
    Set_Row_Address(c, d);
    WriteCommand(0x5C);
    for (i = 0; i < (d - c + 1); i++)
    {
        for (j = 0; j < (b - a + 1); j++)
        {
            WriteData(Data);
            WriteData(Data);
        }
    }
}

void SSD1322::Grayscale()
{
    /* Level 16 => Column 1~16 */
    Fill_Block(0xFF, 0x00, 0x03, 0x00, 0x3f);
    /* Level 15 => Column 17~32*/
    Fill_Block(0xEE, 0x04, 0x07, 0x00, 0x3f);
    /* Level 14 => Column 33~48*/
    Fill_Block(0xDD, 0x08, 0x0B, 0x00, 0x3f);
    /* Level 13 => Column 49~64*/
    Fill_Block(0xCC, 0x0C, 0x0F, 0x00, 0x3f);
    /* Level 12 => Column 65~80*/
    Fill_Block(0xBB, 0x10, 0x13, 0x00, 0x3f);
    /* Level 11 => Column 81~96*/
    Fill_Block(0xAA, 0x14, 0x17, 0x00, 0x3f);
    /* Level 10 => Column 97~112*/
    Fill_Block(0x99, 0x18, 0x1B, 0x00, 0x3f);
    /* Level 9 => Column 113~128*/
    Fill_Block(0x88, 0x1C, 0x1F, 0x00, 0x3f);
    /* Level 8 => Column 129~144*/
    Fill_Block(0x77, 0x20, 0x23, 0x00, 0x3f);
    /* Level 7 => Column 145~160*/
    Fill_Block(0x66, 0x24, 0x27, 0x00, 0x3f);
    /* Level 6 => Column 161~176*/
    Fill_Block(0x55, 0x28, 0x2B, 0x00, 0x3f);
    /* Level 5 => Column 177~192*/
    Fill_Block(0x44, 0x2C, 0x2F, 0x00, 0x3f);
    /* Level 4 => Column 193~208*/
    Fill_Block(0x33, 0x30, 0x33, 0x00, 0x3f);
    /* Level 3 => Column 209~224*/
    Fill_Block(0x22, 0x34, 0x37, 0x00, 0x3f);
    /* Level 2 => Column 225~240*/
    Fill_Block(0x11, 0x38, 0x3B, 0x00, 0x3f);
    /* Level 1 => Column 241~256*/
    Fill_Block(0x00, 0x3C, 0x3f, 0x00, 0x3f);
    delay(100);
}

//U8G2_SSD1322_NHD_256X64_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/10, /* dc=*/9, /* reset=*/8);  // Enable U8G2_16BIT in u8g2.h