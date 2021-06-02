#include "adsr.hpp"
#include "config.hpp"
#include "font_Arial.h"
#include "font_ArialBold.h"
#include "gfx.hpp"

ADSR::ADSR(ValueContainer& valcon, uint8_t id) : vc{valcon}, oscid{id}
{
}

void ADSR::Enter()
{
    drawMenu();
}

void ADSR::HandleParameterChange(uint8_t parameter, int16_t value)
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
            break;
        }

        default: {
            break;
        }
            drawFilter();
    }
}

void ADSR::drawMenu()
{
    Serial.printf("Osc[%d]Menu::drawMenu \n\r", oscid);
    drawHeader();
    // vc.lcdHandler.fillRect(DATA_X, DATA_Y, DATA_VALUE_X - DATA_X, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    // vc.lcdHandler.setTextSize(14);
    // vc.lcdHandler.setFont(Arial_14_Bold);
    // vc.lcdHandler.setTextColor(ILI9341_BLACK);
    // vc.lcdHandler.setCursor(DATA_X, DATA_Y);
    // vc.lcdHandler.printf("Ampl.:");
    // vc.lcdHandler.setCursor(DATA_X, DATA_Y + DATA_SPACING);
    // vc.lcdHandler.printf("Frq.Mod.:");
    // vc.lcdHandler.setCursor(DATA_X, DATA_Y + (2 * DATA_SPACING));
    // vc.lcdHandler.printf("Phase:");

    drawData();
    drawFilter();
    drawFooter();
}

void ADSR::drawHeader()
{
    vc.lcdHandler.fillRect(HEADER_WIDTH, 4, 150, HEADER_HEIGHT - 6, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(16);
    vc.lcdHandler.setFont(Arial_16_Bold);
    vc.lcdHandler.setTextColor(ILI9341_BLUE);
    int width = vc.lcdHandler.measureTextWidth("ADSR X", 6);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - 10 - width, HEADER_HEIGHT - 6 - 18);
    vc.lcdHandler.printf("ADSR %d", oscid + 1);
}

void ADSR::drawData()
{
    // vc.lcdHandler.fillRect(DATA_VALUE_X - 60, DATA_Y, 60, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    // vc.lcdHandler.setTextSize(14);
    // vc.lcdHandler.setFont(Arial_14_Bold);

    // vc.lcdHandler.setTextColor(ILI9341_DARKGREY);
    // int width = vc.lcdHandler.measureTextWidth("W.WW", 4);
    // vc.lcdHandler.setCursor(DATA_VALUE_X + 5 - width, DATA_Y);
    // vc.lcdHandler.printf("%.02f", vc.oscillator[oscid].amplitude);
    // vc.lcdHandler.setCursor(DATA_VALUE_X + 5 - width, DATA_Y + DATA_SPACING);
    // vc.lcdHandler.printf("%.02f", vc.oscillator[oscid].freqModulation);
    // vc.lcdHandler.setCursor(DATA_VALUE_X + 5 - width, DATA_Y + (2 * DATA_SPACING));
    // vc.lcdHandler.printf("%.02f", vc.oscillator[oscid].phase);
}

void ADSR::drawFilter()
{
    // Height 140, Width 290
    vc.lcdHandler.fillRect(DATA_X, DATA_Y, vc.lcdHandler.width() - DATA_X - DATA_X, FOOTER_Y - DATA_Y, ILI9341_WHITE);

    int length = vc.oscillator->attack + vc.oscillator->decay + vc.oscillator->release;
}

void ADSR::drawFooter()
{
    vc.lcdHandler.fillRect(DATA_X, FOOTER_Y, vc.lcdHandler.width() - 10, FOOTER_Y + 20, ILI9341_WHITE);
    vc.lcdHandler.drawFastHLine(DATA_X, FOOTER_Y, vc.lcdHandler.width() - (2 * DATA_X), ILI9341_BLACK);

    GFX::DrawBMP("arrow_l.bmp", DATA_X, FOOTER_Y + 9, vc.lcdHandler);
    vc.lcdHandler.setCursor(DATA_X + 20, FOOTER_Y + 9);
    vc.lcdHandler.setTextColor(ILI9341_BLACK);
    vc.lcdHandler.printf("Oscillator");

    // GFX::DrawBMP("arrow_r.bmp", vc.lcdHandler.width() - 30, FOOTER_Y + 9, vc.lcdHandler);
    // vc.lcdHandler.setCursor(vc.lcdHandler.width() - 35 - vc.lcdHandler.measureTextWidth("Filter", 6), FOOTER_Y + 9);
    // vc.lcdHandler.setTextColor(ILI9341_BLACK);
    // vc.lcdHandler.printf("Filter");
}
