#include <vector>
#include <iostream> 

#pragma once

struct Player {
    std::string nom {};
    char symbol {};
};

Player create_player();