
#include <stdio.h>
#include <string.h>

#include "Hachage.h"

int main(void) {
  FILE *f;
  f = fopen("00014_burma.cha", "r");
  Chaines *C = lectureChaines(f);
  fclose(f);
  for(int i = 0; i<61; i++){
    printf("taille initiale = %d, taille réelle = %d\n",i,size_hash(C,i));
    if (i-size_hash(C,i) > 1){
      printf("La taille %d convient pour la table de Hachage\n",i);
    }
  }
  Reseau *R = reconstitueReseauHash(C, 57);
  liberer_chaine(C);
  afficheReseauSVG(R, "graph_hash");

  f = fopen("hash.res", "w");
  ecrireReseau(R, f);
  liberer_reseau(R);
  fclose(f);
  return 0;
}

