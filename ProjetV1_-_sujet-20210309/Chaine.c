#include <stdio.h>

#include <Chaine.h>

Chaines* lectureChaines(FILE *f){
    
    Chaines* chaine = malloc(sizeof(Chaines));

    char ligne[256], s[256];

    int gamma, nbChaines;

    /* première ligne */

    if (fgets(ligne,sizeof(ligne),f) != NULL) sscanf(ligne,"%s %d", s, &nbChaines);
    
    chaine -> nbChaines = nbChaines;

    /* deuxième ligne */

    if (fgets(ligne,sizeof(ligne),f) != NULL) sscanf(ligne,"%s %d", s, &gamma);
    
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

            point -> suiv = L_point; /*        */

            L_point = point; 

        }

        cell -> points = L_point;

        cell -> suiv = L_cell;

        L_cell = cell;

    }

    chaine -> chaines = L_cell;

    return chaine;

}