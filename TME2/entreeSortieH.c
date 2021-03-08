#include "entreeSortieH.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioH.h"

/* retourne un entier (taille de hachage) adapté à la bibliothèque selon le nombre d'ouvrage */

int getHashSize(int n) {
	
	for (int i = 0; i < PRIMESIZE; i++) {
		
		if (n < PrimeList[i] * 0.75) return PrimeList[i];
		
	}

	return PrimeList[PRIMESIZE - 1];
}

/* retourne une bibliothèque d'ouvrages lue dans un fichier et de taille n passés en paramètre */

BiblioH* charger_n_entrees(char* nomfic, int n){

	BiblioH *bh = creer_biblioH(getHashSize(n));

	FILE *f = fopen(nomfic,"r");

	if (f==NULL){

		fprintf(stderr,"\nErreur: Impossible de lire le fichier %s\n",nomfic);

		exit(EXIT_FAILURE);
	}

	char ligne[256];
	char titre[256];
	char auteur[256];
	int num, cpt=0;

	while(fgets(ligne,256,f) && cpt != n){

		sscanf(ligne, "%d %s %s",&num,titre,auteur);

		inserer(bh,num,titre,auteur);

		cpt++;
	}

	fclose(f);

	return bh;
}

/* stock une bibliothèque passé en paramètre dans un fichier 'nomfic' */

void enregistrer_biblioH(BiblioH *bh, char* nomfic){

	if (bh==NULL) return;

	FILE *f = fopen(nomfic,"w");

	if (f==NULL){

		fprintf(stderr,"\nErreur: Impossible d'ouvrir le fichier %s\n",nomfic);

		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < bh->m; i++){
		
		for(LivreH* lh = bh -> T[i]; lh; lh = lh -> suivant){
			
			fprintf(f,"%d %s %s\n",lh -> num, lh -> titre, lh -> auteur);
			
		}
		
	}

    fclose(f);
}
