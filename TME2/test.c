#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    char titre[256];
    char auteur[256];
    char a[256];
    for (int i = 0; i < 3; i++){
        // getchar();
        fgets(a,256,stdin);
        sscanf(a,"%d %s %s",&n, titre, auteur);
        printf("%d %s %s",n, titre, auteur);
        //fflush(stdin);
    }
    return 0;
}