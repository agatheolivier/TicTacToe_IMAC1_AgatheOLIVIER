#include <iostream> 
#include <array>
#include "player.hpp"

#pragma once

enum class QuiAGagne{
    Player1,
    Player2,
    Personne,
};

//Player multijoueur_debutdepartie (Player &joueur1, Player &joueur2);
void multijoueur_partie (Player joueur1, Player joueur2, std::array<char, 9>& plateau);
std::pair<Player, Player> multijoueur_debut (std::array<char, 9>& plateau);
QuiAGagne Victoire (Player joueur1, Player joueur2, std::array<char, 9>& plateau);