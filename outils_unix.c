#include "ANSI-color-codes.h"
#include <assert.h>
#include <ctype.h> //Pour pouvoir mettre en majuscule les caractères ASCII
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>

#define UTF_16_ENCODING 0x00020000
#define NORMAL_ENCODING 0x4000

#define BOMBE -1
#define DRAPEAU -2
#define VIDE 0
#define PAS_DECOUVERT -3
#define DECOUVERT -4
#define CASE_ACTUELLE -5

#define CLEAR_SCREEN "clear"

void clear_screen()
{
	system(CLEAR_SCREEN);
}

const char *bombe = "⚙";
const char *drapeau = "⚑";
const char *pas_decouvert = "☐";
const char *case_actuelle = "◮"; //⟡
const char vide = ' ';

const char couleurs[8][8] = {BBLU, BGRN, BRED, BMAG, BYEL, BCYN, BBLK, HBLK};

void affiche_tableau(int **tab, int hauteur, int largeur)
{
	for (int i = 0; i < hauteur; i++)
	{
		for (int j = 0; j < largeur; j++)
		{
			printf(" ");
			switch (tab[i][j])
			{
			case CASE_ACTUELLE:
				printf("%s", case_actuelle);
				break;
			case BOMBE:
				printf("%s", bombe);
				break;
			case DRAPEAU:
				printf("%s", drapeau);
				break;
			case VIDE:
				printf("%c", vide);
				break;
			case PAS_DECOUVERT:
				printf("%s", pas_decouvert);
				break;
			default:
				printf("%s%d%s", couleurs[tab[i][j] - 1], tab[i][j], reset);
				break;
			}
		}
		printf("\n");
	}
}

int **
creer_tableau(int m, int n)
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
			tab[i][j] = PAS_DECOUVERT;
		}
	}
}

void initialiser_tableau_solution(int **tab, int m, int n, int nombre_bombes)
{
	// on vérifie que le nombre de bombes est bien inférieur au nombre de cases
	// du tableau
	assert(nombre_bombes < m * n);

	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = VIDE;
		}
	}

	int x;
	int y;

	// place les bombes dans la grille
	for (int k = 0; k < nombre_bombes; k++)
	{
		x = rand() % n;
		y = rand() % m;
		while (tab[y][x] == BOMBE)
		{
			x = rand() % n;
			y = rand() % m;
		}
		tab[y][x] = BOMBE;
	}

	// calcul les nombres pour toutes les autres cases
	for (y = 0; y < m; y++)
	{
		for (x = 0; x < n; x++)
		{
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
				for (int j = x - 1; j < x + 2; j++)
				{
					if (j < 0 || j >= n || (i == 0 && j == 0))
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

void _decouvrir_case(int **tableau_courant, int **tableau_solution, int m, int n, int y, int x, int iteration, int *cases_decouvertes)
{
	int valeur = tableau_solution[y][x];

	// la case à découvrir est une bombe
	if (valeur == BOMBE)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tableau_solution[i][j] == BOMBE)
				{
					tableau_courant[i][j] = BOMBE;
				}
			}
		}

		*cases_decouvertes = -1;
		return;
	}

	// la case à découvrir est un drapeau
	if (valeur == DRAPEAU)
	{
		*cases_decouvertes = 0;
		return;
	}

	// la case à découvrir est un chiffre
	if (valeur != VIDE)
	{
		if (tableau_courant[y][x] != valeur)
		{
			tableau_courant[y][x] = valeur;
			*cases_decouvertes = (*cases_decouvertes) + 1;
		}
		return;
	}

	// la case à découvrir est vide
	if (tableau_courant[y][x] == DECOUVERT)
	{
		return;
	}
	tableau_courant[y][x] = DECOUVERT;
	*cases_decouvertes = (*cases_decouvertes) + 1;
	for (int i = y - 1; i < y + 2; i++)
	{
		if (i < 0 || i >= m)
		{
			continue;
		}
		for (int j = x - 1; j < x + 2; j++)
		{
			if (j < 0 || j >= n)
			{
				continue;
			}
			_decouvrir_case(tableau_courant, tableau_solution, m, n, i, j, iteration + 1, cases_decouvertes);
		}
	}
	if (iteration == 0)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tableau_courant[i][j] == DECOUVERT)
				{
					tableau_courant[i][j] = VIDE;
				}
			}
		}
	}
}

