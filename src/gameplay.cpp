#include "player.hpp"
#include "plateau.hpp"
#include "gameplay.hpp"
#include <iostream>
#include <array>

// ********************************************** VICTOIRE ******************************************************** //


void Victoire (Player joueur1, Player joueur2, std::array<char, 9>& plateau, bool& victoire){
    //Vérification collones
    int c1 = 0;
    int c2 = 3;
    int c3 = 6;
    for (size_t i = 0; i < 3; i++) //Lignes
    {
        if (plateau[c1] == joueur1.symbol && plateau[c2] == joueur1.symbol && plateau[c3] == joueur1.symbol) {
            std::cout << "Félicitation ! Le joueur " << joueur1.nom << " a gagné !";
            victoire = true;
            return;
        }
        else if (plateau[c1] == joueur2.symbol && plateau[c2] == joueur2.symbol && plateau[c3] == joueur2.symbol){
            std::cout << "Félicitation ! Le joueur " << joueur2.nom << " a gagné !";
            victoire = true;
            return;
        }
        c1++;
        c2++;
        c3++;
    }

    //Vérification des lignes
    int c4 = 0;
    int c5 = 1;
    int c6 = 2;
    for (size_t j = 0; j < 3; j++) //Lignes
    {
        if (plateau[c4] == joueur1.symbol && plateau[c5] == joueur1.symbol && plateau[c6] == joueur1.symbol) {
            std::cout << "Félicitation ! Le joueur " << joueur1.nom << " a gagné !";
            victoire = true;
            return;
        }
        else if (plateau[c4] == joueur2.symbol && plateau[c5] == joueur2.symbol && plateau[c6] == joueur2.symbol){
            std::cout << "Félicitation ! Le joueur " << joueur2.nom << " a gagné !";
            victoire = true;
            return;
        }
        c4++;
        c5++;
        c6++;
    }

    //Diagonal n°1
    if (plateau[0] == joueur1.symbol && plateau[4] == joueur1.symbol && plateau[8] == joueur1.symbol) {
        std::cout << "Félicitation ! Le joueur " << joueur1.nom << " a gagné !";
        victoire = true;
        return;
    }
    else if (plateau[0] == joueur2.symbol && plateau[4] == joueur2.symbol && plateau[8] == joueur2.symbol){
         std::cout << "Félicitation ! Le joueur " << joueur2.nom << " a gagné !";
         victoire = true;
        return;
    }

    //Diagonal n°2
    if (plateau[6] == joueur1.symbol && plateau[4] == joueur1.symbol && plateau[2] == joueur1.symbol) {
        std::cout << "Félicitation ! Le joueur " << joueur1.nom << " a gagné !";
        victoire = true;
        return;
    }
    else if (plateau[6] == joueur2.symbol && plateau[4] == joueur2.symbol && plateau[2] == joueur2.symbol){
         std::cout << "Félicitation ! Le joueur " << joueur2.nom << " a gagné !";
        victoire = true;
         return;
    }

}

// ******************************************** INITIALISATION MULTI *********************************************** //

std::pair<Player, Player> multijoueur_debut (std::array<char, 9>& plateau){
    std::cout << "Entrez les information du joueur 1 : ";
    Player joueur1 = create_player();

    std::cout << "Entrez les information du joueur 2 : ";
    Player joueur2 = create_player();

    std::cout << "Récapitulatif des joueurs : ";
    std::cout << joueur1.nom << " joue avec " << joueur1.symbol << "\n";
    std::cout << joueur2.nom << " joue avec " << joueur2.symbol << "\n";

    std::cout << "Voici le plateau de jeu : ";
    std::cout << std::endl;
    draw_game_board(plateau);

    return std::make_pair(joueur1, joueur2);
}

// ********************************************** MULTI ******************************************************** //


void multijoueur_partie (Player joueur1, Player joueur2, std::array<char, 9>& plateau){
    int emplacement = 0;
    int nombredetours = 1; 
    bool victoire = false;

    while (nombredetours < 10 && !victoire) {
        //Joueur 1 de jouer
        if (nombredetours % 2 != 0) {
            std::cout << "C'est au joueur 1 de jouer, choississez votre case : ";
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
        //Joueur 2 de jouer
        else {
            std::cout << "C'est au joueur 2 de jouer, choississez votre case : ";
            std::cin >> emplacement;

            while (emplacement < 1 || emplacement > 9) {
                std::cout << "Cette case n'existe pas. Choississez une nouvelle case :";
                std::cin >> emplacement;
            }

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
}