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

int fonctionHachage(int cle, int m){

    return (int)(m * ((double)cle * A - (int)(cle * A)));
}

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

    BiblioH *bh = malloc(sizeof(BiblioH));

    if (bh==NULL) return NULL;

    bh -> nE = 0;

    bh -> m = m;

    bh -> T = (LivreH**)malloc(sizeof(LivreH*) * bh->m);

    if (bh->T==NULL){

        free(bh);

        return NULL;
    }
    /* Initialisation des tableaux */
    memset(bh->T, 0, sizeof(LivreH*) * bh->m);

    return bh;
}

void liberer_biblioH(BiblioH* bh){

    LivreH** tab = bh -> T;

    for(int i = 0; i < (bh->m); i++) liberer_livreH(&tab[i]);

    free(bh->T);

    free(bh);
}

void inserer(BiblioH* bh,int num,char* titre,char* auteur){

	LivreH* lh;

	if ((lh=creer_livreH(num,titre,auteur)) == NULL) return;

    int clefH = fonctionHachage(lh->clef,bh->m);

    lh -> suivant = bh -> T[clefH];

    bh -> T[clefH] = lh;

    bh -> nE++;
	
}

void afficher_livreH(LivreH* lh){

    if (lh==NULL) return;

    for(LivreH* l = lh; l; l = l -> suivant){

        printf("num : %d, titre : %s, auteur : %s\n",l->num,l->titre,l->auteur);
    }
}

void afficher_biblioH(BiblioH* bh){

    if (bh==NULL) return;

    if (bh->nE == 0) return;
    
    LivreH* lh;
    
    for (int i = 0; i < bh->m; lh = bh->T[i++]) afficher_livreH(lh);
    
}

int main(void){
    LivreH* l = creer_livreH(1,"abc","def");
    l->suivant = creer_livreH(2,"fokods","idjfi");
    afficher_livreH(l);
}

