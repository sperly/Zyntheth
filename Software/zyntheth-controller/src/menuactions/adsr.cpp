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
    Serial.printf("ADSR[%d]::HandleParameterChange: par: %d, val: %d \n\r", oscid, parameter, value);
    switch (parameter)
    {
        case 1: {
            if ((value < 0 && vc.oscillator[oscid].attack > ATTACK_MIN) || (value > 0 && vc.oscillator[oscid].attack < ATTACK_MAX))
            {
                vc.oscillator[oscid].attack += (float_t)((float_t)value / 2.0);
                Serial.printf("Osc.attack: %.02fms\n\r", vc.oscillator[oscid].attack);
            }
            break;
        }
        case 2: {
            if ((value < 0 && vc.oscillator[oscid].decay > DECAY_MIN) || (value > 0 && vc.oscillator[oscid].decay < DECAY_MAX))
            {
                vc.oscillator[oscid].decay += (float_t)((float_t)value / 2.0);
                Serial.printf("Osc.decay: %.02fms\n\r", vc.oscillator[oscid].decay);
            }
            break;
        }
        case 3: {
            if ((value < 0 && vc.oscillator[oscid].sustain > SUSTAIN_MIN) || (value > 0 && vc.oscillator[oscid].sustain < SUSTAIN_MAX))
            {
                vc.oscillator[oscid].sustain += (float_t)((float_t)value / 200.0);
                Serial.printf("Osc.sustain: %.02f%%\n\r", vc.oscillator[oscid].sustain);
            }
            break;
        }
        case 4: {
            if ((value < 0 && vc.oscillator[oscid].release > RELEASE_MIN) || (value > 0 && vc.oscillator[oscid].release < RELEASE_MAX))
            {
                vc.oscillator[oscid].release += (float_t)((float_t)value / 2.0);
                Serial.printf("Osc.release: %.02fms\n\r", vc.oscillator[oscid].release);
            }
            break;
        }

        default: {
            break;
        }
    }
    drawFilter();
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

    drawFilter();
    drawData();
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
    vc.lcdHandler.fillRect(DATA_X, DATA_Y, vc.lcdHandler.width() - DATA_X - DATA_X + 1, FOOTER_Y - DATA_Y, ILI9341_WHITE);

    struct adsr filter;

    int y_size = (FOOTER_Y - DATA_Y - 10) - (DATA_Y + 10);
    int x_size = (vc.lcdHandler.width() - DATA_X - DATA_X);
    Serial.printf("ADSR: a:%.02fms d:%.02fms s:%.02f%% r:%.02fms\n\r", vc.oscillator[oscid].attack, vc.oscillator[oscid].decay, vc.oscillator[oscid].sustain, vc.oscillator[oscid].release);
    float_t length = (vc.oscillator[oscid].attack + vc.oscillator[oscid].decay + vc.oscillator[oscid].release) * (float_t)(1.30);
    Serial.printf("ADSR: length=%.02f", length);
    float_t step_length = (float_t)((float_t)x_size / length);
    Serial.printf(" - step_length=%.02f\n\r", step_length);

    filter.attack.start = {.x = DATA_X, .y = FOOTER_Y - DATA_Y - 10};
    filter.attack.stop  = {.x = DATA_X + (uint16_t)(step_length * vc.oscillator[oscid].attack), .y = DATA_Y + 10};
    filter.decay.stop   = {.x = DATA_X + (uint16_t)(step_length * (vc.oscillator[oscid].decay + vc.oscillator[oscid].attack)), .y = FOOTER_Y - DATA_Y - 10 - (uint16_t)(y_size * (vc.oscillator[oscid].sustain))};
    filter.sustain.stop = {.x = vc.lcdHandler.width() - DATA_X - (uint16_t)(step_length * vc.oscillator[oscid].release), .y = FOOTER_Y - DATA_Y - 10 - (uint16_t)(y_size * (vc.oscillator[oscid].sustain))};
    filter.release.stop = {.x = vc.lcdHandler.width() - DATA_X, .y = FOOTER_Y - DATA_Y - 10};

    vc.lcdHandler.drawLine(filter.attack.start.x, filter.attack.start.y, filter.attack.stop.x, filter.attack.stop.y, ILI9341_BLACK);
    vc.lcdHandler.drawLine(filter.attack.stop.x, filter.attack.stop.y, filter.decay.stop.x, filter.decay.stop.y, ILI9341_BLACK);
    vc.lcdHandler.drawLine(filter.decay.stop.x, filter.decay.stop.y, filter.sustain.stop.x, filter.sustain.stop.y, ILI9341_BLACK);
    vc.lcdHandler.drawLine(filter.sustain.stop.x, filter.sustain.stop.y, filter.release.stop.x, filter.release.stop.y, ILI9341_BLACK);

    //vc.lcdHandler.fillRect(DATA_X, FOOTER_Y - DATA_Y, 60, FOOTER_Y - DATA_Y, ILI9341_WHITE);
    vc.lcdHandler.setTextSize(8);
    vc.lcdHandler.setFont(Arial_8);

    char str_buff[10];
    int width;

    vc.lcdHandler.setTextColor(ILI9341_BLACK);
    vc.lcdHandler.setCursor(DATA_X, FOOTER_Y - DATA_Y);
    vc.lcdHandler.printf("ATTACK: ");
    memset(str_buff, 0, 10);
    sprintf(str_buff, "%.02fms", vc.oscillator[oscid].attack);
    width = vc.lcdHandler.measureTextWidth(str_buff, 0);
    vc.lcdHandler.setCursor(DATA_X + 150 - width, FOOTER_Y - DATA_Y);
    vc.lcdHandler.printf("%s", str_buff);

    vc.lcdHandler.setCursor(DATA_X + 160, FOOTER_Y - DATA_Y);
    vc.lcdHandler.printf("DECAY: ");
    memset(str_buff, 0, 10);
    sprintf(str_buff, "%.02fms", vc.oscillator[oscid].decay);
    width = vc.lcdHandler.measureTextWidth(str_buff, 0);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - DATA_X - width, FOOTER_Y - DATA_Y);
    vc.lcdHandler.printf("%s", str_buff);

    vc.lcdHandler.setCursor(DATA_X, FOOTER_Y - DATA_Y + 12);
    vc.lcdHandler.printf("SUSTAIN: ");
    memset(str_buff, 0, 10);
    sprintf(str_buff, "%.01f%%", vc.oscillator[oscid].sustain * 100);
    width = vc.lcdHandler.measureTextWidth(str_buff, 0);
    vc.lcdHandler.setCursor(DATA_X + 150 - width, FOOTER_Y - DATA_Y + 12);
    vc.lcdHandler.printf("%s", str_buff);

    vc.lcdHandler.setCursor(DATA_X + 160, FOOTER_Y - DATA_Y + 12);
    vc.lcdHandler.printf("RELEASE: ");
    memset(str_buff, 0, 10);
    sprintf(str_buff, "%.02fms", vc.oscillator[oscid].release);
    width = vc.lcdHandler.measureTextWidth(str_buff, 0);
    vc.lcdHandler.setCursor(vc.lcdHandler.width() - DATA_X - width, FOOTER_Y - DATA_Y + 12);
    vc.lcdHandler.printf("%s", str_buff);

    Serial.printf("ADSR: points %d,%d %d,%d %d,%d %d,%d %d,%d\n\r", filter.attack.start.x, filter.attack.start.y, filter.attack.stop.x, filter.attack.stop.y, filter.decay.stop.x, filter.decay.stop.y, filter.sustain.stop.x, filter.sustain.stop.y, filter.release.stop.x, filter.release.stop.y);
}

void ADSR::drawFooter()
{
    vc.lcdHandler.setTextSize(14);
    vc.lcdHandler.setFont(Arial_14_Bold);

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
