#include "lib.h"

void printMatrix( int ** matrix , int* returnSize , int** returnColumnSizes ) {
    int ** aux = returnColumnSizes;
    for ( int row = 0 ; row < *returnSize ; row++ ) {
        printf("[");
        for ( int column = 0 ; column < aux[0][row] ; column++ ) {
            printf("%d " , matrix[row][column] );
        }
        printf("]\n");        
    }
}