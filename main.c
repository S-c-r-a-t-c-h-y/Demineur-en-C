#include <stdlib.h>
#include <stdio.h>
#include "outils.h"

int main()
{
    int m = 3;
    int n = 4;

    int **tab = creer_tableau(2, 3);
    int **tab2 = creer_tableau(m, n);

    initialiser_tableau_solution(tab2, m, n, 3);

    // tab[0][0] = -1;
    // tab[0][1] = 0;
    // tab[0][2] = -2;
    // tab[1][0] = 2;
    // tab[1][1] = 3;
    // tab[1][2] = -3;

    // affiche_tableau(tab, 2, 3);
    affiche_tableau(tab2, m, n);

    for (int i = 0; i < 2; i++)
    {
        free(tab[i]);
    }
    free(tab);

    for (int i = 0; i < m; i++)
    {
        free(tab2[i]);
    }
    free(tab2);
    return 0;
}