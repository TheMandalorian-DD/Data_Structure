#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre* creer_livre(int num,char* titre,char* auteur){
	Livre* livre = (Livre*)malloc(sizeof(Livre));
	livre -> num = num;
	livre -> titre = strdup(titre);
	livre -> auteur = strdup(auteur);
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
	Livre* livre = creer_livre(num,titre,auteur);
	if (b -> L==NULL){
		b -> L = livre;
	}
	livre -> suiv = b -> L;
	b -> L = livre;
}




