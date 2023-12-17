#include <XPT2046_Touchscreen.h>
#include "Arduino.h"
#include "ILI9341_t3n.h"
#include "Metro.h"
#include "SdFat.h"
#include "com/com.hpp"
#include "config.hpp"
#include "encoder.hpp"
#include "log.hpp"
#include "mcp23s17.hpp"
#include "menuhandler.hpp"
#include "valuecontainer.hpp"

#define ENC_INT_A 24
#define CS_PIN 31

MCP23S17 gpio;

#define TCS_PIN 9
#define TIRQ_PIN 8
XPT2046_Touchscreen ts(TCS_PIN, TIRQ_PIN);

Encoder encoder[ENCODERS];
ValueContainer vc{};

short lightState      = 0;
short lcdBackLightPin = 24;

MenuHandler menuHandler{};

Metro sleepTimer = Metro(LCD_TIMEOUT);
bool sleeping    = false;

bool signalsChanged = false;

Com com{vc};

#define SD_FAT_TYPE 3
//const uint8_t SD_CS_PIN = SDCARD_SS_PIN;
#define SPI_CLOCK SD_SCK_MHZ(50)
#define SD_CONFIG SdioConfig(FIFO_SDIO)

void resetSleepTimer()
{
    if (sleeping == true)
    {
        digitalWrite(lcdBackLightPin, HIGH);
        vc.lcdHandler.sleep(false);
        sleeping = false;
        sleepTimer.reset();
        LOG_DEBUG("LCD Wake Up");
    }
    else
    {
        sleepTimer.reset();
    }
}

void checkEncoders()
{
    uint8_t portA = gpio.ReadPortA();
    uint8_t portB = gpio.ReadPortB();
    uint16_t pos  = portA | ((uint16_t)portB << 8);

    bool updated = false;

    for (int count = 0; count < 5; ++count)
    {
        vc.Controls.update[count] = encoder[count].PushState((char)((pos >> (count * 3)) & 0b00000011));
        if (vc.Controls.update[count])
        {
            vc.Controls.localSteps[count] += encoder[count].GetSteps();
            if (vc.Controls.localSteps[count] != 0)
            {
                menuHandler.HandleMenuAction(count, vc.Controls.localSteps[count]);
                updated = true;
            }
            vc.Controls.localSteps[count] = 0;
        }

        uint8_t bPress = ((char)((pos >> (count * 3)) & 0b00000100) >> 2);
        if (bPress != vc.Controls.buttonpress[count])
        {
            LOG_DEBUG("Encoder", "Button: %d - %d", count, bPress);
            menuHandler.HandleMenuAction(count + ENCODERS, bPress);
            vc.Controls.buttonpress[count] = bPress;
            updated                        = true;
        }
    }
    uint8_t bPress = ((char)((pos >> 8) & 0b10000000) >> 7);
    if (bPress != vc.Controls.buttonpress[ENCODERS])
    {
        LOG_DEBUG("Encoder", "Button: %d - %d", ENCODERS, bPress);
        menuHandler.HandleMenuAction(ENCODERS + ENCODERS, bPress);
        vc.Controls.buttonpress[ENCODERS] = bPress;
        updated                           = true;
    }

    if (updated)
    {
        signalsChanged = true;
        resetSleepTimer();
    }
}

void setup()
{
    Serial.begin(115200);
    // while (!Serial)
    //     ;

    Serial.printf("\n\r\n\r\n\r");
    LOG_DEBUG("Starting ZYNTHETH...");

    for (int count = 0; count < 5; ++count)
    {
        encoder[count] = Encoder();
        encoder[count].Reset();
    }

    LOG_DEBUG("Initializing SD...");

    // if (!SD.begin(BUILTIN_SDCARD))
    // {
    //     LOG_DEBUG("... initialization failed!");
    //     return;
    // }

    if (!vc.sd.begin(SD_CONFIG))
    {
        //sd.initErrorHalt(&Serial);
        LOG_DEBUG("... initialization failed!");
        return;
    }

    LOG_DEBUG("... initialization done!");

    gpio.Init(CS_PIN);
    gpio.SetPortDirection(PORT_A, PORT_INPUT);
    gpio.SetPortDirection(PORT_B, PORT_INPUT);
    //attachInterrupt(ENC_INT_A, ISR_EncIntA, FALLING);

    LOG_DEBUG("Initializing LCD...");
    pinMode(lcdBackLightPin, OUTPUT);
    digitalWrite(lcdBackLightPin, LOW);

    vc.lcdHandler.begin();
    vc.lcdHandler.setRotation(1);
    vc.lcdHandler.fillScreen(ILI9341_WHITE);

    ts.begin();
    ts.setRotation(1);
    LOG_DEBUG("Initialization LCD done.");

    menuHandler.Init(vc);
    digitalWrite(lcdBackLightPin, HIGH);
    sleepTimer.reset();

    LOG_DEBUG("Initializing CAN...");
    Can0.begin(1000000);
    LOG_DEBUG("Initialization CAN done.");
}

void loop()
{
    checkEncoders();
    if (!sleeping && sleepTimer.check())
    {
        vc.lcdHandler.sleep(true);
        digitalWrite(lcdBackLightPin, LOW);
        sleeping = true;
        LOG_DEBUG("LCD Sleep");
    }
    if (signalsChanged)
    {
        com.Send();
        signalsChanged = false;
    }

    if (ts.tirqTouched())
    {
        if (ts.touched())
        {
            resetSleepTimer();
            TS_Point p = ts.getPoint();
            Serial.print("Pressure = ");
            Serial.print(p.z);
            Serial.print(", x = ");
            Serial.print(p.x);
            Serial.print(", y = ");
            Serial.print(p.y);
            delay(30);
            Serial.println();
        }
    }
}
