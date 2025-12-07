#include "player.hpp"
#include "plateau.hpp"
#include "gameplay.hpp"
#include <iostream>
#include <array>

/* Player multijoueur_debutdepartie (Player &joueur1, Player &joueur2){
    std::cout << "Entrez les information du joueur 1 : ";
    Player joueur1 = create_player();

    std::cout << "Entrez les information du joueur 2 : ";
    Player joueur2 = create_player();

    std::cout << "Récapitulatif des joueurs : ";
    std::cout << joueur1.nom << " joue avec " << joueur1.symbol << "\n";
    std::cout << joueur2.nom << " joue avec " << joueur2.symbol << "\n";

    std::cout << "Voici le plateau de jeu : ";
    std::cout << std::endl;
    draw_game_board();
    return joueur1, joueur2;
} */

void multijoueur_partie (Player joueur1, Player joueur2, std::array<char, 9>& plateau){
    int emplacement = 0;

    std::cout << "C'est au joueur 1 de jouer, choississez votre case : ";
    std::cin >> emplacement;

    int index = emplacement - 1; 

    if (plateau[index] != joueur1.symbol && plateau[index] != joueur2.symbol) { // la case est libre
        plateau[index] = joueur1.symbol;
    } else {
        std::cout << "Cette case est déjà prise, choisissez une autre case" << std::endl;
    }
    draw_game_board(plateau);

    std::cout << "C'est au joueur 2 de jouer, choississez votre case : ";
    std::cin >> emplacement;

    index = emplacement - 1; 

    if (plateau[index] != joueur1.symbol && plateau[index] != joueur2.symbol) { // la case est libre
        plateau[index] = joueur2.symbol;
    } else {
        std::cout << "Cette case est déjà prise, choisissez une autre case" << std::endl;
    }
    draw_game_board(plateau);

}