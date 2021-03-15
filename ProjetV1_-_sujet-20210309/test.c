#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *f = fopen("test.txt","r");

    char ligne[256], s[256];

    int gamma, nbChaines;

    /* première ligne */

    if (fgets(ligne,256,f) != NULL){
        
        sscanf(ligne,"%s %d", s, &nbChaines);

        printf("nbChaines : %d\n",nbChaines);

    }

    /* deuxième ligne */

    if (fgets(ligne,256,f) != NULL){

        sscanf(ligne,"%s %d", s, &gamma);

        printf("gamma : %d\n",gamma);

    }

    int num, nP;

    float x, y;

    int i = 0;

    for(int j = 0; j < nbChaines; j++){
        
        fscanf(f,"%d %d", &num, &nP);
        
        printf("numero : %d, nP : %d\n",num,nP);

        for(int i = 0; i < nP; i++){

            fscanf(f,"%f %f",&x,&y);

            printf("x : %f, y : %f\n",x,y);


        }


    }
    
    fclose(f);

    return 0;
}