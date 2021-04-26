#include "Chaine.h"


int main(void){

    FILE *f;
    f = fopen("00014_burma.cha","r");
    Chaines *C = lectureChaines(f);
    fclose(f);

    f = fopen("chaine.res","w");
    ecrireChaines(C,f);
    fclose(f);

    afficheChainesSVG(C,"graph_chaine");
    printf("longueur totale = %.2f\n", longueurTotale(C));
    printf("nombre d'occurrence = %d\n", comptePointsTotal(C));
    liberer_chaine(C);

    return 0;
}

