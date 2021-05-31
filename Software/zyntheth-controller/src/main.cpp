#include "Arduino.h"
#include "ILI9341_t3.h"
#include "SD.h"
#include "encoder.hpp"
#include "font_Arial.h"
#include "mcp23s17.hpp"
#include "splash.h"

#define ENC_INT_A 24
#define CS_PIN 31
#define ENCODERS 5

MCP23S17 gpio;
ILI9341_t3 lcd{15, 10, 16};

Encoder encoder[ENCODERS];
int localSteps[ENCODERS] = {0, 0, 0, 0, 0};
int lastSteps[ENCODERS]  = {0, 0, 0, 0, 0};
bool update[ENCODERS];
short lightState = 0;

void bmpDraw(const char *filename, uint8_t x, uint16_t y);
uint16_t read16(File &f);
uint32_t read32(File &f);

void checkEncoders()
{
    uint16_t pos = gpio.ReadPortA() | ((uint16_t)gpio.ReadPortB() << 8);

    for (int count = 0; count < 5; ++count)
    {
        update[count] = encoder[count].PushState((char)((pos >> (count * 3)) & 0x0003));
        if (update[count])
        {
            localSteps[count] += encoder[count].GetSteps();
            Serial.printf("| Steps (%d) = %d ", count, localSteps[count]);
        }
    }
}

// void ISR_EncIntA()
// {
//     cli();
//     Serial.println("At ISR0");
//     delay(6);
//     char pos = gpio.ReadPortA();
//     encoder.PushState((pos & 0b00000011));
//     loaclSteps += encoder.GetSteps();
//     if ((pos & 0b00000100) == 0b00000100)
//     {
//         gpio.SetPin(PORT_B, 1, lightState);
//         lightState = (lightState ? 0 : 1);
//     }
//     char ints = gpio.GetIntStatus(PORT_A);
//     Serial.printf("Steps = %d (int=0x%02X)", loaclSteps, ints);
//     sei();
// }

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    for (int count = 0; count < 5; ++count)
    {
        encoder[count] = Encoder();
        encoder[count].Reset();
    }

    Serial.print("Initializing SD card...");

    if (!SD.begin(BUILTIN_SDCARD))
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");

    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");

    Serial.println("Init of MCP23S17");
    gpio.Init(CS_PIN);
    gpio.SetPortDirection(PORT_A, PORT_INPUT);
    gpio.SetPortDirection(PORT_B, PORT_INPUT);
    //attachInterrupt(ENC_INT_A, ISR_EncIntA, FALLING);
    //lcd.setClock(1000000);
    lcd.begin();
    lcd.setRotation(1);
    //delay(100);
    lcd.fillScreen(ILI9341_BLACK);
    //lcd.writeRect(0, 0, 320, 240, splash);
    //delay(2000);
    bmpDraw("splash.bmp", 0, 0);
    delay(3000);
    bmpDraw("main.bmp", 0, 0);
    //char data = gpio.ReadPortA();
    //Serial.printf("Start with 0x%02X on the port A\n\r", data);
    //data = gpio.ReadPortB();
    //Serial.printf("Start with 0x%02X on the port B\n\r", data);
    lcd.setTextColor(ILI9341_BLACK);
    lcd.setTextSize(14);
    lcd.setFont(Arial_14);
    for (int i = 0; i < ENCODERS; ++i)
    {
        lastSteps[i] = localSteps[i];
        lcd.fillRect(10, 58 + (17 * i), 300, 16, ILI9341_WHITE);
        lcd.setCursor(15, 59 + (17 * i));
        lcd.printf("Pos %d: %d", i + 1, localSteps[i]);
    }
}

