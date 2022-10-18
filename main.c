#include <stdlib.h>
#include <stdio.h>
#include "outils.h"

int main()
{
    int m = 10; // nombre de lignes du tableau
    int n = 10; // nombre de colonnes du tableau

    int nb_bombes = 10; // nombre de bombe dans le tableau

    // le tableau solution contient les bombes et les numéros des cases
    int **tableau_solution = creer_tableau(m, n);
    initialiser_tableau_solution(tableau_solution, m, n, nb_bombes);

    int **tableau_courant = creer_tableau(m, n);
    initialiser_tableau_courant(tableau_courant, m, n);

    affiche_tableau(tableau_courant, m, n);

    // while (nb_bombes != 0)
    // {
    //     // boucle principale
    // }

    liberer_tableau(tableau_solution, m);
    return 0;
}