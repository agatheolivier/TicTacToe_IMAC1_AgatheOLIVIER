# Agathe OLIVIER - TIC TAC TOE

## Organisation des fichiers

J'ai réparti mon travail en plusieurs catégories : 
1. Main : le fichier qui permet de lancer la partie et de choisir son mode de jeu
2. Plateau : Commun aux deux modes de jeux, créer le plateau de jeu et le met à jour
3. Player : Pour créer les joueurs et le profil de l'IA
4. Gameplay : Test de victoire et fonctions du mode multijoueur
5. IA : Fonctions du mode IA
J'ai séparé l'IA du gameplay comme c'est une amélioration et qu'elle nécéssicite une fonction plutôt conséquantes.

## Problèmes rencontrés et solutions trouvées

### Dans player.cpp

Pour la première partie, j'ai vérifier que deux joueurs ne puissent pas choisir le même symbole.
J'ai également vérfié que les joueurs ne puissent pas choisir un chiffre comme le choix des cases libres ce fait avec
les chiffres.

Mais j'ai découvert une faille : si un joueur tentait de choisir un chiffre, puis le même symbole que le joueur précédent, alors il pouvait y arriver.
J'avais la bonne logique mais les deux vérifications se faisaient séparement : 

    ```while (joueur.symbol == PremierSymbolChoisi) {
        std::cout << "Symbole déjà pris par un autre joueur ! Choississez un autre symbole : ";
        std::cin >> joueur.symbol;
    }

    //Vérifier que le joueur n'a pas pris un chiffre, sinon ça se confondera avec l'affichage du plateau de jeu de base
    for (char i = '1'; i <= '9'; i++) {
        if (joueur.symbol == i){
            std::cout << "Vous ne pouvez pas choisir ce symbole. Choississez un autre symbole : ";
            std::cin >> joueur.symbol;
        }
    }```

J'ai donc retravailler le code pour régler cette faille.

### Dans gameplay.cpp

En testant la possibilité de poser ses symboles, j'ai découvert une nouvelle faille : quand le joueur choisissait 0 ou un nombre supérieur à 10, son tour était passé.
J'ai donc ajouté la boucle while actuelle après la sélection de l'emplacement.

Même chose dans la boucle while de la fonction multijoueur_debut, j'ai ajouté un !(std::cin >> emplacement) pour éviter une erreur si le joueur rentre une lettre à la place d'un chiffre pour le choix d'une case.

Au départ le code de ma fonction multijoueur_debut était dans le main car je n'arrivais pas à récupérer les joueurs
qui étaient return pour les passer en paramètre.
Avec l'ajout du second de jeu, j'ai estimé que c'était plus simple de le passer en fonction.
Jules m'a aidé avec std::pair<Player, Player>.

### Dans main.cpp

Pour la sélection du mode de jeu, j'ai repris la logique de la boucle do while de player.

## Améliorations

J'ai choisi l'amélioration de l'IA, Jules m'a aidé pour son fonctionnement. L'idée est de créer une copie du tableau. A l'aide de ma fonction victoire, je vérifie si l'IA peut gagner en jouant un coup précis (attaque), et si le joueur peut gagner également (défense). Dans ce cas, l'IA joue ce coup dans le vrai plateau, sinon elle joue aléatoirement.

Mon premier essaie fonctionnait, mais j'avais regroupé dans la même boucle if la défense et l'attaque.
De ce fait, l'IA jouait le premier coup valide, qu'il soit défensif ou attaquant.
Mais logiquement, l'IA doit attaquer en premier plutôt que de défendre : pas besoin de défendre si on a gagné.
J'ai donc changé mon code pour celui actuel en séparant attaque et défense, avec l'attaque en premier.

Mon IA est fonctionnelle et attaque et défend. Il y a un unique bug que je n'ai pas réussi à résoudre.
Voici le cas de figure :
C'est a votre tour de jouer, choississez votre case : 3
|1|2|A|
|X|A|6|
|7|8|9|
C'est au de l'IA de jouer.
|1|2|A|
|X|A|6|
|X|8|9|
> L'IA défend correctement, la fonction marche bien pour les diagonales

C'est a votre tour de jouer, choississez votre case : 1
|A|2|A|
|X|A|6|
|X|8|9|
C'est au de l'IA de jouer.
|A|X|A|
|X|A|6|
|X|8|9|
> Mais elle ne défend jamais la seconde diagonale attaquée.

Je n'ai pas réussi à comprendre d'où vient le problème.
A part ce cas de figure, l'IA est 100% fonctionnel.