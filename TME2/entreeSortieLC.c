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

void afficher_livre(Livre *livre){
	printf("num = %d, titre = %s, auteur = %s\n",livre -> num, livre -> titre, livre -> auteur);
}

void afficher_biblio(Biblio *b){

	Livre *livre = b -> L;

	for(; livre && strcmp(livre->auteur,"")>0; livre = livre -> suiv){

		afficher_livre(livre);
	}
}

Livre *recherche_ouvrage_num(Biblio *b, int num){

	Livre *livre = b -> L;

	for(; livre; livre = livre -> suiv){

		if (livre->num == num){

			return livre;
		}

	}
	return NULL;
}

Livre *recherche_ouvrage_titre(Biblio *b, char *titre){

	Livre *livre = b -> L;

	for(; livre; livre = livre -> suiv){

		if (strcmp(livre->titre,titre)==0){

			return livre;
		}

	}
	return NULL;
}

Biblio *recherche_meme_auteur(Biblio *b, char *auteur){

	Biblio *bi = creer_biblio();

	Livre *livre = b -> L;

	for(; livre; livre = livre -> suiv){

		if (strcmp(livre->auteur,auteur)==0){

			inserer_en_tete(bi, livre->num, livre->titre, livre->auteur);
		}
	}
	return bi;
}

Biblio *supprimer_livre(Biblio *b, int num, char *titre, char *auteur){

	Livre *livre = b -> L;

	if ((livre->num == num) && strcmp(livre->titre,titre)==0 && strcmp(livre->auteur,auteur)==0){

		b -> L = livre -> suiv;

		liberer_livre(livre);
	}
	
	Livre* l=livre->suiv;

    while(l){

        if(strcmp(l->titre,titre)==0 && strcmp(l->auteur,auteur)==0 && l->num==num){

            Livre* l1=l->suiv;

            liberer_livre(l);

            livre->suiv=l1;

        }

        l=l->suiv;

        livre=livre->suiv;
    }
    return b;
}

Biblio *fusion(Biblio *b1, Biblio *b2){

	Biblio *bi = creer_biblio();

	Livre *livre1 = b1 -> L;

	Livre *livre2 = b2 -> L;
	
	if (livre1==NULL) return b2;

	if (livre2==NULL) return b1;

	Livre *tmp = livre1;
	
	for(;tmp ;tmp = tmp -> suiv);
	
	tmp -> suiv = livre2;

	bi -> L = livre1;

	return bi;
	
}


int main(){

	Biblio *b=charger_n_entrees("GdeBiblio.txt",5);

	Biblio *b1 = charger_n_entrees("GdeBiblio.txt",9);

	//b=supprimer_livre(b,4,"FWKHOPKMCOQHNWNKUE", "hsqmgbbuqcl");
 
    //afficher_biblio(b);

	Biblio *bt = fusion_biblio(b,b1);

	afficher_biblio(bt);

    //enregistrer_biblio(b,"bibi.txt");
}
