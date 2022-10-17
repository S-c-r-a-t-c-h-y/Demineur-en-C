#include <stdlib.h>
#include <stdio.h>

#define BOMBE -1
#define DRAPEAU -2
#define VIDE -3
#define PAS_TROUVE 0

const char bombe = 'x';
const char vide = ' ';
const char drapeau = 'p';
const char pas_trouve = ' ';

void affiche_tableau(int **tab, int hauteur, int largeur)
{
    for (int i = 0; i < hauteur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            switch (tab[i][j])
            {
            case BOMBE:
                printf("|%c", bombe);
                break;
            case DRAPEAU:
                printf("|%c", drapeau);
                break;
            case VIDE:
                printf("|%c", vide);
                break;
            case PAS_TROUVE:
                printf("|%c", pas_trouve);
                break;
            default:
                printf("|%d", tab[i][j]);
                break;
            }
        }
        printf("|\n");
    }
}

int **creer_tableau(int m, int n)
{
    int **matrice = (int **)malloc(sizeof(int *) * m);
    if (matrice == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < m; i++)
    {
        matrice[i] = (int *)malloc(sizeof(int) * n);
        if (matrice[i] == NULL)
        {
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrice[i][j] = 0;
        }
    }

    return matrice;
}

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