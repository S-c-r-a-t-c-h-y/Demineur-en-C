#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include "outils_win.h"
#else
#include "outils_unix.h"
#endif

void jeu(int **tableau_solution, int **tableau_courant, int m, int n, int *position, int *temp_val_case)
{
    char buffer[256];
    int dead = 0;
    int flag = 0;
    int *compteur_flag = &flag;
    int *death_wave = &dead;

    while (*death_wave != 1 && jeu_fini(tableau_solution, tableau_courant, m, n) != 1)
    {
        printf("Ou souhaitez-vous aller ? ");
        scanf("%255s", buffer);
        action_clavier(tableau_solution, tableau_courant, m, n, position, temp_val_case, buffer[0], death_wave);
        //*temp_val_case = tableau_courant[position[0]][position[1]];
    }
    if (*death_wave)
    {
        printf("Tu as perdu ;(\n");
    }
    else
    {
        printf("Tu as gagné ;)\n");
    }
}

int main()
{
    int m = 10;         // nombre de lignes du tableau
    int n = 10;         // nombre de colonnes du tableau
    int nb_bombes = 20; // nombre de bombe dans le tableau

    // le tableau solution contient les bombes et les numéros des cases
    int **tableau_solution = creer_tableau(m, n);
    initialiser_tableau_solution(tableau_solution, m, n, nb_bombes);

    // le tableau courant est le plateau de jeu vu par le joueur, qui est donc découvert au fur et à mesure
    int **tableau_courant = creer_tableau(m, n);
    initialiser_tableau_courant(tableau_courant, m, n);
    int temp_val = tableau_courant[0][0];
    int *position = (int *)malloc(sizeof(int) * 2);
    position[0] = 0; // y
    position[1] = 0; // x
    int *temp_val_case = &temp_val;
    // tableau_courant[0][0] = -5;
    affiche_tableau(tableau_solution, m, n);
    affiche_tableau(tableau_courant, m, n);
    jeu(tableau_solution, tableau_courant, m, n, position, temp_val_case);

    liberer_tableau(tableau_solution, m);
    liberer_tableau(tableau_courant, m);
    return 0;
}
