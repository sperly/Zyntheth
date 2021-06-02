#include "oscmenu.hpp"
#include "config.hpp"
#include "font_Arial.h"
#include "font_ArialBold.h"
#include "gfx.hpp"

OscMenu::OscMenu(ValueContainer& valcon, uint8_t id) : vc{valcon}, oscid{id}
{
}

void OscMenu::Enter()
{
    drawMenu();
}

void OscMenu::HandleParameterChange(uint8_t parameter, int16_t value)
{
    Serial.printf("Osc[%d]Menu::HandleParameterChange: par: %d, val: %d \n\r", oscid, parameter, value);
    switch (parameter)
    {
        case 1: {
            if (value > 0 && vc.oscillator[oscid].waveform < WAVEFORMS - 1)
            {
                vc.oscillator[oscid].waveform++;
            }
            else if (value < 0 && vc.oscillator[oscid].waveform > 0)
            {
                vc.oscillator[oscid].waveform--;
            }
            Serial.printf("Osc.wave: %d\n\r", vc.oscillator[oscid].waveform);
            drawWaveform();
            break;
        }
        case 2: {
            if (value > 0)
            {
                vc.oscillator[oscid].amplitude += (float)(value / 20.0);
            }
            else
            {
                if (vc.oscillator[oscid].amplitude > 0.05)
                    vc.oscillator[oscid].amplitude += (float)(value / 20.0);
                else
                    vc.oscillator[oscid].amplitude = 0;
            }
            Serial.printf("Osc.amp: %.02f\n\r", vc.oscillator[oscid].amplitude);
            drawData();
            break;
        }
        case 3: {
            if (value > 0)
            {
                vc.oscillator[oscid].freqModulation += (float)(value / 20.0);
            }
            else
            {
                if (vc.oscillator[oscid].freqModulation > 0.05)
                    vc.oscillator[oscid].freqModulation += (float)(value / 20.0);
                else
                    vc.oscillator[oscid].freqModulation = 0;
            }
            Serial.printf("Osc.freqMod: %.02f\n\r", vc.oscillator[oscid].freqModulation);
            drawData();
            break;
        }
        case 4: {
            if (value > 0)
            {
                vc.oscillator[oscid].phase += (float)(value / 20.0);
            }
            else
            {
                if (vc.oscillator[oscid].phase > 0.05)
                    vc.oscillator[oscid].phase += (float)(value / 20.0);
                else
                    vc.oscillator[oscid].phase = 0;
            }
            Serial.printf("Osc.phase: %.02f\n\r", vc.oscillator[oscid].phase);
            drawData();
            break;
        }

        default: {
            break;
        }
    }
}

void OscMenu::drawMenu()
{
    Serial.printf("Osc[%d]Menu::drawMenu \n\r", oscid);
    drawHeader();
    vc.lcdHandler.fillRect(DATA_X, DATA_Y, DATA_VALUE_X - DATA_X, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(14);
    vc.lcdHandler.setFont(Arial_14_Bold);
    vc.lcdHandler.setTextColor(ILI9341_BLACK);
    vc.lcdHandler.setCursor(DATA_X, DATA_Y);
    vc.lcdHandler.printf("Ampl.:");
    vc.lcdHandler.setCursor(DATA_X, DATA_Y + DATA_SPACING);
    vc.lcdHandler.printf("Frq.Mod.:");
    vc.lcdHandler.setCursor(DATA_X, DATA_Y + (2 * DATA_SPACING));
    vc.lcdHandler.printf("Phase:");

    drawData();
    drawWaveform();
    drawFooter();
}

void OscMenu::drawHeader()
{
    vc.lcdHandler.fillRect(HEADER_WIDTH, 4, 150, HEADER_HEIGHT - 6, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(16);
    vc.lcdHandler.setFont(Arial_16_Bold);
    vc.lcdHandler.setTextColor(ILI9341_BLUE);
    int width = vc.lcdHandler.measureTextWidth("OSC X", 5);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - 10 - width, HEADER_HEIGHT - 6 - 18);
    vc.lcdHandler.printf("OSC %d", oscid + 1);
}

void OscMenu::drawData()
{
    vc.lcdHandler.fillRect(DATA_VALUE_X - 60, DATA_Y, 60, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(14);
    vc.lcdHandler.setFont(Arial_14_Bold);

    vc.lcdHandler.setTextColor(ILI9341_DARKGREY);
    int width = vc.lcdHandler.measureTextWidth("W.WW", 4);
    vc.lcdHandler.setCursor(DATA_VALUE_X + 5 - width, DATA_Y);
    vc.lcdHandler.printf("%.02f", vc.oscillator[oscid].amplitude);
    vc.lcdHandler.setCursor(DATA_VALUE_X + 5 - width, DATA_Y + DATA_SPACING);
    vc.lcdHandler.printf("%.02f", vc.oscillator[oscid].freqModulation);
    vc.lcdHandler.setCursor(DATA_VALUE_X + 5 - width, DATA_Y + (2 * DATA_SPACING));
    vc.lcdHandler.printf("%.02f", vc.oscillator[oscid].phase);
}

void OscMenu::drawWaveform()
{
    vc.lcdHandler.fillRect(DATA_VALUE_X, DATA_Y, vc.lcdHandler.width() - DATA_VALUE_X, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    switch (vc.oscillator[oscid].waveform)
    {
        case 0:
            GFX::DrawBMP("square.bmp", DATA_VALUE_X, DATA_Y, vc.lcdHandler);
            break;
        case 1:
            GFX::DrawBMP("sine.bmp", DATA_VALUE_X, DATA_Y, vc.lcdHandler);
            break;
        default:
            break;
    }
}

void OscMenu::drawFooter()
{
    vc.lcdHandler.fillRect(DATA_X, FOOTER_Y, vc.lcdHandler.width() - 10, FOOTER_Y + 20, ILI9341_WHITE);
    vc.lcdHandler.drawFastHLine(DATA_X, FOOTER_Y, vc.lcdHandler.width() - (2 * DATA_X), ILI9341_BLACK);

    GFX::DrawBMP("arrow_l.bmp", DATA_X, FOOTER_Y + 9, vc.lcdHandler);
    vc.lcdHandler.setCursor(DATA_X + 20, FOOTER_Y + 9);
    vc.lcdHandler.setTextColor(ILI9341_BLACK);
    vc.lcdHandler.printf("Osc. Contr.");

    GFX::DrawBMP("arrow_r.bmp", vc.lcdHandler.width() - 30, FOOTER_Y + 9, vc.lcdHandler);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - 35 - vc.lcdHandler.measureTextWidth("Filter", 6), FOOTER_Y + 9);
    vc.lcdHandler.setTextColor(ILI9341_BLACK);
    vc.lcdHandler.printf("Filter");
}
