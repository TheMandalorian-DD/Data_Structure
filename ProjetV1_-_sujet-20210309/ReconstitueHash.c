
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hachage.h"

int main(void) {
  FILE *f;
  f = fopen("00014_burma.cha", "r");
  Chaines *C = lectureChaines(f);
  fclose(f);
  int m = 57;
  // for(int i = 0; i<100; i++){
  //   printf("taille initiale = %d, taille réelle = %d\n",i,size_hash(C,i));
  //   if (i-size_hash(C,i) > 1){
  //     printf("La taille %d convient pour la table de Hachage\n",i);
  //     m=i;
  //     break;
  //   }
  // }
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

