#include "plateau.hpp"
#include <iostream>
#include <array>

void draw_game_board(std::array<char, 9> plateau) {
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
                std::cout << "|" << plateau[i+j];
        }
        std::cout << "|" << std::endl;
    }
    return;
}