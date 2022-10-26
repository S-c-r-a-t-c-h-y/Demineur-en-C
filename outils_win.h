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

/*
 */
void initialiser_tableau_courant(int **tab, int m, int n);

/*
 */
void initialiser_tableau_solution(int **tab, int m, int n, int nombre_bombes);

/* Libère l'espace mémoire occupé par la tableau à deux dimensions passé en paramètre
 * Entrées : tab un pointeur vers le tableau à libérer,
 *           m le nombre de lignes du tableau
 * Sortie : l'espace mémoire utilisé par le tableau est libéré
 */
void liberer_tableau(int **tab, int m);

/* Affiche le caractère unicode dont le code est passé en paramètre dans
 * la console (encodage UTF-16)
 * Entrée : unicode_code le code UTF-16 du caractère à afficher dans la console
 * Sortie : affiche le caractère correspondant au code unicode dans la console
 */
void print_unicode(int unicode_code);

/*
 */
int decouvrir_case(int **tableau_courant, int **tableau_solution, int m, int n, int y, int x);
int jeu_fini(int **tab_sol, int **tab_courant, int m, int n);
void action_clavier(int **tab_sol, int **tab, int m, int n, int *position, int *ancienne_var, char key_pressed, int *death_wave);