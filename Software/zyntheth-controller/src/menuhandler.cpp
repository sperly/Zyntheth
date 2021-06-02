#include "menuhandler.hpp"
#include <memory>
#include "menuActions/adsr.hpp"
#include "menuActions/menuaction.hpp"
#include "menuActions/oscmain.hpp"
#include "menuActions/oscmenu.hpp"
#include "menuactions/splashmenu.hpp"
#include "menuactions/testmenu.hpp"

MenuHandler::MenuHandler() : menuStack{}, menu{}, currentMenuIndex{0}
{
}

void MenuHandler::Init(ValueContainer& valuecon)
{
    Serial.printf("MenuHandler::Init \n\r");
    menu.emplace_back(new SplashMenu{valuecon});
    menu.emplace_back(new TestMenu{valuecon});
    menu.emplace_back(new OscMain{valuecon});
    menu.back()->SubMenu.emplace_back(new OscMenu{valuecon, 0});
    menu.back()->SubMenu.back()->SubMenu.emplace_back(new ADSR{valuecon, 0});
    menu.back()->SubMenu.emplace_back(new OscMenu{valuecon, 1});
    menu.back()->SubMenu.back()->SubMenu.emplace_back(new ADSR{valuecon, 1});
    menu.back()->SubMenu.emplace_back(new OscMenu{valuecon, 2});
    menu.back()->SubMenu.back()->SubMenu.emplace_back(new ADSR{valuecon, 2});
    menu.back()->SubMenu.emplace_back(new OscMenu{valuecon, 3});
    menu.back()->SubMenu.back()->SubMenu.emplace_back(new ADSR{valuecon, 3});

    menuStack.push_back(std::make_unique<std::vector<IMenuAction*>>(menu));
    menuStack.back()->at(0)->Enter();
    Serial.printf("MenuHandler::Init ... Done!\n\r");
}

void MenuHandler::HandleMenuAction(uint8_t parameter, int16_t value)
{
    Serial.printf("HandleMenuAction: par: %d, val: %d (currMenu = %d/%d)\n\r", parameter, value, currentMenuIndex.back(), menuStack.back()->size());
    if (parameter == 0)
    {
        if (value < 0)
        {
            if (currentMenuIndex.back() > 0)
                currentMenuIndex.back()--;
            else
                currentMenuIndex.back() = menuStack.back()->size() - 1;
        }
        else
        {
            if (currentMenuIndex.back() < (menuStack.back()->size() - 1))
                currentMenuIndex.back()++;
            else
                currentMenuIndex.back() = 0;
        }

        menuStack.back()->at(currentMenuIndex.back())->Enter();
    }
    else if (parameter == 5 && value == 1)
    {
        if (menuStack.back()->at(currentMenuIndex.back())->SubMenu.size() > 0)
        {
            Serial.printf("MenuHandler::HandleMenuAction: Changing to submenu/n/r");
            menuStack.push_back(std::make_unique<std::vector<IMenuAction*>>(menuStack.back()->at(currentMenuIndex.back())->SubMenu));
            currentMenuIndex.push_back(0);
            menuStack.back()->at(currentMenuIndex.back())->Enter();
        }
    }
    else if (parameter == 10 && menuStack.size() > 1 && value == 1)
    {
        Serial.printf("MenuHandler::HandleMenuAction: Returning to parent menu/n/r");
        menuStack.pop_back();
        currentMenuIndex.pop_back();
        menuStack.back()->at(currentMenuIndex.back())->Enter();
    }
    else
    {
        menuStack.back()->at(currentMenuIndex.back())->HandleParameterChange(parameter, value);
    }
}
