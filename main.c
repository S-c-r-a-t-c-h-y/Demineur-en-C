#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include "outils_win.h"
#else
#include "outils_unix.h"
#endif

int main()
{
    int m = 10; // nombre de lignes du tableau
    int n = 10; // nombre de colonnes du tableau
    int nb_bombes = 20; // nombre de bombe dans le tableau

    // le tableau solution contient les bombes et les numéros des cases
    int **tableau_solution = creer_tableau(m, n);
    initialiser_tableau_solution(tableau_solution, m, n, nb_bombes);

    int **tableau_courant = creer_tableau(m, n);
    initialiser_tableau_courant(tableau_courant, m, n);
    int temp_case = tableau_courant[0][0];
    int *position_case_actuelle = &tableau_courant[0][0];
    *position_case_actuelle = -5;
    
    affiche_tableau(tableau_solution, m, n);
    *position_case_actuelle = temp_case;
    affiche_tableau(tableau_courant, m, n);
    printf("%d\n", decouvrir_case(tableau_courant, tableau_solution, m, n, 0, 0));

    affiche_tableau(tableau_courant, m, n);

    liberer_tableau(tableau_solution, m);
    return 0;
}
