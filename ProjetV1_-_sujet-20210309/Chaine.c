#include "Chaine.h"

#include <math.h>
#include <stdlib.h> 

#include "SVGwriter.h"


Chaines* lectureChaines(FILE *f){ 
    Chaines* C = malloc(sizeof(Chaines));
    char ligne[256], s[256];
    int nbChaines = 0, gamma = 0;

    /* première ligne */
    if (fgets(ligne,256,f) != NULL) sscanf(ligne,"%s %d", s, &nbChaines);
    C -> nbChaines = nbChaines;

    /* deuxième ligne */
    if (fgets(ligne,256,f) != NULL) sscanf(ligne,"%s %d", s, &gamma);
    C -> gamma = gamma;
    
    int num, nP;
    double x, y;
    CellChaine* L_chaine = NULL; /* initialisation de la liste de chaînes */ 

    for(int i = 0; i < C -> nbChaines; i++){
        CellChaine* chaine = malloc(sizeof(CellChaine));
        fscanf(f,"%d %d", &num, &nP);
        chaine -> numero = num;
        CellPoint* L_point = NULL; /* initialisation de la liste de points */
        for(int j = 0; j < nP; j++){
            CellPoint* point = malloc(sizeof(CellPoint));
            fscanf(f,"%lf %lf",&x,&y);
            point -> x = x;
            point -> y = y;
            point -> suiv = L_point; /* Tout les points sont maintenant dans point */
            L_point = point; /* on met à jour notre liste L_point */
        }
        chaine -> points = L_point;
        chaine -> suiv = L_chaine; /* Toute les chaînes sont maintenant dans chaine */
        L_chaine = chaine; /* on met à jour notre liste L_chaine */
    }
    C -> chaines = L_chaine;
    return C;
}

int nbPoints(CellPoint* point){
    int nbpoints = 0;
    for(;point;point=point->suiv) nbpoints++;
    return nbpoints;
}


void ecrireChaines(Chaines *C, FILE *f){
    fprintf(f,"NbChaine: %d\nGamma: %d\n", C -> nbChaines, C -> gamma);
    for(CellChaine* chaine = C -> chaines; chaine; chaine = chaine -> suiv){
        fprintf(f,"%d %d ", chaine -> numero, nbPoints(chaine->points));
        for(CellPoint* point = chaine -> points; point; point = point -> suiv) fprintf(f,"%.2f %.2f ", point -> x, point -> y);
        fprintf(f,"\n");
    }
}

void afficheChainesSVG(Chaines *C, char* nomInstance){
    double maxx=0,maxy=0,minx=1e6,miny=1e6;
    CellChaine *ccour;
    CellPoint *pcour;
    double precx,precy;
    SVGwriter *svg=(SVGwriter *)malloc(sizeof(SVGwriter));
    ccour=C->chaines;
    while (ccour!=NULL){
        pcour=ccour->points;
        while (pcour!=NULL){
            if (maxx<pcour->x) maxx=pcour->x;
            if (maxy<pcour->y) maxy=pcour->y;
            if (minx>pcour->x) minx=pcour->x;
            if (miny>pcour->y) miny=pcour->y;  
            pcour=pcour->suiv;
        }
    ccour=ccour->suiv;
    }
    SVGinit(svg,nomInstance,500,500);
    ccour=C->chaines;
    while (ccour!=NULL){
        pcour=ccour->points;
        SVGlineRandColor(svg);
        SVGpoint(svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny)); 
        precx=pcour->x;
        precy=pcour->y;  
        pcour=pcour->suiv;
        while (pcour!=NULL){
            SVGline(svg,500*(precx-minx)/(maxx-minx),500*(precy-miny)/(maxy-miny),500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            SVGpoint(svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            precx=pcour->x;
            precy=pcour->y;    
            pcour=pcour->suiv;
        }
        ccour=ccour->suiv;
    }
    SVGfinalize(svg);
}

double longueurChaine(CellChaine* c){
    double somme = 0;
    for(CellPoint* L1_point = c -> points; L1_point -> suiv /* on vérifie que le prochain point n'est pas NULL */; L1_point = L1_point -> suiv){
        CellPoint* p1 = L1_point;
        CellPoint* p2 = p1 -> suiv;
        somme += sqrt (pow(p2 -> x - p1 -> x, 2) + pow(p2 -> y - p1 -> y, 2));
    }
    return somme;
}

double longueurTotale(Chaines *C){
    double somme = 0;
    for(CellChaine* L_cell = C -> chaines; L_cell; L_cell = L_cell -> suiv) somme += longueurChaine(L_cell);
    return somme;
}

int comptePointsTotal(Chaines *C){
    int n = 0;
    for(CellChaine* chaine = C -> chaines; chaine; chaine = chaine -> suiv){
        for(CellPoint* point = chaine -> points; point; point = point -> suiv) n++;
    }
    return n;
}

void liberer_point(CellPoint* points){
    while(points) {
		CellPoint *tmp=points->suiv;
		free(points);
		points=tmp;
	} 
}

void liberer_chaine(Chaines* C){
    CellChaine *chaine = C->chaines;
    while(chaine){
        CellChaine *tmp=chaine->suiv;
        liberer_point(chaine->points);
        free(chaine);
        chaine=tmp;
    }
    free(C);
}

