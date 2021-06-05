#include "oscmain.hpp"
#include "config.hpp"
#include "gfx.hpp"
#include "ili9341_t3n_font_Arial.h"
#include "ili9341_t3n_font_ArialBold.h"
#include "log.hpp"


OscMain::OscMain(ValueContainer& valcon) : vc{valcon}
{
}

void OscMain::Enter()
{
    drawMenu();
}

void OscMain::HandleParameterChange(uint8_t parameter, int16_t value)
{
    LOG_DEBUG("par: %d, val: %d", parameter, value);
    if (value > 0)
    {
        vc.oscillator[parameter - 1].enabled = 1;
    }
    else
    {
        vc.oscillator[parameter - 1].enabled = 0;
    }
    LOG_DEBUG("Osc[%d].enabled: %d", parameter, vc.oscillator[parameter - 1].enabled);
    drawData();
}

void OscMain::drawMenu()
{
    LOG_DEBUG("OscMain::drawMenu");
    drawHeader();
    drawData();
    drawFooter();
}

void OscMain::drawHeader()
{
    vc.lcdHandler.fillRect(HEADER_WIDTH, 4, 150, HEADER_HEIGHT - 6, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(16);
    vc.lcdHandler.setFont(Arial_16_Bold);
    vc.lcdHandler.setTextColor(ILI9341_BLUE);
    int width = vc.lcdHandler.strPixelLen("OSC MAIN", 8);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - 10 - width, HEADER_HEIGHT - 6 - 18);
    vc.lcdHandler.printf("OSC MAIN");
}

void OscMain::drawData()
{
    vc.lcdHandler.fillRect(DATA_VALUE_X, DATA_Y, vc.lcdHandler.width() - DATA_VALUE_X, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    vc.lcdHandler.fillRect(DATA_X, DATA_Y, DATA_VALUE_X - DATA_X, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(14);
    vc.lcdHandler.setFont(Arial_14_Bold);
    vc.lcdHandler.setTextColor(ILI9341_DARKGREY);
    for (int i = 0; i < OSCILLATORS; ++i)
    {
        vc.lcdHandler.setCursor(DATA_X, DATA_Y + (DATA_SPACING * i));
        vc.lcdHandler.setTextColor(ILI9341_BLACK);
        vc.lcdHandler.printf("O%d Enabled:", i + 1);
        vc.lcdHandler.setTextColor(ILI9341_DARKGREY);
        int width = vc.lcdHandler.strPixelLen("W", 1);
        vc.lcdHandler.setCursor(DATA_VALUE_X + 5 - width, DATA_Y + (DATA_SPACING * i));
        vc.lcdHandler.printf("%s", (vc.oscillator[i].enabled == 1 ? "X" : "-"));
    }
}

void OscMain::drawFooter()
{
    vc.lcdHandler.setTextSize(14);
    vc.lcdHandler.setFont(Arial_14_Bold);

    vc.lcdHandler.fillRect(DATA_X, FOOTER_Y, vc.lcdHandler.width() - 10, FOOTER_Y + 20, ILI9341_WHITE);
    vc.lcdHandler.drawFastHLine(DATA_X, FOOTER_Y, vc.lcdHandler.width() - (2 * DATA_X), ILI9341_BLACK);

    // GFX::DrawBMP("arrow_l.bmp", DATA_X, FOOTER_Y + 9, vc.lcdHandler);
    // vc.lcdHandler.setCursor(DATA_X + 20, FOOTER_Y + 9);
    // vc.lcdHandler.setTextColor(ILI9341_BLACK);
    // vc.lcdHandler.printf("Oscillator");

    GFX::DrawBMP("arrow_r.bmp", vc.lcdHandler.width() - 30, FOOTER_Y + 9, vc.lcdHandler);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - 35 - vc.lcdHandler.strPixelLen("Oscillators", 11), FOOTER_Y + 9);
    vc.lcdHandler.setTextColor(ILI9341_BLACK);
    vc.lcdHandler.printf("Oscillators");
}