
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hachage.h"

int main(void) {
  FILE *f;
  f = fopen("00014_burma.cha", "r");
  Chaines *C = lectureChaines(f);
  fclose(f);
  int m = C->nbChaines*C->gamma*0.5;
  Reseau *R = reconstitueReseauHash(C, m);
  liberer_chaine(C);
  afficheReseauSVG(R, "graph_hash");
  system("open graph_hash.html");
  f = fopen("hash.res", "w");
  ecrireReseau(R, f);
  liberer_reseau(R);
  fclose(f);
  return 0;
}