int decouvrir_case(int **tableau_courant, int **tableau_solution, int m, int n, int y, int x)
{
	assert(x >= 0 && x < n && y >= 0 && y < m);
	int cases_decouvertes = 0;
	_decouvrir_case(tableau_courant, tableau_solution, m, n, y, x, 0,
					&cases_decouvertes);
	return cases_decouvertes;
}

void liberer_tableau(int **tab, int m)
{
	for (int i = 0; i < m; i++)
	{
		free(tab[i]);
	}
	free(tab);
}

int jeu_fini(int **tab_sol, int **tab_courant, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab_sol[i][j] == -1 && tab_courant[i][j] != -2)
			{
				return 0;
			}
			else if (tab_sol[i][j] != tab_courant[i][j] && tab_courant[i][j] != -2)
			{
				return 0;
			}
		}
	}
	return 1;
}

void dig_hole(int **tab_sol, int **tab, int m, int n, int *position, int *ancienne_var, int *death_wave)
{
	if (*ancienne_var == PAS_DECOUVERT) {
		int temp_points = decouvrir_case(tab, tab_sol, m, n, position[0], position[1]);
		affiche_tableau(tab, m, n);
		// clear_screen();
		tab[position[0]][position[1]] = tab_sol[position[0]][position[1]];
		//*ancienne_var = tab_sol[position[0]][position[1]];
		if (temp_points == -1)
		{
			*death_wave = 1;
		}
	}
}

void put_flag(int **tab, int m, int n, int *position, int *ancienne_var)
{
	//printf("La valeur de la case du drapeau est %d\n", tab[position[0]][position[1]]);
	tab[position[0]][position[1]] = DRAPEAU;
	//*ancienne_var = DRAPEAU;
	affiche_tableau(tab, m, n);
	//printf("APRES COUP, la valeur de la case du drapeau est %d\n", tab[position[0]][position[1]]);
}

void deplace_pointeur(int **tab, int m, int n, int *position, int *ancienne_var)
{
	if (position[0] < 0)
	{
		position[0] = m - 1;
	}
	else if (position[0] >= m)
	{
		position[0] = 0;
	}
	else if (position[1] < 0)
	{
		position[1] = n - 1;
	}
	else if (position[1] >= n)
	{
		position[1] = 0;
	}
	*ancienne_var = tab[position[0]][position[1]];
	tab[position[0]][position[1]] = CASE_ACTUELLE;
	affiche_tableau(tab, m, n);
}

void action_clavier(int **tab_sol, int **tab, int m, int n, int *position, int *ancienne_var, char key_pressed, int *death_wave)
{
	clear_screen();
	if (tab[position[0]][position[1]] == CASE_ACTUELLE)
	{
		tab[position[0]][position[1]] = *ancienne_var;
	}
	switch (toupper(key_pressed))
	{
	case 'Z':
		position[0]--;
		deplace_pointeur(tab, m, n, position, ancienne_var);
		break;
	case 'Q':
		position[1]--;
		deplace_pointeur(tab, m, n, position, ancienne_var);
		break;
	case 'S':
		position[0]++;
		deplace_pointeur(tab, m, n, position, ancienne_var);
		break;
	case 'D':
		position[1]++;
		deplace_pointeur(tab, m, n, position, ancienne_var);
		break;
	case '@':
		dig_hole(tab_sol, tab, m, n, position, ancienne_var, death_wave);
		// deplace_pointeur(tab, m, n, position, ancienne_var);
		break;
	case '&':
		put_flag(tab, m, n, position, ancienne_var); //ajouter compteur flag à afficher
		break;
	default: // SI autre touche rappeler fonction input deplacement
		printf("Mmm, je ne connais pas %c, peux tu réessayer ?\n",
				key_pressed);
		break;
	}
}