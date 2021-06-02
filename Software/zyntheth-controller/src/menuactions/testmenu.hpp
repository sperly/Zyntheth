#pragma once

#include "ILI9341_t3.h"
#include "menuaction.hpp"
#include "valuecontainer.hpp"

class TestMenu : public IMenuAction
{
 public:
    TestMenu(ValueContainer& valcon);
    void Enter();
    void HandleParameterChange(uint8_t parameter, int16_t value);

 private:
    void drawMenu();
    ValueContainer& vc;

    int16_t parameterValues[ENCODERS + ENCODERS];
    int16_t prevParameterValues[ENCODERS + ENCODERS];
};
