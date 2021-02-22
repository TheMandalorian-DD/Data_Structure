#include "biblioLC.h"
#include "entreeSortieLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre* creer_livre(int num,char* titre,char* auteur){

	Livre* livre = (Livre*)malloc(sizeof(Livre));

	if (livre==NULL) return NULL;

	livre -> titre = strdup(titre);

	if (livre->titre==NULL){

		free(livre);

		return NULL;
	}

	livre -> auteur = strdup(auteur);

	if (livre->auteur==NULL){

		free(livre->titre);

		free(livre);
		
		return NULL;
	}

	livre -> num = num;

	livre -> suiv = NULL;

	return livre;
}

void liberer_livre(Livre* l){

	free(l -> titre);

	free(l -> auteur);

	free(l);
}

Biblio* creer_biblio(){

	Biblio* b = (Biblio*)malloc(sizeof(Biblio));

	if (b==NULL) return NULL;

	b -> L = creer_livre(0,"","");

	return b;
}

void liberer_biblio(Biblio* b){

	Livre* livre = b -> L;

	while(livre) {

		Livre* tmp = livre -> suiv;

		liberer_livre(livre);

		livre = tmp;
	}

	free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){

	Livre* livre;

	if (livre=creer_livre(num,titre,auteur) == NULL) return;

	livre -> suiv = b -> L;

	b -> L = livre;
}

void afficher_livre(Livre *livre){

	if (livre==NULL) return;

	printf("num = %d, titre = %s, auteur = %s\n",livre -> num, livre -> titre, livre -> auteur);
}

void afficher_biblio(Biblio *b){

	if (b==NULL) return;

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

	if (livre->num == num && strcmp(livre->titre,titre)==0 && strcmp(livre->auteur,auteur)==0){

		b -> L = livre -> suiv;

		liberer_livre(livre);
	}
	
	Livre* l = livre -> suiv;

    while(l){

        if(l->num==num && strcmp(l->titre,titre)==0 && strcmp(l->auteur,auteur)==0){

            Livre* tmp = l -> suiv;

            liberer_livre(l);

            livre -> suiv = tmp;

        }

        l = l -> suiv;

        livre = livre -> suiv;
    }
    return b;
}

Biblio *fusion(Biblio *b1, Biblio *b2){

	if (b1 -> L == NULL) return b2;

	if (b2 -> L == NULL) return b1;

	Biblio *bi = creer_biblio();

	Livre *livre1 = b1 -> L;

	Livre *livre2 = b2 -> L;

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


