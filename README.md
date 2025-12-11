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

************************************************ GAMEPLAY **********************************************************

En testant la possibilité de poser ses symboles, j'ai découvert une nouvelle faille : si le joueur choisi 0 ou un
nombre supérieur à 10, son tour est passé.

J'ai donc ajouté la boucle while après la sélection de l'emplacement.

Au départ le code de ma fonction multijoueur_debut était dans le main car je n'arrivais pas à récupérer les joueurs
qui étaient return pour les passer en paramètre.
Avec l'ajout du second de jeu, j'ai estimé que c'était plus simple de le passer en fonction.
Jules m'a aidé avec std::pair<Player, Player> .

************************************************ MODE DE JEU **********************************************************

Pour la sélection du mode de jeu, j'ai repris la logique de la boucle do while de player.