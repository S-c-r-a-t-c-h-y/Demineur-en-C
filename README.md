# Démineur en C

Grâce à ces fichiers, vous pourrez jouer à une adaptation du démineur en C et dans un terminal uniquement (sans interface graphique).

## Comment jouer au jeu ?

### 1. Vérifier si GCC est installé

C'est très simple à partir du moment où vous avez le [compilateur GCC](https://gcc.gnu.org/install/) à votre diposition et ce peut-importe l'OS que vous utilisez.
Pour cela sous Linux/macOS ouvrez votre meilleur terminal et tapez 
```bash
which gcc
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
````
Et voilà, le programme est maintenant lancé et on peut enfin jouer au démineur !
