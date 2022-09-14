#pragma once

#include <iostream>
#include <string>
#include <cstring>

class Game
{
private:

    void init_variables();
    void init_console();


public:
    Game();
    virtual ~Game();

    void end_app();
    void update();

    void run();
};