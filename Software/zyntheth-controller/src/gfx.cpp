#include "gfx.hpp"
#include "ili9341_t3n_font_Arial.h"
#include "ili9341_t3n_font_ArialBold.h"
#include "log.hpp"

struct point
{
    uint8_t x;
    uint8_t y;
};

point corner[5] = {{4, 1}, {3, 1}, {2, 2}, {1, 3}, {1, 4}};

void GFX::DrawBMP(const char *filename, uint16_t x, uint16_t y, ILI9341_t3n &lcd)
{
    File bmpFile;
    uint32_t size;
    int bmpWidth, bmpHeight;              // W+H in pixels
    uint8_t bmpDepth;                     // Bit depth (currently must be 24)
    uint32_t bmpImageoffset;              // Start of image data in file
    uint32_t rowSize;                     // Not always = bmpWidth; may have padding
    uint8_t sdbuffer[3 * BUFFPIXEL];      // pixel buffer (R+G+B per pixel)
    uint16_t buffidx = sizeof(sdbuffer);  // Current position in sdbuffer
    boolean goodBmp  = false;             // Set to true on valid header parse
    boolean flip     = true;              // BMP is stored bottom-to-top
    int w, h, row, col;
    uint8_t r, g, b;
    uint32_t pos = 0, startTime = millis();

    uint16_t awColors[320];  // hold colors for one row at a time...

    if ((x >= lcd.width()) || (y >= lcd.height())) return;

    LOG_INFO("Loading image '%s'", filename);

    // Open requested file on SD card
    if (!(bmpFile = SD.open(filename)))
    {
        LOG_ERROR("File not found");
        return;
    }

    // Parse BMP header
    if (read16(bmpFile) == 0x4D42)
    {  // BMP signature
        size = read32(bmpFile);
        (void)read32(bmpFile);             // Read & ignore creator bytes
        bmpImageoffset = read32(bmpFile);  // Start of image data
        // Read DIB header
        (void)read32(bmpFile);
        bmpWidth  = read32(bmpFile);
        bmpHeight = read32(bmpFile);
        if (read16(bmpFile) == 1)
        {                                // # planes -- must be '1'
            bmpDepth = read16(bmpFile);  // bits per pixel
            if ((bmpDepth == 24) && (read32(bmpFile) == 0))
            {  // 0 = uncompressed

                goodBmp = true;  // Supported BMP format -- proceed!

                // BMP rows are padded (if needed) to 4-byte boundary
                rowSize = (bmpWidth * 3 + 3) & ~3;

                // If bmpHeight is negative, image is in top-down order.
                // This is not canon but has been observed in the wild.
                if (bmpHeight < 0)
                {
                    bmpHeight = -bmpHeight;
                    flip      = false;
                }

                // Crop area to be loaded
                w = bmpWidth;
                h = bmpHeight;
                if ((x + w - 1) >= lcd.width()) w = lcd.width() - x;
                if ((y + h - 1) >= lcd.height()) h = lcd.height() - y;

                for (row = 0; row < h; row++)
                {  // For each scanline...

                    // Seek to start of scan line.  It might seem labor-
                    // intensive to be doing this on every line, but this
                    // method covers a lot of gritty details like cropping
                    // and scanline padding.  Also, the seek only takes
                    // place if the file position actually needs to change
                    // (avoids a lot of cluster math in SD library).
                    if (flip)  // Bitmap is stored bottom-to-top order (normal BMP)
                        pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
                    else  // Bitmap is stored top-to-bottom
                        pos = bmpImageoffset + row * rowSize;
                    if (bmpFile.position() != pos)
                    {  // Need seek?
                        bmpFile.seek(pos);
                        buffidx = sizeof(sdbuffer);  // Force buffer reload
                    }

                    for (col = 0; col < w; col++)
                    {  // For each pixel...
                        // Time to read more pixel data?
                        if (buffidx >= sizeof(sdbuffer))
                        {  // Indeed
                            bmpFile.read(sdbuffer, sizeof(sdbuffer));
                            buffidx = 0;  // Set index to beginning
                        }

                        // Convert pixel from BMP to lcd format, push to display
                        b             = sdbuffer[buffidx++];
                        g             = sdbuffer[buffidx++];
                        r             = sdbuffer[buffidx++];
                        awColors[col] = lcd.color565(r, g, b);
                    }  // end pixel
                    lcd.writeRect(x, y + row, w, 1, awColors);
                }  // end scanline
            }      // end goodBmp
        }
    }

    bmpFile.close();
    if (!goodBmp)
        LOG_ERROR("BMP format not recognized.");
    else
        LOG_INFO("BMP Size: %d, x: %d, y: %d, bitdepth: %d, time to read: %dms", size, bmpWidth, bmpHeight, bmpDepth, millis() - startTime);
}

