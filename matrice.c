//
// Created by alessandro on 07/12/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrice.h"
int** creaMatrice(char *prima, char*seconda) {
    int** matrice = riempiMatrice(prima, seconda);
    return matrice;
}

int** riempiMatrice(char*prima , char*seconda) {
    int righe = strlen(prima) + 1;
    int colonne = strlen(seconda) + 1;
    int** matrice = (int**) malloc(sizeof(int*)*righe);
    for (int i = 0; i < righe; ++i) {
        matrice[i] = (int*) calloc(colonne,sizeof (int));
    }

    return matrice;
}