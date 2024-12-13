#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

// Evandro Chaves Barn

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main() {
    int* returnSize;
    int** returnColumnSizes;
    generate( 2 ,  returnSize, returnColumnSizes);
    return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int ** ans, ** aux , ** aux1, ** aux2;

    ans = (int **)malloc( sizeof( int *) * numRows );

    returnSize = (int *)malloc( sizeof(int));
    *returnSize = sizeof( int) * numRows;

    returnColumnSizes = (int **)malloc( sizeof( int *) * numRows);

    aux2 = returnColumnSizes;

    aux = ans;

    for (int i = 0; i < numRows; i++) {
        *aux = ( int * ) malloc(sizeof(int) * ( i + 1) );
        *aux2 = (int * ) malloc( sizeof(int));
        **aux2 = sizeof(int) * (i + 1);
        aux++;
        aux2++;
    }

    for (int i = 0; i < numRows; i++) {
        for (int x = 0; x <= i; x++) {
            ans[i][x] = 1;
        }
    }

    return ans;
}