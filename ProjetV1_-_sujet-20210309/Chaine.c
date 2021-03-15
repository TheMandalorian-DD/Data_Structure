#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Chaine.h"

Chaines* lectureChaines(FILE *f){ 
    
    Chaines* chaine = malloc(sizeof(Chaines));

    char ligne[256], s[256];

    int nbChaines = 0, gamma = 0;

    /* première ligne */

    if (fgets(ligne,256,f) != NULL) sscanf(ligne,"%s %d", s, &nbChaines);
    
    chaine -> nbChaines = nbChaines;

    /* deuxième ligne */

    if (fgets(ligne,256,f) != NULL) sscanf(ligne,"%s %d", s, &gamma);
    
    chaine -> gamma = gamma;
    
    int num, nP;

    float x, y;

    CellChaine* L_cell = NULL; /* initialisation de la liste des cellules */

    for(int i = 0; i < chaine -> nbChaines; i++){

        CellChaine* cell = malloc(sizeof(CellChaine));

        fscanf(f,"%d %d", &num, &nP);

        cell -> numero = num;

        CellPoint* L_point = NULL; /* initialisation de la liste de points */

        for(int j = 0; j < nP; j++){

            CellPoint* point = malloc(sizeof(CellPoint));

            fscanf(f,"%f %f",&x,&y);

            point -> x = x;

            point -> y = y;

            point -> suiv = L_point; /* on insère le point dans la liste L_point */

            L_point = point; /* on met à jour notre liste L_point */

        }

        cell -> points = L_point;

        cell -> suiv = L_cell; /* on insère la cellule dans la liste L_cell */

        L_cell = cell; /* on met à jour notre liste L_cell */

    }

    chaine -> chaines = L_cell;

    return chaine;

}


void ecrireChaines(Chaines *C, FILE *f){

    fprintf(f,"NbChain: %d\nGamma: %d\n", C -> nbChaines, C -> gamma);
    
    for(CellChaine* L_cell = C -> chaines; L_cell; L_cell = L_cell -> suiv){

        int taille_L_point = 0;

        for(CellPoint* L_point = L_cell -> points; L_point; L_point = L_point -> suiv) taille_L_point++;
        
        fprintf(f,"%d %d ", L_cell -> numero, taille_L_point);

        for(CellPoint* L_point = L_cell -> points; L_point; L_point = L_point -> suiv) fprintf(f,"%.2f %.2f ", L_point -> x, L_point -> y);
        
        fprintf(f,"\n");
    }
}