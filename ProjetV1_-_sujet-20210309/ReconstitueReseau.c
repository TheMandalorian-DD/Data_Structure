    
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

  //afficheReseauSVG(R, "graph_reseau");  

  f = fopen("reseau.txt", "w");

  ecrireReseau(R,f);

  fclose(f);

  return 0;
}

