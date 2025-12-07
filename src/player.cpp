#include "player.hpp"
#include <vector>
#include <iostream>

Player create_player() {
    static char PremierSymbolChoisi = '\0'; // garde sa valeur d’un appel à l’autre, sans avoir besoin de la passer en paramètre.
    Player joueur;

    std::cout << "Entrez le nom du joueur : ";
    std::cin >> joueur.nom;

    bool symbole_valide = false;
    do {
        std::cout << "Choisissez un symbole (ex: X ou O) : ";
        std::cin >> joueur.symbol;

        if (joueur.symbol == PremierSymbolChoisi) {
            std::cout << "Symbole déjà pris par un autre joueur !";
            continue; //Revient au début de la boucle
        }

        //Vérifier que le joueur n'a pas pris un chiffre, sinon ça se confondera avec l'affichage du plateau de jeu de base
        if (joueur.symbol >= '1' && joueur.symbol <= '9') {
            std::cout << "Vous ne pouvez pas choisir ce symbole.";
            continue;  
        }
        
        //Si ça ne remplit pas les deux if le symbole est bon
        symbole_valide = true;
    } while (!symbole_valide); //Condition d'arrête de la boucle
    
    if (PremierSymbolChoisi == '\0') {
        PremierSymbolChoisi = joueur.symbol;
    }

    return joueur;
}