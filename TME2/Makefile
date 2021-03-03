CFLAGS = -Wall -Wextra -pedantic
objects = biblioLC.o entreeSortieLC.o main.o
objects2 = biblioH.o entreeSortieH.o mainH.o

all : biblio biblioH
biblio : $(objects)
	$(CC) -o $@ $(CFLAGS) $(objects)
biblioH : $(objects2)
	$(CC) -o $@ $(CFLAGS) $(objects2)
main.o : entreeSortieLC.h biblioLC.h
mainH.o : entreeSortieH.h biblioH.h
entreeSortieLC.o : entreeSortieLC.h biblioLC.h
entreeSortieH.o : entreeSortieH.h biblioH.h
biblioLC.o : biblioLC.h
biblioH.o : biblioH.h
.PHONY : clean
clean :
	-rm biblio $(objects)
	-rm testH $(objects2)