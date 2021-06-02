#pragma once

#include "ILI9341_t3.h"
#include "menuaction.hpp"
#include "valuecontainer.hpp"

class ADSR : public IMenuAction
{
 public:
    ADSR(ValueContainer& valcon, uint8_t id);
    void Enter();
    void HandleParameterChange(uint8_t parameter, int16_t value);

 private:
    void drawMenu();
    void drawHeader();
    void drawData();
    void drawFilter();
    void drawFooter();
    ValueContainer& vc;
    uint8_t oscid;
};
