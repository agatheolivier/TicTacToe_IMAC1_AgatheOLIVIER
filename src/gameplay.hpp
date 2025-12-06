#include <iostream> 
#include <array>

#pragma once

//Player multijoueur_debutdepartie (Player &joueur1, Player &joueur2);
void multijoueur_partie (Player joueur1, Player joueur2, std::array<int, 9> plateau = {1,2,3,4,5,6,7,8,9});