#include "entreeSortieLC.h"
#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Biblio* charger_n_entrees(char* nomfic, int n){

	Biblio *b = creer_biblio();

	FILE *f = fopen(nomfic,"r");

	if (f==NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		exit(1);
	}

	char ligne[100];
	char titre[50];
	char auteur[50];
	int num, cpt=0;

	while(fgets(ligne,100,f)){

		if (cpt==n) break;

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
		printf("Erreur lors de l'ouverture du fichier\n");
		exit(1);
	}

	Livre* livre = b -> L;

	for(; livre; livre = livre -> suiv){

		fprintf(f,"%d %s %s\n",livre -> num, livre -> titre, livre -> auteur);

	}

}

