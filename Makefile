# Compilation de fichiers pour construire des programmes.
# Vous pouvez rajouter des commentaires en utilisant le symbole #

# Donner ci-dessous le du fichier source principal
NOM_FICHIER= main.c

# Donner ci-dessous le nom des fichiers intermédiaires à générer
# Si vous indiquez un nom de module ici, cela sous-entend que votre programme
# fait appel à des fonctions déclarées dans un fichier .h et définies dans un
# fichier .c de même nom de base que celui du fichier objet généré en .o.
# Nom de base : nom du fichier sans extension.
OBJETS = outils.o

# Donner ci-dessous le nom du fichier exécutable à produire
NOM_EXECUTABLE= demineur

# Ligne ci-dessous à conserver
OPTIONS = -std=c99 -Wall -Wextra -Wvla #-fsanitize=address,undefined

# Règle principale
all: $(NOM_EXECUTABLE)

%.o : %.c %.h
	gcc -c $< $(OPTIONS)

$(NOM_EXECUTABLE): $(NOM_FICHIER) $(OBJETS)
	gcc -o $(NOM_EXECUTABLE) $(OPTIONS) $(OBJETS) $(NOM_FICHIER)


