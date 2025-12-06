#include <vector>
#include <iostream> 
#include "player.hpp"

int main() {
    std::cout << "Entrez les information du joueur 1 : ";
    Player joueur1 = create_player();

    std::cout << "Entrez les information du joueur 2 : ";
    Player joueur2 = create_player();

    std::cout << "Racapitulatif des joueurs : ";
    std::cout << joueur1.nom << " joue avec " << joueur1.symbol << "\n";
    std::cout << joueur2.nom << " joue avec " << joueur2.symbol << "\n";

    return 0;
}

