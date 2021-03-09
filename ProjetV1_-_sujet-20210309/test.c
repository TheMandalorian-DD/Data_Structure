#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *f = fopen("test.txt","r");

    int num, nP;
    float x, y;

    char LIGNE[256];

    int i = 0;

    while(i<3){

        //sscanf(LIGNE,"%d %d", &num, &nP);
        
        fscanf(f,"%d %d", &num, &nP);
        
        printf("numero : %d, nP : %d\n",num,nP);

        for(int i = 0; i < nP; i++){

            fscanf(f,"%f %f",&x,&y);

            printf("x : %f, y : %f\n",x,y);


        }

        i++;

    }

    
    

    fclose(f);

    return 0;
}