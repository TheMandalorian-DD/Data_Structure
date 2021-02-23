#ifndef _BIBLIOLC_H_
#define _BIBLIOLC_H_


typedef struct livre {
	int num ;
	char * titre ;
	char * auteur ;
	struct livre * suiv ;
} Livre ;



typedef struct { /* Tete fictive */
	Livre * L; /* Premier element */
} Biblio ;



Livre* creer_livre(int num,char* titre,char* auteur);

void liberer_livre(Livre* l);

Biblio* creer_biblio();

void liberer_biblio(Biblio* b);

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);

void afficher_livre(Livre *livre);

void afficher_biblio(Biblio *b);

Livre *recherche_ouvrage_num(Biblio *b, int num);

Livre *recherche_ouvrage_titre(Biblio *b, char *titre);

Biblio *recherche_meme_auteur(Biblio *b, char *auteur);

Biblio *supprimer_livre(Biblio *b, int num, char *titre, char *auteur);

void fusion(Biblio *b1, Biblio *b2);

Biblio *recherche_exemplaires(Biblio *b);

#endif




