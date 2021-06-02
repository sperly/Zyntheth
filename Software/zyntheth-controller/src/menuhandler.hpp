#pragma once

#include <memory>
#include <vector>
#include "Arduino.h"
#include "ILI9341_t3.h"
#include "menuactions/menuaction.hpp"
#include "valuecontainer.hpp"
// #include "menuitem.hpp"

class MenuHandler
{
 public:
    MenuHandler();
    // ~MenuHandler();

    void Init(ValueContainer& vc);
    void HandleMenuAction(uint8_t parameter, int16_t value);

 private:
    // std::unique_ptr<std::vector<IMenuAction*>> currentMenu;
    // std::unique_ptr<std::vector<IMenuAction*>> parentMenu;
    std::vector<std::unique_ptr<std::vector<IMenuAction*>>> menuStack;
    std::vector<IMenuAction*> menu;
    std::vector<uint8_t> currentMenuIndex;
};
