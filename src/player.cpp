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

    //Vérifier que le joueur n'a pas pris un chiffre, sinon ça se confondera avec l'affichage du plateau de jeu de base
    for (char i = '1'; i <= '9'; i++) {
        if (joueur.symbol == i){
            std::cout << "Vous ne pouvez pas choisir ce symbole. Choississez un autre symbole : ";
            std::cin >> joueur.symbol;
        }
    }

    PremierSymbolChoisi = joueur.symbol;

    return joueur;
}