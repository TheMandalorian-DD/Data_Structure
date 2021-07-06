#ifndef __HACHAGE_H__
#define __HACHAGE_H__
#include "Reseau.h"
#include <math.h>

#define functionClef(X, Y) Y + ((X + Y) * (X + Y + 1)/2 )

#define GOLDEN ((sqrt(5) - 1) / 2.0)

#define functionHachage(x, M) floor( (M) * ( (x * GOLDEN) - floor(x * GOLDEN) ) ) 

typedef struct tableHachage TableHachage;
typedef struct nodeHachage NodeHachage;

struct nodeHachage {
  Noeud *node;
  NodeHachage *suiv;
};

struct tableHachage {
  int size;
  int nb_elements;
  NodeHachage **nodes;
};

int size_hash(Chaines* C, int m);
Reseau *reconstitueReseauHash(Chaines *C, int size);
Noeud *rechercheCreeNoeudHachage(Reseau *R, TableHachage *H, double x, double y);
void liberer_node(NodeHachage* n);
void liberer_hash(TableHachage* hash);

#endif

