#include "Arduino.h"
#include "ILI9341_t3.h"
#include "SD.h"
#include "config.hpp"
#include "encoder.hpp"
#include "mcp23s17.hpp"
#include "menuhandler.hpp"
#include "valuecontainer.hpp"

#define ENC_INT_A 24
#define CS_PIN 31

MCP23S17 gpio;

Encoder encoder[ENCODERS];
ValueContainer vc;

short lightState = 0;

MenuHandler menuHandler{};

void checkEncoders()
{
    uint8_t portA = gpio.ReadPortA();
    uint8_t portB = gpio.ReadPortB();
    uint16_t pos  = portA | ((uint16_t)portB << 8);

    for (int count = 0; count < 5; ++count)
    {
        vc.Controls.update[count] = encoder[count].PushState((char)((pos >> (count * 3)) & 0b00000011));
        if (vc.Controls.update[count])
        {
            vc.Controls.localSteps[count] += encoder[count].GetSteps();
            if (vc.Controls.localSteps[count] != 0)
                menuHandler.HandleMenuAction(count, vc.Controls.localSteps[count]);
            vc.Controls.localSteps[count] = 0;
        }

        uint8_t bPress = ((char)((pos >> (count * 3)) & 0b00000100) >> 2);
        if (bPress != vc.Controls.buttonpress[count])
        {
            Serial.printf("Button: %d - %d\n\r", count, bPress);
            menuHandler.HandleMenuAction(count + ENCODERS, bPress);
            vc.Controls.buttonpress[count] = bPress;
        }
    }
    uint8_t bPress = ((char)((pos >> 8) & 0b10000000) >> 7);
    if (bPress != vc.Controls.buttonpress[ENCODERS])
    {
        Serial.printf("Button: %d - %d\n\r", ENCODERS, bPress);
        menuHandler.HandleMenuAction(ENCODERS + ENCODERS, bPress);
        vc.Controls.buttonpress[ENCODERS] = bPress;
    }
}

void initValueContainer()
{
    for (int i = 0; i < ENCODERS; i++)
    {
        vc.Controls.localSteps[i] = 0;
        vc.Controls.lastSteps[i]  = 0;
        vc.Controls.update[i]     = false;
    }

    for (int i = 0; i < BUTTONS; i++)
    {
        vc.Controls.buttonpress[i] = 0;
    }

    for (int i = 0; i < OSCILLATORS; ++i)
    {
        vc.oscillator[i].waveform  = WAVEFORM_SINE;
        vc.oscillator[i].amplitude = 0.7;

        vc.oscillator[i].freqMod  = 0.0;
        vc.oscillator[i].phaseMod = 0.0;
        vc.oscillator[i].freq     = 0;
        vc.oscillator[i].delay    = DELAY_DEF;
        vc.oscillator[i].attack   = ATTACK_DEF;
        vc.oscillator[i].hold     = HOLD_DEF;
        vc.oscillator[i].decay    = DECAY_DEF;
        vc.oscillator[i].sustain  = SUSTAIN_DEF;
        vc.oscillator[i].release  = RELEASE_DEF;
    }
}

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    Serial.print("\n\r\n\r\n\rStarting ZYNTHETH...");

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

    Serial.println("Init of MCP23S17");
    gpio.Init(CS_PIN);
    gpio.SetPortDirection(PORT_A, PORT_INPUT);
    gpio.SetPortDirection(PORT_B, PORT_INPUT);
    //attachInterrupt(ENC_INT_A, ISR_EncIntA, FALLING);
    //lcd.setClock(60000000);
    vc.lcdHandler.begin();
    vc.lcdHandler.setRotation(1);
    vc.lcdHandler.fillScreen(ILI9341_WHITE);

    Serial.print("Initializing value container...");
    initValueContainer();

    menuHandler.Init(vc);
}

void loop()
{
    checkEncoders();

    // for (int i = 0; i < ENCODERS; ++i)
    // {
    //     if (0 != vc.localSteps[i])
    //     {
    //         menuHandler.HandleMenuAction(i, vc.localSteps[i]);
    //         vc.lastSteps[i] = 0;
    //         // vc.lastSteps[i] = vc.localSteps[i];
    //     }
    // }
}
