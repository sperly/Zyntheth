#include "testmenu.hpp"
#include "config.hpp"
#include "ili9341_t3n_font_Arial.h"
#include "ili9341_t3n_font_ArialBold.h"
#include "gfx.hpp"

TestMenu::TestMenu(ValueContainer& valcon) : vc{valcon}
{
    for (int i = 0; i < ENCODERS * 2; i++)
    {
        parameterValues[i]     = 0;
        prevParameterValues[i] = 0;
    }
}

void TestMenu::Enter()
{
    drawMenu();
}

void TestMenu::HandleParameterChange(uint8_t parameter, int16_t value)
{
    if (parameter > ENCODERS - 1)
    {
        if (parameterValues[parameter] != prevParameterValues[parameter])
        {
            prevParameterValues[parameter] = parameterValues[parameter];
        }
    }
    else
    {
        parameterValues[parameter] += value;
    }

    Serial.printf("MainMenu::HandleParameterChange: par: %d, val: %d \n\r", parameter, value);
    vc.lcdHandler.setTextSize(14);
    vc.lcdHandler.setFont(Arial_14);
    if (parameter >= 1 && parameter <= 4)
    {
        if (parameterValues[parameter] < 0)
        {
            vc.lcdHandler.setTextColor(ILI9341_RED);
        }
        else
        {
            vc.lcdHandler.setTextColor(ILI9341_BLACK);
        }
        vc.lcdHandler.fillRect(10, 58 + (17 * (parameter - 1)), 300, 16, ILI9341_WHITE);
        vc.lcdHandler.setCursor(15, 59 + (17 * (parameter - 1)));
        vc.lcdHandler.printf("Pos %d: %d", parameter, parameterValues[parameter]);
    }
    else if (parameter >= ENCODERS && parameter < ENCODERS + ENCODERS)
    {
        vc.lcdHandler.fillRect(100, 58 + (17 * (parameter - ENCODERS - 1)), 300, 16, ILI9341_WHITE);
        vc.lcdHandler.setCursor(105, 59 + (17 * (parameter - ENCODERS - 1)));
        if (value == 1) vc.lcdHandler.printf("PRESSED");
    }
}

void TestMenu::drawMenu()
{
    Serial.printf("MainMenu::drawMenu \n\r");
    //GFX::DrawBMP("main.bmp", 0, 0, lcdHandler);
    vc.lcdHandler.fillRect(10, HEADER_HEIGHT + 1, 300, 200, ILI9341_WHITE);
    vc.lcdHandler.fillRect(HEADER_WIDTH, 4, 150, HEADER_HEIGHT - 6, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(16);
    vc.lcdHandler.setFont(Arial_16_Bold);

    vc.lcdHandler.setTextColor(ILI9341_BLUE);
    int width = vc.lcdHandler.strPixelLen("TEST", 4);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - 10 - width, HEADER_HEIGHT - 6 - 18);
    vc.lcdHandler.printf("TEST");

    vc.lcdHandler.setTextSize(14);
    vc.lcdHandler.setFont(Arial_14);

    for (int parameter = 1; parameter <= 4; parameter++)
    {
        if (parameterValues[parameter] < 0)
        {
            vc.lcdHandler.setTextColor(ILI9341_RED);
        }
        else
        {
            vc.lcdHandler.setTextColor(ILI9341_BLACK);
        }
        vc.lcdHandler.fillRect(10, 58 + (17 * (parameter - 1)), 300, 16, ILI9341_WHITE);
        vc.lcdHandler.setCursor(15, 59 + (17 * (parameter - 1)));
        vc.lcdHandler.printf("Pos %d: %d", parameter, parameterValues[parameter]);
    }
}
