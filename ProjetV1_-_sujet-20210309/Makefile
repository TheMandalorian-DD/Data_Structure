CC = gcc
CFLAGS = -Wall -Wextra -pedantic 
objects = ArbreQuat.o Hachage.o Reseau.o Chaine.o SVGwriter.o
objectsChaine = ChaineMain.o SVGwriter.o Chaine.o
objectsReseau = ReconstitueReseau.o Reseau.o SVGwriter.o Chaine.o
objectsHash = ReconstitueHash.o Reseau.o SVGwriter.o Chaine.o Hachage.o
objectsArbre = ReconstitueArbre.o Reseau.o SVGwriter.o Chaine.o ArbreQuat.o
objectsTime = TimeTest.o Reseau.o SVGwriter.o Chaine.o Hachage.o ArbreQuat.o
objectsGraphe = ReorganiseReseau.o Graphe.o Struct_File.o Struct_Liste.o

ReorganiseReseau: $(objects) $(objectsGraphe)
	$(CC) -o $@ $(CFLAGS) $(objects) $(objectsGraphe) -lm
TimeTest : $(objectsTime)
	$(CC) -o $@ $(CFLAGS) $(objectsTime) -lm
ReconstitueArbre : $(objectsArbre)
	$(CC) -o $@ $(CFLAGS) $(objectsArbre) -lm
ReconstitueHash : $(objectsHash)
	$(CC) -o $@ $(CFLAGS) $(objectsHash) -lm
ReconstitueReseau : $(objectsReseau)
	$(CC) -o $@ $(CFLAGS) $(objectsReseau) -lm
ChaineMain : $(objectsChaine)
	$(CC) -o $@ $(CFLAGS) $(objectsChaine) -lm

SVGwriter.o : SVGwriter.h
Chaine.o : Chaine.h SVGwriter.h
Reseau.o: Reseau.h Chaine.h
Hachage.o : Hachage.h Reseau.h
ArbreQuat.o : ArbreQuat.h Reseau.h
Graphe.o : Graphe.h Struct_File.h Struct_Liste.h
.PHONY : clean
clean :	
	-rm ReorganiseReseau $(objectsGraphe)
	-rm TimeTest $(objectsTime)
	-rm ReconstitueArbre $(objectsArbre)
	-rm ReconstitueHash $(objectsHash)
	-rm ReconstitueReseau $(objectsReseau)
	-rm ChaineMain $(objectsChaine)
 
