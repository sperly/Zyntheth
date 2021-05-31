#pragma once

class MenuItem
{
 public:
    std::shared_ptr<MenuItem> NextItem;
    std::shared_ptr<MenuItem> PreviousItem;
    std::shared_ptr<MenuItem> SubItem;
    std::shared_ptr<MenuItem> parentItem;

    MenuItem(std::shared_ptr<MenuItem> parent, char* title);

    void HandleMenuAction(uint8_t parameter, int16_t value);

    void AddSubItem(std::shared_ptr<MenuItem> child);
    void AddNextItem(std::shared_ptr<MenuItem> next);
    void SetPrevious(std::shared_ptr<MenuItem> previous);

 private:
    char* title;
}