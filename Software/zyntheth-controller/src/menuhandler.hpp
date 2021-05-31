#pragma once

#include "Arduino.h"
#include "menuitem.hpp"

class MenuHandler
{
 public:
    MenuHandler();
    ~MenuHandler();

    void Init();
    void HandleMenuAction(uint8_t parameter, int16_t value);
    void EnterMenu();
    void ExitMenu();

 private:
    std::shared_ptr<MenuItem> topItem;
    std::shared_ptr<MenuItem> currentItem;
};
