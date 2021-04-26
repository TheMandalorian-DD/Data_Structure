#include <stdio.h>
#include <string.h>
#include "Chaine.h"
#include "Reseau.h"

int main(void) {

  FILE *f;
  f = fopen("00014_burma.cha", "r"); 
  Chaines *C = lectureChaines(f);
  fclose(f);

  Reseau *R = reconstitueReseauListe(C);
  liberer_chaine(C);
  afficheReseauSVG(R, "graph_reseau");  
  f = fopen("reseau.res", "w");
  ecrireReseau(R,f);
  liberer_reseau(R);
  fclose(f);
  return 0;
}

