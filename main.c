#include <stdio.h>
#include "algorithm.h"
int main(int argc, char * argv[]){
    printf(" Il comando è : LCS file1 file2 fileUscita.\n ");
  /*  if( argc != 4){
        printf("There must be at least 4 args, but only %d were given.\n", argc);
        return 0;
    } */
    printSoluzione("fileUscita", "file1", "file2");
    return 0;
}