# Démineur en C

Grâce à ces fichiers, vous pourrez jouer à une adaptation du démineur en C et dans un terminal uniquement (sans interface graphique).

## Comment jouer au jeu ?

### 1. Vérifier si GCC est installé

C'est très simple à partir du moment où vous avez le [compilateur GCC](https://gcc.gnu.org/install/) à votre diposition et ce peut-importe l'OS que vous utilisez.
Pour cela sous Linux/macOS ouvrez votre meilleur terminal et tapez :

```bash
which gcc
```

Pour Windows, tapez la commande :

```bash
where gcc
```

Si vous avez un chemin d'installation alors c'est bon GCC est bien installé, sinon il faudra le faire.

Maintenant que cette étape est effective, passons à la compilation.

### 2. Compiler le programme

Pour compiler, il suffit d'ouvrir votre terminal préféré (ci-possible un terminal bash, shell, zsh...), puis de rentrer la commande

```bash
make
```

Et voilà, s'il n'y a pas de message d'erreur, on va pouvoir passer à la suite

### 3. Exécuter le programme

La compilation a produit un exécutable `demineur` pour un système Unix (Linux/macOS) et `demineur.exe` pour Windows.
Sur un système Unix, pour exécuter `demineur`, il suffit de rentrer la commande suivante :

```bash
./demineur
````

Pour Windows, c'est presque pareil :

```bash
demineur.exe
```

Et voilà, le programme est maintenant lancé et on peut enfin jouer au démineur !

### 4. Interagir avec le programme

Une fois ce dernier ouvert, nul besoin d'appeler une quelconque fonction ou de faire des modifications du programme avant de le compiler, il fonctionne de fonction autonome.
Pour jouer, il suffit de suivre les consignes données par le jeu, et de profiter, en essayant de gagner !

### 5. Supprimer l'exécutable

Si jamais le besoin vient de supprimer l'exécutable car la compilation a mal marché ou que des modifications dans le code ont été faites, il suffit sur Unix de rentrer la commande

```bash
make clean
```

ou sur Windows de supprimer l'exécutable directement.

## Fonctionnalités du programme

Le jeu du démineur est **100%** fonctionnel, cependant voici quand même une liste *non-exhaustive* des fonctionnalités du programme :

- l'utilisateur peut choisir un niveau de difficulté avec des tailles de grille et des nombres de bombes différents
- l'utilisateur peut choisir de crééer une grille aléatoire de la taille voulu (*min 2x2, max 100x100*) avec le nombre de bombes voulues (*min 1, max inférieur au nombre de cases*)
- l'utilisateur peut creuser (découvrir une case)
- l'utilisateur peut poser et enlever des drapeaux
- l'utilisateur peut demander à (re)afficher les commandes

Toute interaction avec le programme est pris en compte, même les mauvaises entrées ou les entrées multiples, qui prennent alors le premier caractère rentré. En cas d'erreur, soit le jeu redemande à l'utilisateur de rentrer une commande, soit il réalise une action par défaut.

La partie se finit lorsque toutes les cases ne contenant pas de bombes sont découvertes, auquel cas l'utilisateur gagne, ou lorsque l'utilisateur découvre une case ayant une bombe, auquel cas il perd la partie.

## Code source

Le code source complet se trouve sur [ce repository GitHub](https://github.com/S-c-r-a-t-c-h-y/Demineur-en-C).
