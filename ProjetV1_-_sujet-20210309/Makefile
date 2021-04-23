CC = gcc
CFLAGS = -Wall -Wextra -pedantic -lm
objectsChaine = ChaineMain.o Chaine.o SVGwriter.o
objects = ReconstitueReseau.o Reseau.o SVGwriter.o Chaine.o

Chaine : $(objectsChaine)
	$(CC) -o $@ $(CFLAGS) $(objectsChaine)

ReconstitueReseau : $(objects)
	$(CC) -o $@ $(CFLAGS) $(objects)

.PHONY : clean
clean :
	-rm Chaine $(objectsChaine) 
	-rm ReconstitueReseau $(objects) 

	