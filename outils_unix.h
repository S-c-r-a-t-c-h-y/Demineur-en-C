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

/*
 */
void action_clavier(int **tab_sol, int **tab, int m, int n, int *position, int *ancienne_var, char key_pressed, int *death_wave, int *compteur_flag, int *cases_restantes);

/* Fonction non utilisées autre part que dans le fichier outils présentes ici uniquement pour la documentation */
/* ########################################################################################################### */

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
void dig_hole(int **tab_sol, int **tab, int m, int n, int *position, int *ancienne_var, int *death_wave, int *cases_restantes);
void put_flag(int **tab, int m, int n, int *position, int *compteur_flag);
void deplace_pointeur(int **tab, int m, int n, int *position, int *ancienne_var);
void help(int **tab, int m, int n);