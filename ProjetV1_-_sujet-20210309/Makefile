CC = gcc
CFLAGS = -Wall -Wextra -pedantic -lm
objectsReseau = ReconstitueReseau.o Reseau.o SVGwriter.o Chaine.o
objectsHash = ReconstitueHash.o Reseau.o SVGwriter.o Chaine.o Hachage.o
objectsArbre = ReconstitueArbre.o Reseau.o SVGwriter.o Chaine.o ArbreQuat.o

ReconstitueArbre : $(objectsArbre)
	$(CC) -o $@ $(CFLAGS) $(objectsArbre)
ReconstitueHash : $(objetcs) $(objectsHash)
	$(CC) -o $@ $(CFLAGS) $(objetcs) $(objectsHash)
ReconstitueReseau : $(objectsReseau)
	$(CC) -o $@ $(CFLAGS) $(objectsReseau)
SVGwriter.o : SVGwriter.h
Chaine.o : Chaine.h SVGwriter.h
Reseau.o: Reseau.h Chaine.h
Hachage.o : Hachage.h Reseau.h
ArbreQuat.o : ArbreQuat.h Reseau.h
.PHONY : clean
clean :
	-rm ReconstitueArbre $(objectsArbre)
	-rm ReconstitueHash $(objectsHash)
	-rm ReconstitueReseau $(objectsReseau)
	-rm graph_arbre.html
	-rm *.res