#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Chaine.h"

int main(void){

    FILE *f1 = fopen("00014_burma.cha","r");

    Chaines *C = lectureChaines(f1);

    fclose(f1);

    FILE *f2 = fopen("Chaine.txt","w");

    ecrireChaines(C,f2);

    fclose(f2);

    printf("longueur totale = %.2f\n", longueurTotale(C));

    return 0;
    
}