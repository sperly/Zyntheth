#include "menuhandler.hpp"
#include <memory>

MenuHandler::MenuHandler()
{
    topItem = std::make_shared<MenuItem>(MenuItem(NULL, "Splash"));
    topItem->AddNextItem(std::make_shared<MenuItem>(MenuItem(topItem, "Main")));
    currentItem = topItem;
}

void MenuHandler::Init()
{
}