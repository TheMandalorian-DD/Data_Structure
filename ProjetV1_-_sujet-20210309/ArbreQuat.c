#include "ArbreQuat.h"

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void chaineCoordMinMax(Chaines* C, double *xmin, double *ymin, double *xmax, double *ymax){
  double val_xmin=0, val_ymin=0, val_xmax=0, val_ymax=0;
  CellPoint *p = C->chaines->points;
  if (p){
    val_xmin = p->x;
    val_xmax = p->x;
    val_ymin = p->y;
    val_ymax = p->y;
  }
  for(CellChaine* chaine = C -> chaines; chaine; chaine = chaine -> suiv){
    if (chaine){
      for(CellPoint* point = chaine -> points; point; point = point -> suiv){
        if (point){
          *xmin = min(val_xmin,point->x);
          *ymin = min(val_ymin, point->y);
          *xmax = max(val_xmax,point->x);
          *ymax = max(val_ymax,point->y);
          val_xmin = *xmin;
          val_ymin = *ymin;
          val_xmax = *xmax;
          val_ymax = *ymax;
        }
      }
    }
  }
  printf("xmin = %f, ymin = %f, xmax = %f, ymax = %f\n",*xmin,*ymin,*xmax,*ymax);
}

ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY){
    ArbreQuat* a = malloc(sizeof(ArbreQuat));
    a -> xc = xc;
    a -> yc = yc;
    a -> coteX = coteX;
    a -> coteY = coteY;
    a -> noeud = NULL;
    a -> so = NULL;
    a -> se = NULL;
    a -> no = NULL;
    a -> ne = NULL;
    return a;
}


void insererNoeudArbre(Noeud* n, ArbreQuat** a, ArbreQuat* parent){
    /* Arbre vide */
    if (*a == NULL) {
        double coteX = parent->coteX / 2;
        double coteY = parent->coteY / 2;
        double xc, yc;
        if (n->x < parent->xc) {
            if (n->y < parent->yc) {
                xc = parent->xc - (coteX / 2);
                yc = parent->yc - (coteY / 2);
            } else {
                xc = parent->xc - (coteX / 2);
                yc = parent->yc + (coteY / 2);
            }
        } else if (n->y < parent->yc) {
            xc = parent->xc + (coteX / 2);
            yc = parent->yc - (coteY / 2);
        } else {
            xc = parent->xc + (coteX / 2);
            yc = parent->yc + (coteY / 2);
        }
        *a = creerArbreQuat(xc, yc, coteX, coteY);
        (*a)->noeud = n;
        return;
    }
    /* Feuille */
    if ((*a)->noeud != NULL) {
        if ((*a)->noeud->x < (*a)->xc) {
            if ((*a)->noeud->y < (*a)->yc) {
                insererNoeudArbre((*a)->noeud, &(*a)->so, *a);
            } else {
                insererNoeudArbre((*a)->noeud, &(*a)->no, *a);
            }
        } else if ((*a)->noeud->y < (*a)->yc) {
            insererNoeudArbre((*a)->noeud, &(*a)->se, *a);
        } else {
            insererNoeudArbre((*a)->noeud, &(*a)->ne, *a);
        }
        (*a)->noeud = NULL;
        if (n->x < (*a)->xc) {
            if (n->y < (*a)->yc) {
                insererNoeudArbre(n, &(*a)->so, *a);
            } else {
                insererNoeudArbre(n, &(*a)->no, *a);
            }
        } else if (n->y < (*a)->yc) {
            insererNoeudArbre(n, &(*a)->se, *a);
        } else {
            insererNoeudArbre(n, &(*a)->ne, *a);
        }
        return;
    }
    /* Cellule interne */
    if (n->x < (*a)->xc) {
        if (n->y < (*a)->yc) {
            insererNoeudArbre(n, &(*a)->so, *a);
        } else {
            insererNoeudArbre(n, &(*a)->no, *a);
        }
    } else if (n->y < (*a)->yc) {
      insererNoeudArbre(n, &(*a)->se, *a);
    } else {
      insererNoeudArbre(n, &(*a)->ne, *a);
    }
}

