#include "player.hpp"
#include "plateau.hpp"
#include "gameplay.hpp"
#include "ia.hpp"
#include <iostream>
#include <array>
#include <cstdlib> // pour std::rand et std::srand
#include <ctime>   // pour std::time

/******************************** INITIALISATION SOLO *****************************************************/

std::pair<Player, Player> solo_debut (std::array<char, 9>& plateau){
    std::cout << "Entrez les information du joueur : ";
    Player joueur1 = create_player();
    Player joueur2 = create_ia(joueur1);

    std::cout << "Recapitulatif des joueurs : ";
    std::cout << joueur1.nom << " joue avec " << joueur1.symbol << "\n";
    std::cout << joueur2.nom << " joue avec " << joueur2.symbol << "\n";

    std::cout << "Voici le plateau de jeu : ";
    std::cout << std::endl;
    draw_game_board(plateau);

    return std::make_pair(joueur1, joueur2);
}

/****************************************** PARTIE SOLO *****************************************************/

void solo_partie (Player joueur1, Player joueur2, std::array<char, 9>& plateau){
    int emplacement = 0;
    int nombredetours = 1; 
    QuiAGagne gagnant = QuiAGagne::Personne;
    QuiAGagne gagnantTest = QuiAGagne::Personne;

    while (nombredetours < 10 && gagnant == QuiAGagne::Personne) {
        //Joueur 1 de jouer
        if (nombredetours % 2 != 0) {
            std::cout << "C'est a votre tour de jouer, choississez votre case : ";

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
                std::cout << "Cette case est deja prise, choisissez une autre case" << std::endl;
            }
            draw_game_board(plateau);
            gagnant = Victoire (joueur1, joueur2, plateau);
        } 
        //Joueur 2 de jouer
        else {
            std::cout << "C'est au de l'IA de jouer. " << std::endl;

            //Attaque en priorié
            for (size_t indexIA = 0; indexIA < 9; indexIA++) {
                //Si la case est occupée, on ne fait pas les autres vérifs
                if (plateau[indexIA] == joueur1.symbol || plateau[indexIA] == joueur2.symbol) {
                    continue;
                }

                //Test si l'IA a deux symbole alignés
                std::array<char, 9> plateauTest = plateau; //On dublique le plateau
                plateauTest[indexIA] = joueur2.symbol; //On joue sur le plateau test
                gagnantTest = Victoire (joueur1, joueur2, plateauTest); //Si ce coup nous fait gagner, on le joue, sinon on continue
                if (gagnantTest == QuiAGagne::Player2) {
                    plateau[indexIA] = joueur2.symbol;
                    break;
                }
            }

            //Si pas d'attaque possible, on vérifie la défense
            if (gagnantTest == QuiAGagne::Personne) {
                for (size_t indexIA = 0; indexIA < 9; indexIA++) {
                    if (plateau[indexIA] == joueur1.symbol || plateau[indexIA] == joueur2.symbol) {
                        continue;
                    }

                    std::array<char, 9> plateauTest = plateau; //On réinitialise le plateau test
                    plateauTest[indexIA] = joueur1.symbol; //On fait comme si le joueur jouait le coup sur plateau test
                    gagnantTest = Victoire (joueur1, joueur2, plateauTest); //Si le joueur 1 gagne, on joue le coup pour contrer
                    if (gagnantTest == QuiAGagne::Player1) {
                        plateau[indexIA] = joueur2.symbol;
                        break;
                    }
                }
            }
            
            //Si pas d'attaque ni de défense, alors coup aléatoire
            if (gagnantTest == QuiAGagne::Personne) { //Si pas deux symboles allignés, alors l'IA joue un coup aléatoire
                int indexIA;
                do {
                    std::srand(std::time(nullptr)); //Evite que ce soit toujours le même nombre aléatoire à chaque lancement
                    indexIA = std::rand() % 9; //Un nombre entre 0 et 8, change jusqu'à ce que ce soit une case vide
                } while (plateau[indexIA] == joueur1.symbol || plateau[indexIA] == joueur2.symbol);

                plateau[indexIA] = joueur2.symbol;
            }
            nombredetours++;
            draw_game_board(plateau);
            gagnant = Victoire (joueur1, joueur2, plateau);
        }
    }
    if (gagnant == QuiAGagne::Player1) {
        std::cout << "Felicitation ! Le joueur " << joueur1.nom << " a gagne !" << std::endl;
    }
    if (gagnant == QuiAGagne::Player2) {
        std::cout << "Dommage, l'IA a gagne. Vous ferez mieux la prochaine fois" << std::endl;
    }
    std::cout << "La partie est terminee !" << std::endl;
    return;
}