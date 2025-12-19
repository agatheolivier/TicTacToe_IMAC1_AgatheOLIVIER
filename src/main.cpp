#include <vector>
#include <iostream> 
#include "player.hpp"
#include "plateau.hpp"
#include "gameplay.hpp"
#include "ia.hpp"

int main() {
    std::array<char, 9> plateau = {'1','2','3','4','5','6','7','8','9'};
    char mode;
    bool mode_valide = false;

    do {
        std::cout << "Choississez votre mode de jeu. 1 pour multijoueur, 2 pour jouer contre une IA :" << std::endl;
        std::cin >> mode;

        if (mode != '1' && mode != '2') {
            std::cout << "Le mode de jeu choisi est invalide." << std::endl;
            continue;
        }
        
        mode_valide = true;
    } while (!mode_valide);


    if (mode == '1') {
        std::pair<Player, Player>  players =  multijoueur_debut(plateau); //Récupère le return de la fonction
        multijoueur_partie(players.first, players.second, plateau); //Les passe en paramètre pour la seconde
    }
    else {
        std::pair<Player, Player>  players =  solo_debut(plateau); //Récupère le return de la fonction
        solo_partie(players.first, players.second, plateau);
    }
    return 0;
}

