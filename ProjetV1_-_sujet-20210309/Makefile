# CC = gcc
# CFLAGS = -Wall -Wextra -pedantic -lm
# objectsChaine = ChaineMain.o SVGwriter.o Chaine.o
# objectsReseau = ReconstitueReseau.o Reseau.o SVGwriter.o Chaine.o
# objectsHash = ReconstitueHash.o Reseau.o SVGwriter.o Chaine.o Hachage.o
# objectsArbre = ReconstitueArbre.o Reseau.o SVGwriter.o Chaine.o ArbreQuat.o
# objectsTime = TimeTest.o Reseau.o SVGwriter.o Chaine.o Hachage.o ArbreQuat.o
# objectsGraphe = ReorganiseReseau.o Graphe.o Struct_File.o Struct_Liste.o

# TimeTest : $(objectsTime)
# 	$(CC) -o $@ $(CFLAGS) $(objectsTime)
# ReconstitueArbre : $(objectsArbre)
# 	$(CC) -o $@ $(CFLAGS) $(objectsArbre)
# ReconstitueHash : $(objectsHash)
# 	$(CC) -o $@ $(CFLAGS) $(objectsHash)
# ReconstitueReseau : $(objectsReseau)
# 	$(CC) -o $@ $(CFLAGS) $(objectsReseau)
# ChaineMain : $(objectsChaine)
# 	$(CC) -o $@ $(CFLAGS) $(objectsChaine)
# ReorganiseReseau : $(objectsGraphe)
# 	$(CC) -o $@ $(CFLAGS) $(objectsGraphe)

# SVGwriter.o : SVGwriter.h
# Chaine.o : Chaine.h SVGwriter.h
# Reseau.o: Reseau.h Chaine.h
# Hachage.o : Hachage.h Reseau.h
# ArbreQuat.o : ArbreQuat.h Reseau.h
# Graphe.o : Graphe.h Struct_File.h Struct_Liste.h
# .PHONY : clean
# clean :	
# 	-rm ReorganiseReseau $(objectsGraphe)
# 	-rm TimeTest $(objectsTime)
# 	-rm ReconstitueArbre $(objectsArbre)
# 	-rm ReconstitueHash $(objectsHash)
# 	-rm ReconstitueReseau $(objectsReseau)
# 	-rm ChaineMain $(objectsChaine)
 
CC = gcc
CFLAGS = -g -Wall -Wextra -pedantic
objects = ArbreQuat.o Hachage.o Reseau.o Chaine.o SVGwriter.o
objectsReconstitue = ReconstitueReseau.o
objectsTime = TimeTest.o
objectsGraphe = ReorganiseReseau.o Graphe.o Struct_File.o Struct_Liste.o
objectslist = $(objects) $(objectsReconstitue) $(objectsTime) $(objectsGraphe) ChaineMain.o
all = ChaineMain ReconstitueReseau Time ReorganiseReseau

prog: $(all) 
ChaineMain : ChaineMain.o Chaine.o SVGwriter.o
	gcc -Wall -ggdb -o ChaineMain ChaineMain.o Chaine.o SVGwriter.o -lm
ReconstitueReseau: $(objects) $(objectsReconstitue)
	$(CC) -o $@ $(CFLAGS) $(objects) $(objectsReconstitue) -lm
Time: $(objects) $(objects) $(objectsTime)
	$(CC) -o $@ $(CFLAGS) $(objects) $(objectsTime) -lm
ReorganiseReseau: $(objects) $(objectsGraphe)
	$(CC) -o $@ $(CFLAGS) $(objects) $(objectsGraphe) -lm
SVGwriter.o : SVGwriter.h
Reseau.o: Reseau.h Chaine.h
Hachage.o : Hachage.h Reseau.h
ArbreQuat.o : ArbreQuat.h Reseau.h
Graphe.o : Graphe.h Struct_File.h Struct_Liste.h
.PHONY : clean
clean :
	-rm $(all) $(objectslist)
	-rm exemple.res
	-rm *.html