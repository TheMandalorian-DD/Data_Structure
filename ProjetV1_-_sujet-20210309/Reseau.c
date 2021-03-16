#include "Reseau.h"

Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y){

    for(CellNoeud* L_noeud = R -> noeuds; L_noeud; L_noeud = L_noeud -> suiv){

        Noeud* noeud = L_noeud -> nd;

        if (noeud -> x == x && noeud -> y == y) return noeud;
    }

    CellNoeud* new_noeud = malloc(sizeof(CellNoeud));

    Noeud* n = malloc(sizeof(Noeud));
    
    n -> num = (R -> nbNoeuds) + 1;

    n -> x = x;

    n -> y = y;

    n -> voisins = NULL;

    new_noeud -> nd = n;

    new_noeud -> suiv = R -> noeuds;

    R -> noeuds = new_noeud;

    R -> nbNoeuds += 1;

    return n;
}