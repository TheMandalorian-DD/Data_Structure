#ifndef _BIBLIOH_H_
#define _BIBLIOH_H_

typedef struct livreh {
    int clef;
    int num;
    char* titre;
    char* auteur;
    struct livreh * suivant ;
} LivreH ;

typedef struct table {
    int nE; /*nombre d'elements contenus dans la table de hachage */
    int m; /*taille de la table de hachage */
    LivreH ** T; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;

int fonctionClef(char* auteur);

int fonctionHachage(int cle, int m);

LivreH* creer_livreH(int num,char* titre,char* auteur);

void liberer_livreH(LivreH** lh);

BiblioH* creer_biblioH(int m);

void liberer_biblioH(BiblioH* bh);

void inserer(BiblioH* b,int num,char* titre,char* auteur);

void afficher_livreH(LivreH* lh);

void afficher_biblioH(BiblioH* bh);

LivreH *recherche_ouvrage_num(BiblioH *bh, int num);

LivreH *recherche_ouvrage_titre(BiblioH *bh, char *titre);

BiblioH *recherche_meme_auteur(BiblioH *bh, char *auteur);

int supprimer_livreH(BiblioH* bh, int num, char* titre, char* auteur);

void fusion(BiblioH* b1, BiblioH* b2);

BiblioH *recherche_exemplaires(BiblioH *bh);

#endif

