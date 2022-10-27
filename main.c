#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include "outils_win.h"
#else
#include "outils_unix.h"
#endif

void jeu(int **tableau_solution, int **tableau_courant, int m, int n, int bombes, int *position, int *temp_val_case)
{
    char buffer[256];
    int dead = 0;
    int flag = 0;
    int *compteur_flag = &flag;
    int *death_wave = &dead;
    printf("Utilises les touches\n-Z,Q,S,D pour te deplacer,\n-@ pour creuser,\n-& pour mettre un drapeau\n");
    printf("Si durant le jeu tu ne te rappelles plus de ces commandes,\ntapes ! pour qu'elles te soient rappellees\n");
    printf("\nTu es pret ?\nAppuies sur n'importe quelle touche pour commencer,\npuis appuie sur la touche Entree : ");
    char temp_buffer[64];
    scanf("%s", temp_buffer);
    clear_screen();
    affiche_tableau(tableau_courant, m, n);
    printf("Voici ton tableau de jeu, tu pars d'en haut a gauche\n");
    while (*death_wave != 1 && jeu_fini(tableau_solution, tableau_courant, m, n) != 1 && *compteur_flag != bombes)
    {
        printf("Tu as posé %d/%d drapeaux\n", *compteur_flag, bombes);
        printf("Tapes Z,Q,S,D ou @,& ou bien !, puis Entree : ");
        scanf("%255s", buffer);
        action_clavier(tableau_solution, tableau_courant, m, n, position, temp_val_case, buffer[0], death_wave, compteur_flag);
    }
    liberer_tableau(tableau_solution, m);
    liberer_tableau(tableau_courant, m);
    if (*death_wave)
    {
        printf("Oh non je suis si triste tu as perdu ;(\n");
    }
    else
    {
        printf("Bravo, tu as gagne ;)\n");
        printf("J'espere que tu n'es pas un nostalgique de MS-DOS,\nParce que Linux c'est mieux ;)\n");
    }
    printf("A une prochaine fois peut-etre !\n");
}

void selection_user(int *p_m, int *p_n, int *p_bombes)
{
    printf("\n");
    printf("Combien de lignes ? ");
    scanf("%d", p_m);
    printf("Combien de colonnes ? ");
    scanf("%d", p_n);
    printf("Combien de bombes ? ");
    scanf("%d", p_bombes);
    if (*p_m > 100 || *p_n > 100 || *p_m < 2 || *p_n < 2 || *p_bombes >= (*p_m) * (*p_n) || *p_bombes < 1)
    {
        printf("Tu ne m'as pas ecoute,\nTant pis, on recommence\n");
        selection_user(p_m, p_n, p_bombes);
    }
    else
    {
        clear_screen();
        printf("Ok, c'est parti pour un plateau de %dx%d,\net de %d bombes !\n", *p_m, *p_n, *p_bombes);
    }
}

void initialisation_plateau()
{
    char buffer_partie[64];
    printf("Que souhaites tu faire ?\nChoisis un nombre entre 1 et 6 : ");
    scanf("%s", buffer_partie);
    int bombes = 20; // nombre de bombes dans le tableau
    int m = 10;      // nombre de lignes du tableau
    int n = 10;      // nombre de colonnes du tableau
    switch (buffer_partie[0])
    {
    case '1':
        clear_screen();
        printf("Ok on y va pour une partie facile !\n");
        m = 5;
        n = 5;
        bombes = 5;
        break;
    case '2':
        clear_screen();
        printf("Ok on y va pour une partie moyenne !\n");
        m = 7;
        n = 7;
        bombes = 10;
        break;
    case '3':
        clear_screen();
        printf("Ok on y va pour une partie dure !\n");
        m = 10;
        n = 10;
        bombes = 21;
        break;
    case '4':
        clear_screen();
        printf("Ok on y va pour une partie horrible !\n");
        m = 15;
        n = 15;
        bombes = 42;
        break;
    case '5':
        clear_screen();
        printf("Ok on y va pour une partie infaisable !\n");
        m = 21;
        n = 21;
        bombes = 84;
        break;
    case '6':
        clear_screen();
        printf("Ok tu es donc pret a trifouiller le systeme,\na tes risques et perils !\n");
        printf("Pour des raisons de confort d'utilisation,\nla selection est limitee a 100x100 cases maximum,\net bien evidemment,\nil ne faut pas qu'il y ait plus de bombes\nque de cases !\n");
        selection_user(&m, &n, &bombes);
        break;
    default:
        printf("Mmm, je ne suis pas sur que %c\nsoit un nombre entre 1 et 6, reessayons !\n", buffer_partie[0]);
        initialisation_plateau();
        break;
    }
    // le tableau solution contient les bombes et les numéros des cases
    int **tableau_solution = creer_tableau(m, n);
    initialiser_tableau_solution(tableau_solution, m, n, bombes);

    // le tableau courant est le plateau de jeu vu par le joueur, qui est donc découvert au fur et à mesure
    int **tableau_courant = creer_tableau(m, n);
    initialiser_tableau_courant(tableau_courant, m, n);

    int temp_val = -3;                              // on recupere la valeur de la position actuelle (par défaut la case de coordonnées (0,0)) qui vaut -3 au début du jeu (par convention)
    int *position = (int *)malloc(sizeof(int) * 2); // on crée le tableau qui stockera la position du pointeur
    position[0] = 0;                                // correspond au y
    position[1] = 0;                                // correspond au x
    int *temp_val_case = &temp_val;
    jeu(tableau_solution, tableau_courant, m, n, bombes, position, temp_val_case);
}

void start()
{
    clear_screen();
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
