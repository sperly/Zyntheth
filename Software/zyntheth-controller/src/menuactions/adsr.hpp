#pragma once

#include "menuaction.hpp"
#include "valuecontainer.hpp"

class ADSR : public IMenuAction
{
 public:
    ADSR(ValueContainer& valcon, uint8_t id);
    void Enter();
    void HandleParameterChange(uint8_t parameter, int16_t value);

 private:
    struct point
    {
        int x;
        int y;
    };

    struct line
    {
        struct point start;
        struct point stop;
    };

    struct adsr
    {
        struct line attack;
        struct line decay;
        struct line sustain;
        struct line release;
    };

    void drawMenu();
    void drawHeader();
    void drawData();
    void drawFilter();
    void drawFooter();
    ValueContainer& vc;
    uint8_t oscid;
};
