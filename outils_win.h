/* Fonction qui efface le contenu de la console
 */
void clear_screen();

/* Affiche le tableau à deux dimensions passé en paramètre (grille de démineur)
 * en suivant certaines conventions pour la représentation de certains caractères
 * de la grille.
 * Entrées : tab un pointeur vers le tableau en question,
 *           hauteur et largeur les dimensions du tableau
 * Sortie : la grille de démineur est affichée dans la console
 */
void affiche_tableau(int **tab, int hauteur, int largeur);

/* Créé un tableau à deux dimensions suivant ses dimensions à l'aide de malloc.
 * Entrées : m le nombre de lignes du tableau,
 *           n le nombre de colonnes
 * Sortie : un pointeur vers le tableau créé
 */
int **creer_tableau(int m, int n);

/* Rempli le tableau courant (grille 2D) avec un valeur par défaut (PAS_DECOUVERT)
 * Entrées : tab un pointeur vers le tableau en question
 *           m le nombre de lignes du tableau,
 *           n le nombre de colonnes
 * Sortie : les valeurs du tableau sont modifiées en conséquant
 */
void initialiser_tableau_courant(int **tab, int m, int n);

/* Rempli le tableau solution (grille 2D) avec un certain nombre de bombes,
 * puis calcul les valeurs des autres cases du tableau (nombre de bombes voisines)
 * Entrées : tab un pointeur vers le tableau en question
 *           m le nombre de lignes du tableau,
 *           n le nombre de colonnes,
 *           nombre_bombes le nombre de bombes à placer
 * Sortie : les valeurs du tableau sont modifiées en conséquant
 */
void initialiser_tableau_solution(int **tab, int m, int n, int nombre_bombes);

/* Libère l'espace mémoire occupé par la tableau à deux dimensions passé en paramètre
 * Entrées : tab un pointeur vers le tableau à libérer,
 *           m le nombre de lignes du tableau
 * Sortie : l'espace mémoire utilisé par le tableau est libéré
 */
void liberer_tableau(int **tab, int m);

/* A partir d'une entrée utilisateur (un appui sur une touche de clavier), une action est réalisée en fonction du caractère rentré
 * Entrées : tab_sol, le tableau final avec toutes les bombes placées
 *           tab, le tableau de jeu qui évolue au fil des découvertes de l'utilisateur
 *           m le nombre de lignes du tableau,
 *           n le nombre de colonnes,
 *           position, un pointeur vers un tableau qui contient 2 éléments, la ligne et la colonne actuelles du pointeur
 *           ancienne_var, un pointeur vers une variable qui contient la valeur de la case sur laquelle le pointeur se trouve (car dans tab à cette position on trouve -5, la valeur du pointeur pour l'affichage)
 *           key_pressed, une chaine de caractère qui est en fait l'entrée utilisateur, dont on récupère uniquement le premier caractère, afin de voir s'il correspond à une des actions à réaliser
 *           death_wave, un pointeur vers une variable qui vaut soit 0 si le joueur n'a pas creusé une case contenant une bombe, soit 1 si une case contenant une bombe a été créee, si une bombe est creusée, c'est perdu
 *           compteur_flag, un pointeur vers une variable qui compte le nombre de drapeaux posés, à mettre en relation avec le nombre de bombes
 *           cases_restantes, un pointeur vers une variable qui contient le nombre de cases hormis les bombes qu'il reste à découvrir
 * Sortie : En fonction de la commande rentrée, on appelle soit :
 *          - la fonction de déplacement, `deplace_pointeur`,
 *          - la fonction pour creuser une case, `dig_hole`,
 *          - la fonction pour poser un drapeau, `put_flag`,
 *          Sinon c'est que l'utilisateur n'a pas rentré la bonne commande, et dans ce cas là la fonction dit qu'elle n'a pas compris l'entrée utilisateur, et on recommence
 */
void action_clavier(int **tab_sol, int **tab, int m, int n, int *position, int *ancienne_var, char key_pressed, int *death_wave, int *compteur_flag, int *cases_restantes);

/* Fonction qui vérifie si un string est composé uniquement de chiffres
 * Entrée : s le string à vérifier
 * Sortie : 1 si le string est composé uniquement de nombres, 0 sinon
 */
int est_un_nombre(char s[]);

/* Fonction non utilisées autre part que dans le fichier outils présentes ici uniquement pour la documentation */
/* ########################################################################################################### */

/* Affiche le caractère unicode dont le code est passé en paramètre dans
 * la console (encodage UTF-16)
 * Entrée : unicode_code le code UTF-16 du caractère à afficher dans la console
 * Sortie : affiche le caractère correspondant au code unicode dans la console
 */
void print_unicode(int unicode_code);

