************************************************ PLAYER ************************************************************

Pour la première partie, j'ai vérifier que deux joueurs ne puissent pas choisir le même symbole.
J'ai également vérfié que les joueurs ne puissent pas choisir un chiffre comme le plateau de jeu affiche
des chiffres pour le choix des cases libres.

Mais j'ai remarqué que si les joueurs tentaient de choisir un chiffre, puis le même symbole que le joueur précédent,
alors il pouvait y arriver.
J'avais donc la bonne logique mais les deux vérifications se faisaient séparement : 

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
J'ai donc retravailler le code pour régler cette faille