void GFX::DrawButton(uint16_t x, uint16_t y, uint16_t width, uint16_t height, String text, uint8_t text_size, ILI9341_t3n &lcd)
{
    lcd.drawFastHLine(x + 5, y, width - 10, ILI9341_BLACK);
    lcd.drawFastHLine(x + 5, y + height, width - 10, ILI9341_BLACK);
    lcd.drawFastVLine(x, y + 5, height - 10, ILI9341_BLACK);
    lcd.drawFastVLine(x + width, y + 5, height - 10, ILI9341_BLACK);
    for (uint8_t i = 0; i <= 5; ++i)
    {
        lcd.drawPixel(x + corner[i].x, y + corner[i].y, ILI9341_BLACK);
        lcd.drawPixel(x + width - corner[i].x, y + corner[i].y, ILI9341_BLACK);
        lcd.drawPixel(x + corner[i].x, y + height - corner[i].y, ILI9341_BLACK);
        lcd.drawPixel(x + width - corner[i].x, y + height - corner[i].y, ILI9341_BLACK);
    }

    //Filling
    lcd.drawFastHLine(x + 5, y + 1, width - 10, ILI9341_LIGHTGREY);
    lcd.drawFastHLine(x + 5, y + height - 1, width - 10, ILI9341_LIGHTGREY);
    lcd.drawFastHLine(x + 3, y + 2, width - 6, ILI9341_LIGHTGREY);
    lcd.drawFastHLine(x + 3, y + height - 2, width - 6, ILI9341_LIGHTGREY);
    lcd.drawFastHLine(x + 2, y + 3, width - 8, ILI9341_LIGHTGREY);
    lcd.drawFastHLine(x + 2, y + height - 3, width - 4, ILI9341_LIGHTGREY);
    lcd.drawFastHLine(x + 2, y + 4, width - 8, ILI9341_LIGHTGREY);
    lcd.drawFastHLine(x + 2, y + height - 4, width - 4, ILI9341_LIGHTGREY);

    for (uint8_t i = y + 5; i <= y + height - 5; ++i)
    {
        lcd.drawFastHLine(x + 1, i, width - 2, ILI9341_LIGHTGREY);
    }

    lcd.setTextSize(12);
    lcd.setFont(Arial_12_Bold);
    lcd.setTextColor(ILI9341_DARKGREY);
    int text_width = lcd.strPixelLen(text.c_str());
    int text_pos_x = x + ((width - text_width) / 2);
    int text_pos_y = y + ((height - 12) / 2);
    lcd.setCursor(text_pos_x, text_pos_y);
    lcd.printf("%s", text.c_str());
    LOG_DEBUG("Button x:%d, y:%d w: %d, h:%d - Text x:%d, y:%d, w:%d, h:%d", x, y, width, height, text_pos_x, text_pos_y, text_width, 12);
}

// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.
uint16_t GFX::read16(File &f)
{
    uint16_t result;
    ((uint8_t *)&result)[0] = f.read();  // LSB
    ((uint8_t *)&result)[1] = f.read();  // MSB
    return result;
}

uint32_t GFX::read32(File &f)
{
    uint32_t result;
    ((uint8_t *)&result)[0] = f.read();  // LSB
    ((uint8_t *)&result)[1] = f.read();
    ((uint8_t *)&result)[2] = f.read();
    ((uint8_t *)&result)[3] = f.read();  // MSB
    return result;
}