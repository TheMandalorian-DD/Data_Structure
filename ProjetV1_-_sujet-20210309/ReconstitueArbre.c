#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArbreQuat.h"

int main(void) {
  FILE *f;
  f = fopen("00014_burma.cha", "r");
  Chaines *C = lectureChaines(f);
  fclose(f);
  Reseau *R = reconstitueReseauArbre(C);
  liberer_chaine(C);
  afficheReseauSVG(R, "graph_arbre");
  system("open graph_arbre.html");
  f = fopen("arbre.res", "w");
  ecrireReseau(R, f);
  fclose(f);
  return 0;
}

