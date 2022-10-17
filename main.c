#include <stdlib.h>
#include <stdio.h>
#include "outils.h"

int main()
{
    int **tab = creer_tableau(2, 3);

    tab[0][0] = -1;
    tab[0][1] = 0;
    tab[0][2] = -2;
    tab[1][0] = 2;
    tab[1][1] = 3;
    tab[1][2] = -3;

    affiche_tableau(tab, 2, 3);

    for (int i = 0; i < 2; i++)
    {
        free(tab[i]);
    }
    free(tab);
    return 0;
}