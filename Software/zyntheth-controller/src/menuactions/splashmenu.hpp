#pragma once

#include "ILI9341_t3.h"
#include "menuaction.hpp"

class SplashMenu : public IMenuAction
{
 public:
    SplashMenu(ValueContainer& valcon);
    void Enter();
    void HandleParameterChange(uint8_t parameter, int16_t value);

 private:
    void drawMenu();
    ValueContainer& vc;
};
