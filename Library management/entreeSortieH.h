#ifndef _ENTREESORTIEH_H_
#define _ENTREESORTIEH_H_

#include "biblioH.h"

#define TAILLE_HACHAGE 10

BiblioH* charger_n_entrees(char* nomfic, int n);

void enregistrer_biblioH(BiblioH *bH, char* nomfic);

#endif