void loop()
{
    checkEncoders();

    for (int i = 0; i < ENCODERS; ++i)
    {
        if (lastSteps[i] != localSteps[i])
        {
            if (localSteps[i] < 0)
            {
                lcd.setTextColor(ILI9341_RED);
            }
            else
            {
                lcd.setTextColor(ILI9341_BLACK);
            }
            lastSteps[i] = localSteps[i];
            lcd.fillRect(10, 58 + (17 * i), 300, 16, ILI9341_WHITE);
            lcd.setCursor(15, 59 + (17 * i));
            lcd.printf("Pos %d: %d", i + 1, localSteps[i]);
        }
    }
    //gpio.WritePortB(0xff);
    //delay(5);
    //gpio.WritePortB(0x00);
    //char data = gpio.ReadPortA();
    //Serial.printf("Read 0x%02X on the A port\n\r", data);
    //delay(500);
}

// Serial.print("Initializing SD card...");

//   if (!SD.begin(chipSelect)) {
//     Serial.println("initialization failed!");
//     return;
//   }
//   Serial.println("initialization done.");

//   // open the file.
//   myFile = SD.open("test.txt", FILE_WRITE);

//   // if the file opened okay, write to it:
//   if (myFile) {
//     Serial.print("Writing to test.txt...");
//     myFile.println("testing 1, 2, 3.");
// 	// close the file:
//     myFile.close();
//     Serial.println("done.");
//   } else {
//     // if the file didn't open, print an error:
//     Serial.println("error opening test.txt");
//   }

//   // re-open the file for reading:
//   myFile = SD.open("test.txt");
//   if (myFile) {
//     Serial.println("test.txt:");

//     // read from the file until there's nothing else in it:
//     while (myFile.available()) {
//     	Serial.write(myFile.read());
//     }
//     // close the file:
//     myFile.close();
//   } else {
//   	// if the file didn't open, print an error:
//     Serial.println("error opening test.txt");
//   }

#define BUFFPIXEL 80

//===========================================================
// Try Draw using writeRect
void bmpDraw(const char *filename, uint8_t x, uint16_t y)
{
    File bmpFile;
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

    Serial.println();
    Serial.print(F("Loading image '"));
    Serial.print(filename);
    Serial.println('\'');

    // Open requested file on SD card
    if (!(bmpFile = SD.open(filename)))
    {
        Serial.print(F("File not found"));
        return;
    }

    // Parse BMP header
    if (read16(bmpFile) == 0x4D42)
    {  // BMP signature
        Serial.print(F("File size: "));
        Serial.println(read32(bmpFile));
        (void)read32(bmpFile);             // Read & ignore creator bytes
        bmpImageoffset = read32(bmpFile);  // Start of image data
        Serial.print(F("Image Offset: "));
        Serial.println(bmpImageoffset, DEC);
        // Read DIB header
        Serial.print(F("Header size: "));
        Serial.println(read32(bmpFile));
        bmpWidth  = read32(bmpFile);
        bmpHeight = read32(bmpFile);
        if (read16(bmpFile) == 1)
        {                                // # planes -- must be '1'
            bmpDepth = read16(bmpFile);  // bits per pixel
            Serial.print(F("Bit Depth: "));
            Serial.println(bmpDepth);
            if ((bmpDepth == 24) && (read32(bmpFile) == 0))
            {  // 0 = uncompressed

                goodBmp = true;  // Supported BMP format -- proceed!
                Serial.print(F("Image size: "));
                Serial.print(bmpWidth);
                Serial.print('x');
                Serial.println(bmpHeight);

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
                    lcd.writeRect(0, row, w, 1, awColors);
                }  // end scanline
                Serial.print(F("Loaded in "));
                Serial.print(millis() - startTime);
                Serial.println(" ms");
            }  // end goodBmp
        }
    }

    bmpFile.close();
    if (!goodBmp) Serial.println(F("BMP format not recognized."));
}

// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.

uint16_t read16(File &f)
{
    uint16_t result;
    ((uint8_t *)&result)[0] = f.read();  // LSB
    ((uint8_t *)&result)[1] = f.read();  // MSB
    return result;
}

uint32_t read32(File &f)
{
    uint32_t result;
    ((uint8_t *)&result)[0] = f.read();  // LSB
    ((uint8_t *)&result)[1] = f.read();
    ((uint8_t *)&result)[2] = f.read();
    ((uint8_t *)&result)[3] = f.read();  // MSB
    return result;
}