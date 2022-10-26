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
    printf("Utilises les touches\n-Z,Q,S,D pour te déplacer,\n-@ pour creuser,\n-& pour mettre un drapeau\n");
    printf("Si durant le jeu tu ne te rappelles plus de ces commandes,\ntapes ! pour qu'elles te soient rappellees\n");
    printf("Tu es prêt ?\nAppuies sur n'importe quelle touche pour commencer puis appuie sur la touche Entree : ");
    char temp_buffer[64];
    scanf("%s", temp_buffer);
    clear_screen();
    affiche_tableau(tableau_courant, m, n);
    printf("Voici ton tableau de jeu, tu pars d'en haut à gauche\n");
    while (*death_wave != 1 && jeu_fini(tableau_solution, tableau_courant, m, n) != 1)
    {
        printf("Tapes Z,Q,S,D ou @,& ou bien !, puis Entree : ");
        scanf("%255s", buffer);
        action_clavier(tableau_solution, tableau_courant, m, n, position, temp_val_case, buffer[0], death_wave);
    }
    if (*death_wave)
    {
        printf("Oh non je suis si triste tu as perdu ;(\n");
        printf("Souhaites tu recommencer ?\n");
        // Demander oui non
    }
    else
    {
        printf("Bravo, tu as gagne ;)\n");
        printf("J'espere que tu n'es pas un nostalgique de MS-DOS, parce que Linux c'est mieux ;)\n");
    }
    printf("A une prochaine fois peut-être !\n");
    liberer_tableau(tableau_solution, m);
    liberer_tableau(tableau_courant, m);
}

void initialisation_plateau() 
{
    char buffer_partie[64];
    printf("Que souhaites tu faire ?\nChoisis un nombre entre 1 et 6 : ");
    scanf("%s", buffer_partie);
    int bombes = 21; // nombre de bombes dans le tableau
    int m = 21;      // nombre de lignes du tableau
    int n = 21;      // nombre de colonnes du tableau
    switch (buffer_partie[0])
    {
    case '1':
        printf("Ok on y va pour une partie facile !\n");
        m = 5;
        n = 5;
        bombes = 5;
        break;
    case '2':
        printf("Ok on y va pour une partie moyenne !\n");
        m = 7;
        n = 7;
        bombes = 10;
        break;
    case '3':
        printf("Ok on y va pour une partie dure !\n");
        m = 10;
        n = 10;
        bombes = 21;
        break;
    case '4':
        printf("Ok on y va pour une partie horrible !\n");
        m = 15;
        n = 15;
        bombes = 42;
        break;
    case '5':
        printf("Ok on y va pour une partie infaisable !\n");
        m = 21;
        n = 21;
        bombes = 84;
        break;
    case '6':
        printf("Ok tu es donc prêt à trifouiller le système, à tes risques et perils !\n");
        printf("Pour des raisons de confort d'utilisation, la selection est limitee a 100x100 cases maximum et 1000 bombes\n");
        break;
    default:
        printf("Mmm, je ne suis pas sur que %c, soit un nombre entre 1 et 6, reessayons !\n", buffer_partie[0]);
        initialisation_plateau();
        break;
    }
    // le tableau solution contient les bombes et les numéros des cases
    int **tableau_solution = creer_tableau(m, n);
    initialiser_tableau_solution(tableau_solution, m, n, bombes);

    // le tableau courant est le plateau de jeu vu par le joueur, qui est donc découvert au fur et à mesure
    int **tableau_courant = creer_tableau(m, n);
    initialiser_tableau_courant(tableau_courant, m, n);

    int temp_val = tableau_courant[0][0]; // on recupere la valeur de la position actuelle (par défaut la case de coordonnées (0,0))
    int *position = (int *)malloc(sizeof(int) * 2); // on crée le tableau qui stockera la position du pointeur
    position[0] = 0; // correspond au y
    position[1] = 0; // correspond au x
    int *temp_val_case = &temp_val;
    jeu(tableau_solution, tableau_courant, m, n, position, temp_val_case);
}

void start() 
{
    printf("##########-DEMINEUR-##########\n");
    printf("Choix de la partie:\n");
    printf("1-----FACILE-----");
    printf("Un jeu de 5x5 cases, 5 mines\n");
    printf("2-----MOYEN-----");
    printf("Un jeu de 7x7 cases, 10 mines\n");
    printf("3-----DUR-----");
    printf("Un jeu de 10x10 cases, 21 mines\n");
    printf("4-----HORRIBLE-----");
    printf("Un jeu de 15x15 cases, 42 mines\n");
    printf("5-----INFAISABLE-----");
    printf("Un jeu de 21x21 cases, 84 mines\n");
    printf("6-----MA PROPRE PARTIE-----");
    printf("Choisis tes cases et tes mines\n");
    initialisation_plateau();
}

int main()
{
    start();
    
    return 0;
}
