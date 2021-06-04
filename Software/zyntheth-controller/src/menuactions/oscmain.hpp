#pragma once

#include "ILI9341_t3n.h"
#include "menuaction.hpp"
#include "valuecontainer.hpp"

class OscMain : public IMenuAction
{
 public:
    OscMain(ValueContainer& valcon);
    void Enter();
    void HandleParameterChange(uint8_t parameter, int16_t value);

 private:
    void drawMenu();
    void drawHeader();
    void drawData();
    void drawFooter();
    ValueContainer& vc;
};
