#include "biblioH.h"
#include "entreeSortieH.h"

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

    printf("num : %d, titre : %s, auteur : %s\n",lh -> num, lh -> titre, lh -> auteur);
}

void afficher_biblioH(BiblioH* bh){

    if (bh==NULL) return;

    if (bh->nE == 0) return;

    LivreH* lh;

    int i = 0;

    while(lh = bh -> T[i++], i <= bh->m){
        
        for(; lh; lh = lh -> suivant) afficher_livreH(lh);

    }
    
    /*for (int i = 0; i < bh->m; i++) afficher_livreH(bh->T[i]);*/

}

LivreH *recherche_ouvrage_num(BiblioH *bh, int num){

    if (bh==NULL) return NULL;

    if (bh->nE == 0) return NULL;

    LivreH* lh;

    int i = 0;

    while(lh = bh -> T[i++], i <= bh->m){

        for(; lh; lh = lh -> suivant){

            if (lh->num == num){

                return lh;

            }
        }
    }
    return NULL;
}

LivreH *recherche_ouvrage_titre(BiblioH *bh, char *titre){

    if (bh==NULL) return NULL;

    if (bh->nE == 0) return NULL;

    LivreH* lh;

    int i = 0;

    while(lh = bh -> T[i++], i <= bh->m){

        for(; lh; lh = lh -> suivant){

            if (strcmp(lh->titre,titre)==0){

                return lh;

            }
        }
    }
    return NULL;
}

BiblioH *recherche_meme_auteur(BiblioH *bh, char *auteur){

    if (bh==NULL) return NULL;

    if (bh->nE == 0) return NULL;

    BiblioH* b;

    if ((b=creer_biblioH(bh->m))==NULL) return NULL;

    int clefH = fonctionHachage(fonctionClef(auteur),bh->m);

    LivreH* lh;

    if((lh=bh->T[clefH])==NULL){

        printf("Cet auteur n'est pas répertorié dans la bibliothèque !\n");

        return NULL;
    }

    for(; lh; lh = lh -> suivant){

        if (strcmp(lh->auteur,auteur)==0){

            inserer(b,lh->num,lh->titre,lh->auteur);
        }
        
    }

    return b;

}

int supprimer_livreH(BiblioH* bh, int num, char* titre, char* auteur) {

  LivreH* curr;

  int clefH = fonctionHachage(fonctionClef(auteur),bh->m);

  LivreH** suivp = &(bh->T[clefH]);

  for(; (curr = *suivp) != NULL && (curr->num != num || strcmp(titre, curr->titre) != 0 || strcmp(auteur, curr->auteur) != 0); 

  suivp = &curr->suivant);

  if (curr == NULL) return 0;

  *suivp = curr->suivant;

  curr->suivant = NULL;

  liberer_livreH(&curr);

  bh->nE--;

  return 1;

}

void fusion(BiblioH* b1, BiblioH* b2){

    for(int i = 0; i < b2 -> m; i++){

        LivreH** lp = &(b2->T[i]);
        
        LivreH* curr;
        
        for(; (curr = *lp); lp = &curr->suivant);
        
        *lp = b1->T[i];
        
        b1->T[i] = b2->T[i];
        
        b2->T[i] = NULL;

    }

    b1 -> nE += b2 -> nE;

    liberer_biblioH(b2);
}

BiblioH *recherche_exemplaires(BiblioH *bh){

    if (bh==NULL) return NULL;

    if (bh->nE == 0) return NULL;

    BiblioH* b = creer_biblioH(bh -> m);

    for(int i = 0; i < bh -> m; i++){

        for(LivreH* lh1 = bh -> T[i]; lh1; lh1 = lh1 -> suivant){

            for(LivreH* lh2 = bh -> T[i]; lh2; lh2 = lh2 -> suivant){

                if (lh1 != lh2 && strcmp(lh1->titre,lh2->titre)==0 && strcmp(lh1->auteur,lh2->auteur)==0){
                    
                    inserer(b,lh2->num,lh2->titre,lh2->auteur);
            
                }

            }

        }
    }

    return b;

}


