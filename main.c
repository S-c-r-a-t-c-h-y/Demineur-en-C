#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include "outils_win.h"
#else
#include "outils_unix.h"
#endif

int main()
{
    int m = 10;         // nombre de lignes du tableau
    int n = 10;         // nombre de colonnes du tableau
    int nb_bombes = 20; // nombre de bombe dans le tableau

    // le tableau solution contient les bombes et les numéros des cases
    int **tableau_solution = creer_tableau(m, n);
    initialiser_tableau_solution(tableau_solution, m, n, nb_bombes);

    int **tableau_courant = creer_tableau(m, n);
    initialiser_tableau_courant(tableau_courant, m, n);
    int temp_val = tableau_courant[0][0];
    int *position = (int *)malloc(sizeof(int) * 2);
    position[0] = 0; // y
    position[1] = 0; // x
    int *temp_val_case = &temp_val;
    tableau_courant[0][0] = -5;
    affiche_tableau(tableau_solution, m, n);
    affiche_tableau(tableau_courant, m, n);
    char buffer[256];
    while (1) {
        printf("Où souhaitez-vous aller ? ");
        scanf("%255s", buffer);
        printf("Lettre choisie %c, n'est pas ?\n", buffer[0]);
        deplace_pointeur(tableau_courant, m, n, position, temp_val_case, buffer[0]);
    }
    
    
    char nom[50];
    char prenom[50];
    int res;
    printf("Saisissez votre nom suivi de votre prénom : ");
    res = scanf("%49s%49s", nom, prenom);
    if(res == 2)
        printf("Vous vous appelez %s %s, est-ce correct ?\n", prenom, nom);
    else
        printf("Vous avez fait une erreur lors de la saisie.\n");
    /*char buffer[256];
    printf("Entre une lettre : \n");
    scanf("%s", buffer);
    printf("%s", buffer);*/
    /*while (longueur(buffer, 256) > 1)
    {
        printf("Entre une seule lettre : \n");
        scanf("%s", buffer);
    }*/
    /*while (!isalpha(buffer[0]))
    {
        printf("Entre une lettre de l'alphabet : \n");
        scanf("%s", buffer);
    }*/
    printf("ici");
    printf("Ou souhaitez vous aller ? ");
    printf("ici2 ");
    /*deplace_pointeur(tableau_courant, m, n, 0, 0, temp_val_case, buffer[0]);*/

    affiche_tableau(tableau_courant, m, n);
    printf("%d\n", decouvrir_case(tableau_courant, tableau_solution, m, n, 0, 0));

    affiche_tableau(tableau_courant, m, n);

    liberer_tableau(tableau_solution, m);
    return 0;
}
