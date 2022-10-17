#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

    return matrice;
}

void initialiser_tableau_courant(int **tab, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = PAS_TROUVE;
        }
    }
}

void initialiser_tableau_solution(int **tab, int m, int n, int nombre_bombes)
{
    srand(time(NULL));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = PAS_TROUVE;
        }
    }

    // place les bombes dans la grille
    for (int k = 0; k < nombre_bombes; k++)
    {
        int x = rand() % n;
        int y = rand() % m;
        while (tab[y][x] == BOMBE)
        {
            x = rand() % n;
            y = rand() % m;
        }
        tab[y][x] = BOMBE;
    }

    // calcul les nombres pour toutes les autres cases
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            printf("%d %d", y, x);
            if (tab[y][x] == BOMBE)
            {
                continue;
            }
            int bombes_voisines = 0;
            for (int i = y - 1; i < y + 2; i++)
            {
                if (i < 0 || i >= m)
                {
                    continue;
                }
                for (int j = x - 1; j < x + 2; x++)
                {
                    if (j < 0 || j >= n)
                    {
                        continue;
                    }
                    if (tab[i][j] == BOMBE)
                    {
                        bombes_voisines += 1;
                    }
                }
            }
            tab[y][x] = bombes_voisines;
        }
    }
}