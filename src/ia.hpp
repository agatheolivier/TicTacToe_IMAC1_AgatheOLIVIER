#include <iostream> 
#include <array>
#include "player.hpp"

#pragma once

std::pair<Player, Player> solo_debut (std::array<char, 9>& plateau);
void solo_partie (Player joueur1, Player joueur2, std::array<char, 9>& plateau);