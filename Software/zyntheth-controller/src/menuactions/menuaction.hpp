#pragma once

#include <vector>
#include "Arduino.h"
#include "valuecontainer.hpp"

class IMenuAction
{
 public:
    virtual ~IMenuAction(){};
    virtual void Enter() = 0;
    virtual void Exit(){};
    virtual void HandleParameterChange(uint8_t parameter, int16_t value){};

    std::vector<IMenuAction*> SubMenu;

 private:
    virtual void drawMenu() = 0;
};
