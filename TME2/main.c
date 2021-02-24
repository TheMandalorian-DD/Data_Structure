#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "entreeSortieLC.h"
#include "biblioLC.h"

void menu(){

  puts("1.affichage biblio");

  puts("2.ajouter un ouvrage");

  puts("3.recherche d’un ouvrage par son numero");

  puts("4.recherche d’un ouvrage par son titre");

  puts("5.recherche de tous les livres d’un meme auteur");

  puts("6.suppression d’un ouvrage");

  puts("7.recherche de tous les ouvrages avec plusieurs exemplaires");

  puts("press 0 to exit...");
}

int main(int argc, char** argv){

    if (argc < 3){

        printf("usage: %s file line_number\n",argv[0]);
        
        exit(-1);
    }

    Biblio *b = charger_n_entrees(argv[1],atoi(argv[2]));

    Biblio *bi = NULL;

    Livre *livre;

    int rep;

    do{

    	livre = NULL;

    	printf("Que voulez-vous faire ? ...\n");

    	sleep(1);

    	menu();

    	scanf("%d",&rep);

    	switch(rep){

    		case 1:

    			printf("Affichage\n");

    			afficher_biblio(b);

    			break;

    		case 2:

    			printf("Veuillez entrer le numero, le titre et l'auteur de l'ouvrage.\n");

    			/* On suppose que le titre et l’auteur ne contiennent pas d’espace*/

    			int num;

    			char titre[256];

    			char auteur[256];

    			if (scanf("%d %s %s",&num,titre,auteur)==3) {

    				inserer_en_tete(b,num,titre,auteur);

    				printf("Ajout fait.\n");

    			} else {

    				printf("Erreur format\n");

    			}

    			break;

    		case 3:

    			printf("Veuillez enntrer le numero de l'ouvrage.\n");

    			if (scanf("%d",&num)==1){

    				livre = recherche_ouvrage_num(b,num);

    			}

    			if (livre==NULL) printf("Ouvrage non trouvé\n");
    			else printf("Ouvrage trouvé\n");

    			afficher_livre(livre);

    			break;

    		case 4:

    			printf("Veuillez enntrer le titre de l'ouvrage.\n");

    			if (scanf("%s",titre)==1){

    				livre = recherche_ouvrage_titre(b,titre);

    			}

    			if (livre==NULL) printf("Ouvrage non trouvé\n");
    			else printf("Ouvrage trouvé\n");

    			afficher_livre(livre);

    			break;

    		case 5:

    			printf("Veuillez entrer le nom de l'auteur.\n");

    			if (scanf("%s",auteur)==1){

    				bi = recherche_meme_auteur(b,auteur);

    			}

    			if (bi->L==NULL) printf("Aucun ouvrage trouvé de cet auteur\n");
    			else printf("Ouvrages trouvés\n");

    			afficher_biblio(bi);

    			liberer_biblio(bi);

    			break;

    		case 6:

    			printf("Veuillez entrer le numero, le titre et l'auteur de l'ouvrage.\n");

    			/* On suppose que le titre et l’auteur ne contiennent pas d’espace*/

    			if (scanf("%d %s %s",&num,titre,auteur)==3) {

    				b = supprimer_livre(b,num,titre,auteur);

    				printf("suppression fait.\n");

    			} else {

    				printf("Erreur format\n");

    			}
    			break;

    		case 7:

    			bi = recherche_exemplaires(b);

    			if (bi->L==NULL) printf("Aucun exemplaires trouvés\n");
    			else printf("Exemplaires trouvés\n");

    			afficher_biblio(bi);

    			liberer_biblio(bi);

    			break;


    	}
    } while (rep != 0);

    liberer_biblio(b);

    printf("Au revoir !\n");

    return 0;
}


