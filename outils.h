void clear_screen();
void affiche_tableau(int **tab, int hauteur, int largeur);
int **creer_tableau(int m, int n);
void initialiser_tableau_courant(int **tab, int m, int n);
void initialiser_tableau_solution(int **tab, int m, int n, int nombre_bombes);
void liberer_tableau(int **tab, int m);
void print_unicode(int unicode_code);
int decouvrir_case(int **tableau_courant, int **tableau_solution, int m, int n, int y, int x);