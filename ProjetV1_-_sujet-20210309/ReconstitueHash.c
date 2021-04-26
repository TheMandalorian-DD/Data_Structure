
#include <stdio.h>
#include <string.h>

#include "Hachage.h"

int main(void) {
  FILE *f;
  f = fopen("00014_burma.cha", "r");
  Chaines *C = lectureChaines(f);
  fclose(f);

  Reseau *R = reconstitueReseauHash(C, 57);
  liberer_chaine(C);
  afficheReseauSVG(R, "graph_hash");

  f = fopen("hash.res", "w");
  ecrireReseau(R, f);
  fclose(f);
  return 0;
}

