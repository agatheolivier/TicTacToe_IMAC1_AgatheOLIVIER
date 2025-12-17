#include "player.hpp"
#include "plateau.hpp"
#include "gameplay.hpp"
#include "ia.hpp"
#include <iostream>
#include <array>

/******************************** INITIALISATION SOLO *****************************************************/

std::pair<Player, Player> solo_debut (std::array<char, 9>& plateau){
    std::cout << "Entrez les information du joueur : ";
    Player joueur1 = create_player();
    Player joueur2 = create_ia(joueur1);

    std::cout << "Récapitulatif des joueurs : ";
    std::cout << joueur1.nom << " joue avec " << joueur1.symbol << "\n";
    std::cout << joueur2.nom << " joue avec " << joueur2.symbol << "\n";

    std::cout << "Voici le plateau de jeu : ";
    std::cout << std::endl;
    draw_game_board(plateau);

    return std::make_pair(joueur1, joueur2);
}

/****************************************** PARTIE SOLO *****************************************************/

/* 
void multijoueur_partie (Player joueur1, Player joueur2, std::array<char, 9>& plateau){
    int emplacement = 0;
    int nombredetours = 1; 
    bool victoire = false;

    while (nombredetours < 10 && !victoire) {
        //Joueur de jouer
        if (nombredetours % 2 != 0) {
            std::cout << "C'est à votre tour de jouer, choississez votre case : ";
            std::cin >> emplacement;

            while (emplacement < 1 || emplacement > 9) {
                std::cout << "Cette case n'existe pas. Choississez une nouvelle case :";
                std::cin >> emplacement;
            }

            int index = emplacement - 1; 

            if (plateau[index] != joueur1.symbol && plateau[index] != joueur2.symbol) { // la case est libre
                plateau[index] = joueur1.symbol;
                nombredetours++;
            } else {
                std::cout << "Cette case est déjà prise, choisissez une autre case" << std::endl;
            }
            draw_game_board(plateau);
            Victoire (joueur1, joueur2, plateau, victoire);

        } 

        //IA de jouer
        else {
            std::cout << "C'est à l'IA de jouer : ";

            //Etape n°1 : Je créais une copie du plateau actuel pour faire mes vérifs
            std::array<char, 9> verifvictoire = plateau; 

            int index = emplacement - 1; 

            if (plateau[index] != joueur1.symbol && plateau[index] != joueur2.symbol) { // la case est libre
                plateau[index] = joueur2.symbol;
                nombredetours++;
            } else {
                std::cout << "Cette case est déjà prise, choisissez une autre case" << std::endl;
            }
            draw_game_board(plateau);
            Victoire (joueur1, joueur2, plateau, victoire);
        }
    }
    std::cout << "La partie est terminée !" << std::endl;
    return;
} */