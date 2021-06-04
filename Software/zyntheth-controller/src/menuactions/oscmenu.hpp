#pragma once

#include "ILI9341_t3n.h"
#include "menuaction.hpp"
#include "valuecontainer.hpp"

class OscMenu : public IMenuAction
{
 public:
    OscMenu(ValueContainer& valcon, uint8_t id);
    void Enter();
    void HandleParameterChange(uint8_t parameter, int16_t value);

 private:
    void drawMenu();
    void drawHeader();
    void drawData();
    void drawWaveform();
    void drawFooter();
    ValueContainer& vc;
    uint8_t oscid;
};
