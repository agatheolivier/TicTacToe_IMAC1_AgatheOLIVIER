#include "plateau.hpp"
#include <iostream>
#include <array>

void draw_game_board(std::array<char, 9> plateau) {
    for (size_t i = 0; i < 3; i++) //Lignes
    {
        for (size_t j = 0; j < 3; j++) //Collones
        {
                std::cout << "|" << plateau[i*3+j]; //i*3+j permet d'avoir le bon indice du tableau. Ex : i=1, j=1,  (1*3) + 1 = 4
        }
        std::cout << "|" << std::endl;
    }
    return;
}