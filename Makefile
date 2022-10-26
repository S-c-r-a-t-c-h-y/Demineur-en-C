NOM_FICHIER= main.c

NOM_EXECUTABLE= demineur

ifeq ($(OS),Windows_NT) #Si on est sur Windows, on compile les fichiers destinés pour Windows
	OPTIONS = -std=c99 -Wall -Wextra -Wvla #-fsanitize=address,undefined
	OBJETS = outils_win.o
else 			#Si on n'est pas sur Windows, on est sur Unix on compile alors les fichiers destinés pour Unix
	OPTIONS = -std=c99 -Wall -Wextra -Wvla #-fsanitize=address,undefined
	OBJETS = outils_unix.o
endif

all: $(NOM_EXECUTABLE)

%.o : %.c %.h
	gcc -c $< $(OPTIONS)

$(NOM_EXECUTABLE): $(NOM_FICHIER) $(OBJETS)
	gcc -o $(NOM_EXECUTABLE) $(OPTIONS) $(OBJETS) $(NOM_FICHIER)

clean:
	rm -f *.o; rm -f demineur;
