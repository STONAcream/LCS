#include <stdlib.h>
#include <string.h>
#include "algorithm.h"
#include "matrice.h"
#include "readfile.h"
#include <stdio.h>


char **algorithm (int** matrice , char * prima, char * seconda ) {
    int righe = strlen(prima) + 1;
    int colonne = strlen(seconda) + 1;
    char** soluzione = (char**) malloc(sizeof(char *)*righe);
    for (int i = 0; i < righe; ++i) {
        soluzione[i] = (char*) calloc(colonne,sizeof(char));

    }
    for (int i = 0; i < righe; ++i) {
        soluzione[i][0] = '0';
    }
    for (int i = 0; i < colonne; ++i) {
        soluzione[0][i] = '0';
    }
    for (int i = 1; i < righe ; i++) {
        for (int j = 1; j < colonne; j++) {
            if (seconda[i - 1] == prima[j - 1]) {
                matrice[i][j] = matrice[i - 1][j - 1] + 1;
                soluzione[i][j] = 'd';
            } else {
                matrice[i][j] = max(matrice[i-1][j], matrice[i][j-1]);
                if(matrice[i-1][j] >= matrice[i][j-1]){
            soluzione[i][j]= 't';
                }else{         soluzione[i][j]= 'l';
              }
            }
        }
    }
    return soluzione;
}

    int max(int x, int y) {
        if (x > y) {
            return x;
        } else return y;

    }

char* getSoluzione ( char * pathFile, char * pathFileS) {
    char *prima = readFile(pathFile);
    char *seconda = readFile(pathFileS);
    int** tabella = creaMatrice(prima,seconda);
    char** matrice = algorithm(tabella,prima,seconda);
    for (int i = 0; i <= strlen(prima); ++i) {
        for (int j = 0; j <= strlen(seconda); ++j) {
            printf("%c ",matrice[i][j]);
        }
        printf("\n");
    }

    char* soluzione = malloc(sizeof(char)*tabella[strlen(prima)][strlen(seconda)]);
    if (strlen(prima) == 0 || strlen(seconda) == 0) {
        return "";
    } else if (strcmp(prima, seconda) == 0) {
        return prima;
    } else {
        int m = strlen(prima);
        int n = strlen(seconda);
        int i = tabella[strlen(prima)][strlen(seconda)] -1;
        while (matrice[m][n] != '0') {
            if (matrice[m][n] == 'd') {
            soluzione[i] = prima[m-1];
                i--;
                m--;
                n--;
            } else if (matrice[m][n] == 'l') {
                n--;

            } else if (matrice[m][n] == 't') {
                m--;
            }


        }free( prima);
        free(seconda);
        prima = NULL;
        seconda = NULL;
        return soluzione;

    }
}
void printSoluzione(char* percUscita,char * pathFile, char * pathFileS){
    char * soluzione = getSoluzione(pathFile, pathFileS);
    FILE* f = fopen(percUscita, "w");
    fprintf (f,"%s",soluzione);
    free(soluzione);
    soluzione =NULL;
}


