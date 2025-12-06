#include "player.hpp"
#include <vector>
#include <iostream>

Player create_player() {
    static char PremierSymbolChoisi = '\0'; // garde sa valeur d’un appel à l’autre, sans avoir besoin de la passer en paramètre.
    Player joueur;

    std::cout << "Entrez le nom du joueur : ";
    std::cin >> joueur.nom;

    std::cout << "Choisissez un symbole (ex: X ou O) : ";
    std::cin >> joueur.symbol;

    while (joueur.symbol == PremierSymbolChoisi) {
        std::cout << "Symbole déjà pris par un autre joueur ! Choississez un autre symbole : ";
        std::cin >> joueur.symbol;
    }

    if (joueur.symbol == '.') {
        std::cout << "Vous ne pouvez pas choisir ce symbole. Choississez un autre symbole : ";
        std::cin >> joueur.symbol;
    }

    PremierSymbolChoisi = joueur.symbol;

    return joueur;
}