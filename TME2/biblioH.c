#include "biblioH.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A (sqrt(5)-1) / 2

int fonctionClef(char* auteur){

    int somme = 0;

    for(int i = 0; auteur[i]!='\0'; i++){
        somme += (int)auteur[i];
    }

    return somme;
}

int fonctionHachage(int cle, int m){}

LivreH* creer_livreH(int num,char* titre,char* auteur){

    LivreH* livre = (LivreH*)malloc(sizeof(LivreH));

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

    livre -> clef = fonctionClef(auteur);

	livre -> suivant = NULL;

	return livre;
}

void liberer_livreH(LivreH** lh){
    
    LivreH* curr = *lh;
    
    while ((curr = *lh) != NULL) {
        
        lh = &curr->suivant;
        free(curr->auteur);
        free(curr->titre);
        free(curr);
    }
}

BiblioH* creer_biblioH(int m){

    BiblioH *b = malloc(sizeof(BiblioH));

    if (b==NULL) return NULL;

    b -> nE = 0;

    b -> m = m;

    b -> T = (LivreH**)malloc(sizeof(LivreH*) * b->m);

    if (b->T==NULL){

        free(b);

        return NULL;
    }

    return b;
}

void liberer_biblioH(BiblioH* b){

    LivreH** tab = b -> T;

    for(int i = 0; i < (b->m); i++) liberer_livreH(&tab[i]);

    free(b->T);

    free(b);
}

void inserer(BiblioH* b,int num,char* titre,char* auteur){

	LivreH* lh;

	if ((lh=creer_livreH(num,titre,auteur)) == NULL) return;

    int clefH = fonctionHachage(lh->clef,b->m);

    lh -> suivant = b -> T[clefH];

    b -> T[clefH] = lh;
	
}

int main(){
    printf("%d\n",fonctionClef("abcd"));
    printf("%f\n",A);
    return 0;
}