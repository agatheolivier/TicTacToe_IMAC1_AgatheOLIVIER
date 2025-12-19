#include "player.hpp"
#include "plateau.hpp"
#include "gameplay.hpp"
#include <iostream>
#include <array>

// ********************************************** VICTOIRE ******************************************************** //

QuiAGagne Victoire (Player joueur1, Player joueur2, std::array<char, 9>& plateau){
    //Vérification collones
    int c1 = 0;
    int c2 = 3;
    int c3 = 6;
    for (size_t i = 0; i < 3; i++) //Lignes
    {
        if (plateau[c1] == joueur1.symbol && plateau[c2] == joueur1.symbol && plateau[c3] == joueur1.symbol) {
            return QuiAGagne::Player1;
        }
        else if (plateau[c1] == joueur2.symbol && plateau[c2] == joueur2.symbol && plateau[c3] == joueur2.symbol){
            return QuiAGagne::Player2;
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
            return QuiAGagne::Player1;
        }
        else if (plateau[c4] == joueur2.symbol && plateau[c5] == joueur2.symbol && plateau[c6] == joueur2.symbol){
            return QuiAGagne::Player2;
        }
        c4 += 3;
        c5 += 3;
        c6 += 3;
    }

    //Diagonal n°1
    if (plateau[0] == joueur1.symbol && plateau[4] == joueur1.symbol && plateau[8] == joueur1.symbol) {
        return QuiAGagne::Player1;
    }
    else if (plateau[0] == joueur2.symbol && plateau[4] == joueur2.symbol && plateau[8] == joueur2.symbol){
        return QuiAGagne::Player2;
    }

    //Diagonal n°2
    if (plateau[6] == joueur1.symbol && plateau[4] == joueur1.symbol && plateau[2] == joueur1.symbol) {
        return QuiAGagne::Player1;
    }
    else if (plateau[6] == joueur2.symbol && plateau[4] == joueur2.symbol && plateau[2] == joueur2.symbol){
        return QuiAGagne::Player2;
    }

    return QuiAGagne::Personne;
}

// ******************************************** INITIALISATION MULTI *********************************************** //

std::pair<Player, Player> multijoueur_debut (std::array<char, 9>& plateau){
    std::cout << "Entrez les information du joueur 1 : ";
    Player joueur1 = create_player();

    std::cout << "Entrez les information du joueur 2 : ";
    Player joueur2 = create_player();

    std::cout << "Recapitulatif des joueurs : ";
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
    QuiAGagne gagnant = QuiAGagne::Personne;

    while (nombredetours < 10 && gagnant == QuiAGagne::Personne) {
        //Joueur 1 de jouer
        if (nombredetours % 2 != 0) {
            std::cout << "C'est au joueur 1 de jouer, choississez votre case : ";
            // std::cin >> emplacement;

            while (!(std::cin >> emplacement) || emplacement < 1 || emplacement > 9) {
                std::cin.clear(); // enlève l’erreur
                std::cin.ignore(1000, '\n');
                std::cout << "Cette case n'existe pas. Choississez une nouvelle case :";
            }

            int index = emplacement - 1; 

            if (plateau[index] != joueur1.symbol && plateau[index] != joueur2.symbol) { // la case est libre
                plateau[index] = joueur1.symbol;
                nombredetours++;
            } else {
                std::cout << "Cette case est déjà prise, choisissez une autre case" << std::endl;
            }
            draw_game_board(plateau);
            gagnant = Victoire (joueur1, joueur2, plateau);
        } 
        //Joueur 2 de jouer
        else {
            std::cout << "C'est au joueur 2 de jouer, choississez votre case : ";

            while (!(std::cin >> emplacement) || emplacement < 1 || emplacement > 9) {
                std::cin.clear(); // enlève l’erreur
                std::cin.ignore(1000, '\n');
                std::cout << "Cette case n'existe pas. Choississez une nouvelle case :";
            }

            int index = emplacement - 1; 

            if (plateau[index] != joueur1.symbol && plateau[index] != joueur2.symbol) { // la case est libre
                plateau[index] = joueur2.symbol;
                nombredetours++;
            } else {
                std::cout << "Cette case est déjà prise, choisissez une autre case" << std::endl;
            }
            draw_game_board(plateau);
            gagnant = Victoire (joueur1, joueur2, plateau);
        }
    }
    if (gagnant == QuiAGagne::Player1) {
        std::cout << "Felicitation ! Le joueur " << joueur1.nom << " a gagné !";
    }
    else if (gagnant == QuiAGagne::Player2) {
        std::cout << "Felicitation ! Le joueur " << joueur2.nom << " a gagné !";
    }
    else {
        std::cout << "C'est une égalité. ";
    }
    std::cout << "La partie est terminee !" << std::endl;
    return;
}