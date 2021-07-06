#include "entreeSortieLC.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioLC.h"

Biblio* charger_n_entrees(char* nomfic, int n){

	Biblio *b = creer_biblio();

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

		inserer_en_tete(b,num,titre,auteur);

		cpt++;
	}

	fclose(f);

	return b;
}

void enregistrer_biblio(Biblio *b, char* nomfic){

	if (b==NULL) return;

	FILE *f = fopen(nomfic,"w");

	if (f==NULL){

		fprintf(stderr,"\nErreur: Impossible d'ouvrir le fichier %s\n",nomfic);

		exit(EXIT_FAILURE);
	}

	Livre* livre = b -> L;

	for(; livre; livre = livre -> suiv){

		fprintf(f,"%d %s %s\n",livre -> num, livre -> titre, livre -> auteur);

	}
	fclose(f);

}

