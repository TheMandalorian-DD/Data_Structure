#include "entreeSortieLC.h"
#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    if (argc < 3){

        printf("usage: ./%s file line_number\n",argv[0]);
        
        exit(-1);
    }

    Biblio* b = creer_biblio();

    b = charger_n_entrees(argv[1],atoi(argv[2]));

    return 0;

}