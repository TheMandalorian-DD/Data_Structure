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

        printf("usage: %s file number_of_line\n",argv[0]);
        
        return EXIT_FAILURE;
    }

    Biblio *b = charger_n_entrees(argv[1],atoi(argv[2]));

    Biblio *bi;

    Livre *livre;

	int num;

    char titre[256];

    char auteur[256];

    char ligne[256];

	int rep;

    do{

		bi = NULL, livre = NULL;

    	printf("\nQue voulez-vous faire ? ...\n");

    	menu();

    	fgets(ligne,256,stdin);

		sscanf(ligne,"%d",&rep);

    	switch(rep){

    		case 1:

    			printf("\nAffichage\n");

    			afficher_biblio(b);

    			break;

    		case 2:

    			printf("\nVeuillez entrer le numero, le titre et l'auteur de l'ouvrage.\n");

    			/* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
				
				fgets(ligne,256,stdin);

    			if (sscanf(ligne,"%d %s %s",&num,titre,auteur)==3) {

    				inserer_en_tete(b,num,titre,auteur);

    				printf("\nAjout fait.\n");

    			} else {

    				printf("\nErreur format\n");

    			}

    			break;

    		case 3:

    			printf("\nVeuillez entrer le numero de l'ouvrage.\n");
				
				fgets(ligne,256,stdin);

    			if (sscanf(ligne,"%d",&num)==1){

    				if ((livre = recherche_ouvrage_num(b,num))==NULL) printf("\nOuvrage non trouvé\n");
                    else afficher_livre(livre);

    			} else {

                    printf("\nErreur format\n");
                }

    			break;

    		case 4:

    			printf("\nVeuillez enntrer le titre de l'ouvrage.\n");
				
				fgets(ligne,256,stdin);

    			if (sscanf(ligne,"%s",titre)==1){

    				if ((livre = recherche_ouvrage_titre(b,titre))==NULL) printf("\nOuvrage non trouvé\n");
                    else afficher_livre(livre);

                } else {

                    printf("\nErreur format\n");
                }

    			break;

    		case 5:

    			printf("\nVeuillez entrer le nom de l'auteur.\n");
				
				fgets(ligne,256,stdin);

    			if (sscanf(ligne,"%s",auteur)==1){

    				if ((bi = recherche_meme_auteur(b,auteur))->L == NULL) printf("\nAucun ouvrage trouvé de cet auteur\n");
                    else afficher_biblio(bi);

    			} else {

                    printf("\nErreur format\n");

                }

    			liberer_biblio(bi);

    			break;

    		case 6:

    			printf("\nVeuillez entrer le numero, le titre et l'auteur de l'ouvrage.\n");

    			/* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
				
				fgets(ligne,256,stdin);

    			if (sscanf(ligne,"%d %s %s",&num,titre,auteur)==3) {

    				b = supprimer_livre(b,num,titre,auteur);

    				printf("\nsuppression fait.\n");

    			} else {

    				printf("\nErreur format\n");

    			}

    			break;

    		case 7:

    			if ((bi = recherche_exemplaires(b))->L==NULL) printf("\nAucun exemplaires trouvés\n");
    			else afficher_biblio(bi);

    			liberer_biblio(bi);

    			break;


    	}

    } while (rep != 0);

    liberer_biblio(b);

    printf("\nAu revoir !\n");

    return 0;
}