/* Fonction appelée pour modifier les valeurs du tableau courant (tableau de jeu)
 * lorsque que l'on creuse (découvre) une certaine case
 * Entrées : tableau_courant un pointeur vers le tableau en question
 *           tableau_solution un pointeur vers le tableau rempli avec les bombes et les chiffres
 *           m le nombre de lignes du tableau,
 *           n le nombre de colonnes,
 *           y la coordonnée en y de la case à découvrir,
 *           x la coordonnée en x de la case à découvrir
 * Sortie : - si la case à découvrir est une bombe, renvoie -1 et découvre toutes les bombes du tableau
 *          - si la case à découvrir est un drapeau, renvoie 0 et ne fait rien
 *          - sinon, découvre la case aux coordonnées données et eventuellement les cases voisines s'il s'agit d'une
 *            case vide et renvoie le nombre de cases ayant été decouvertes
 */
int decouvrir_case(int **tableau_courant, int **tableau_solution, int m, int n, int y, int x);

/* Fonction appelée pour creuser une case dont on suspecte qu'elle ne contient pas une bombe
 * Entrées : tab_sol, le tableau final avec toutes les bombes placées
 *           tab, le tableau de jeu qui évolue au fil des découvertes de l'utilisateur
 *           m le nombre de lignes du tableau,
 *           n le nombre de colonnes,
 *           position, un pointeur vers un tableau qui contient 2 éléments, la ligne et la colonne actuelles du pointeur
 *           ancienne_var, un pointeur vers une variable qui contient la valeur de la case sur laquelle le pointeur se trouve (car dans tab à cette position on trouve -5, la valeur du pointeur pour l'affichage)
 *           death_wave, un pointeur vers une variable qui vaut soit 0 si le joueur n'a pas creusé une case contenant une bombe, soit 1 si une case contenant une bombe a été créee, si une bombe est creusée, c'est perdu
 *           cases_restantes, un pointeur vers une variable qui contient le nombre de cases hormis les bombes qu'il reste à découvrir
 * Sortie : La case a la position demandée est creusée
 *          Si c'est une bombe c'est perdu, *death_wave prend la valeur 1 et on affiche toutes les bombes du plateau,
 *          Sinon on affiche le plateau de jeu avec la case creusée et on met à jour le nombre de cases restantes
 */
void dig_hole(int **tab_sol, int **tab, int m, int n, int *position, int *ancienne_var, int *death_wave, int *cases_restantes);

/* Fonction appelée pour mettre un drapeau sur une case dont on suspecte qu'elle contient une bombe
 * Entrées : tab, le tableau de jeu qui évolue au fil des découvertes de l'utilisateur
 *           m le nombre de lignes du tableau,
 *           n le nombre de colonnes,
 *           position, un pointeur vers un tableau qui contient 2 éléments, la ligne et la colonne actuelles du pointeur
 *           compteur_flag, un pointeur vers une variable qui compte le nombre de drapeaux posés, à mettre en relation avec le nombre de bombes
 * Sortie : - Si la case n'a pas été découverte,
 *            On met à jour le nombre de drapeaux (la valeur de *compteur_flag),
 *            On met à jour la valeur de la case sur le plateau de jeu,
 *          - Si la case contient un drapeau,
 *            On fait l'inverse ;
 *            On retire un élément du nombre de drapeaux posés,
 *            On met à jour la valeur de la case pour qu'elle ait la valeur -3 (Pas découvert)
 */
void put_flag(int **tab, int m, int n, int *position, int *compteur_flag);

/* Fonction appelée pour déplacer le pointeur vers la case demandée
 * Entrées : tab, le tableau de jeu qui évolue au fil des découvertes de l'utilisateur
 *           m le nombre de lignes du tableau,
 *           n le nombre de colonnes,
 *           position, un pointeur vers un tableau qui contient 2 éléments, la ligne et la colonne actuelles du pointeur
 *           ancienne_var, un pointeur vers une variable qui contient la valeur de la case sur laquelle le pointeur se trouve (car dans tab à cette position on trouve -5, la valeur du pointeur pour l'affichage)
 * Sortie : La position du pointeur est dorénavant à la position donnée,
 *          Pour ce faire,
 *          On vérifie que la nouvelle position ne sort pas des limites du plateau, le cas échéant on la replace dans les limites,
 *          On remet l'ancienne valeur (*ancienne_var) à l'ancienne position
 *          On stocke la nouvelle valeur de la case
 *          On met le pointeur sur cette case
 *          On affiche le plateau de jeu
 */
void deplace_pointeur(int **tab, int m, int n, int *position, int *ancienne_var);

/* Fonction appelée si l'utilisateur a un doute sur les commandes à utiliser (en tapant !)
 * Entrée : Ø
 * Sortie : Rappelle comment chaque commande fonctionne
 */
void help(int **tab, int m, int n);