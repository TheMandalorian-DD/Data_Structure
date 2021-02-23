#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entreeSortieLC.h"
#include "biblioLC.h"

void menu(){

  puts("1.affichage biblio");

  puts("2.ajouter un ouvrage");

  puts("press 0 to exit...");
}

int main(int argc, char** argv){

    if (argc < 3){

        printf("usage: %s file line_number\n",argv[0]);
        
        exit(-1);
    }

    Biblio *b = charger_n_entrees(argv[1],atoi(argv[2]));

    int rep;

    do{

    	menu();

    	scanf("%d",&rep);

    	switch(rep){

    		case 1:

    			printf("Affichage\n");

    			afficher_biblio(b);

    			break;

    		case 2:

    			int num;

    			char titre[256];

    			char auteur[256];

    			printf("Veuillez ecrire le numero, le titre et l'auteur de l'ouvrage.\n");

    			/* On suppose que le titre et l’auteur ne contiennent pas d’espace*/

    			if (scanf("%d %s %s",&num,titre,auteur)==3) {

    				inserer_en_tete(b,num,titre,auteur);

    				printf("Ajout fait.");

    			} else {

    				printf("Erreur format");

    			}
    			break;
    	}
    } while (rep != 0);

    printf("Au revoir !\n");

    return 0;
}


