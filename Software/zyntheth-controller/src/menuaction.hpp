#pragma once

class MenuAction
{
 public:
    MenuAction();
    void Enter();
    void Exit();
    void HandleParameterChange(uint8_t parameter, int16_t value);

 private:
    drawMenu();
}