Noeud* rechercheCreeNoeudArbre(Reseau* R, ArbreQuat** a, ArbreQuat* parent, double x, double y) {
  if (*a == NULL) {
    Noeud* new_node = malloc(sizeof(Noeud));
    new_node->num = R->nbNoeuds + 1;
    new_node->x = x;
    new_node->y = y;
    new_node->voisins = NULL;
    insererNoeudArbre(new_node, a, parent);
    CellNoeud* new_cell = malloc(sizeof(CellNoeud));
    new_cell->nd = new_node;
    new_cell->suiv = R->noeuds;
    R->noeuds = new_cell;
    R->nbNoeuds++;
    return new_node;
  }
  if ((*a)->noeud != NULL) {
    if ((*a)->noeud->x == x && (*a)->noeud->y == y) return (*a)->noeud;
    Noeud* new_node = malloc(sizeof(Noeud));
    new_node->num = R->nbNoeuds + 1;
    new_node->x = x;
    new_node->y = y;
    new_node->voisins = NULL;
    insererNoeudArbre(new_node, a, parent);
    CellNoeud* new_cell = malloc(sizeof(CellNoeud));
    new_cell->nd = new_node;
    new_cell->suiv = R->noeuds;
    R->noeuds = new_cell;
    R->nbNoeuds++;
    return new_node;
  }

  if (x < (*a)->xc) {
    if (y < (*a)->yc) {
      return rechercheCreeNoeudArbre(R, &(*a)->so, *a, x, y);
    } else {
      return rechercheCreeNoeudArbre(R, &(*a)->no, *a, x, y);
    }
  } else if (y < (*a)->yc) {
    return rechercheCreeNoeudArbre(R, &(*a)->se, *a, x, y);
  } else {
    return rechercheCreeNoeudArbre(R, &(*a)->ne, *a, x, y);
  }
}

Reseau* reconstitueReseauArbre(Chaines* C) {
  Reseau* R = malloc(sizeof(Reseau));
  R->nbNoeuds = 0;
  R->gamma = C->gamma;
  R->noeuds = NULL;
  R->commodites = NULL;
  double xmin, ymin, xmax, ymax;
  chaineCoordMinMax(C, &xmin, &ymin, &xmax, &ymax);
  double coteX = xmax - xmin;
  double coteY = ymax - ymin;
  double xc = (xmax + xmin) / 2;
  double yc = (ymax + ymin) / 2;
  ArbreQuat* root = creerArbreQuat(xc, yc, coteX, coteY);
  Noeud *node, *node_pre, *node_first;
  CellChaine* list_chaine = C->chaines;
  while (list_chaine != NULL) {
    CellPoint* list_point = list_chaine->points;
    node_pre = NULL;
    if (list_point->x < root->xc) {
      if (list_point->y < root->yc) {
        node_first = rechercheCreeNoeudArbre(R, &root->so, root, list_point->x, list_point->y);
      } else {
        node_first = rechercheCreeNoeudArbre(R, &root->no, root, list_point->x, list_point->y);
      }
    } else if (list_point->y < root->yc) {
      node_first = rechercheCreeNoeudArbre(R, &root->se, root, list_point->x, list_point->y);
    } else {
      node_first = rechercheCreeNoeudArbre(R, &root->ne, root, list_point->x, list_point->y);
    }
    while (list_point != NULL) {
      if (list_point->x < root->xc) {
        if (list_point->y < root->yc) {
          node = rechercheCreeNoeudArbre(R, &root->so, root, list_point->x, list_point->y);
        } else {
          node = rechercheCreeNoeudArbre(R, &root->no, root, list_point->x, list_point->y);
        }
      } else if (list_point->y < root->yc) {
        node = rechercheCreeNoeudArbre(R, &root->se, root, list_point->x, list_point->y);
      } else {
        node = rechercheCreeNoeudArbre(R, &root->ne, root, list_point->x, list_point->y);
      }
      if (node_pre != NULL) {
        ajoute_voisins(node_pre, node);
      }
      node_pre = node;
      list_point = list_point->suiv;
    }
    ajoute_commodites(R, node_first, node);
    list_chaine = list_chaine->suiv;
  }
  liberer_arbre(root);
  return R;
}

void liberer_arbre(ArbreQuat* A){
  if (A){
    liberer_arbre(A->so);
    liberer_arbre(A->se);
    liberer_arbre(A->no);
    liberer_arbre(A->ne);
    free(A);
  }
}

