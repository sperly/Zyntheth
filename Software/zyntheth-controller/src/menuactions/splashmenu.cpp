#include "splashmenu.hpp"
#include "gfx.hpp"
#include "ili9341_t3n_font_Arial.h"
#include "ili9341_t3n_font_ArialBold.h"
#include "log.hpp"

SplashMenu::SplashMenu(ValueContainer& valcon) : vc{valcon}
{
}

void SplashMenu::Enter()
{
    drawMenu();
}

void SplashMenu::HandleParameterChange(uint8_t parameter, int16_t value)
{
    return;
    // lcdHandler.setTextSize(14);
    // lcdHandler.setFont(Arial_14);
    // if (parameter >= 1 && parameter <= 4)
    // {
    //     if (value < 0)
    //     {
    //         lcdHandler.setTextColor(ILI9341_RED);
    //     }
    //     else
    //     {
    //         lcdHandler.setTextColor(ILI9341_BLACK);
    //     }
    //     lcdHandler.fillRect(10, 58 + (17 * (parameter - 1)), 300, 16, ILI9341_WHITE);
    //     lcdHandler.setCursor(15, 59 + (17 * (parameter - 1)));
    //     lcdHandler.printf("Pos %d: %d", parameter, value);
    // }
}

void SplashMenu::drawMenu()
{
    LOG_DEBUG("Drawing Splash menu...");
    vc.lcdHandler.fillRect(10, 4, 300, HEADER_HEIGHT - 6, ILI9341_WHITE);
    GFX::DrawBMP(vc, "logo.bmp", HEADER_HEIGHT - 22, 2, vc.lcdHandler);
    vc.lcdHandler.drawFastHLine(15, HEADER_HEIGHT - 2, 290, ILI9341_BLACK);
    GFX::DrawBMP(vc, "splash.bmp", 15, HEADER_HEIGHT + 1, vc.lcdHandler);
    vc.lcdHandler.setTextColor(ILI9341_BLACK);
    vc.lcdHandler.setTextSize(12);
    vc.lcdHandler.setFont(Arial_12_Bold);
    vc.lcdHandler.setCursor(160, HEADER_HEIGHT - 4 - 12);
    vc.lcdHandler.printf("HW:");
    vc.lcdHandler.setCursor(239, HEADER_HEIGHT - 4 - 12);
    vc.lcdHandler.printf("SW:");
    vc.lcdHandler.setCursor(198, HEADER_HEIGHT - 4 - 12);
    vc.lcdHandler.printf("%d", HW_VER_MAJOR);
    vc.lcdHandler.setCursor(276, HEADER_HEIGHT - 4 - 12);
    vc.lcdHandler.printf("%d", SW_VER_MAJOR);

    vc.lcdHandler.setTextSize(9);
    vc.lcdHandler.setFont(Arial_9_Bold);
    vc.lcdHandler.setTextColor(vc.lcdHandler.color565(165, 165, 165));
    vc.lcdHandler.setCursor(206, HEADER_HEIGHT - 4 - 10);
    vc.lcdHandler.printf(".%d.%d", HW_VER_MINOR, HW_VER_PATCH);
    vc.lcdHandler.setCursor(284, HEADER_HEIGHT - 4 - 10);
    vc.lcdHandler.printf(".%d.%d", SW_VER_MINOR, SW_VER_PATCH);
    LOG_DEBUG("Drawing menu done.");
}
