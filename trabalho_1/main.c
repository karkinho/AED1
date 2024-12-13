#include <stdio.h>
#include <stdlib.h>
#define size 5

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main(int argc, char const *argv[])
{
    int ** ans, ** returnColumnSizes , * returnSize;
    returnSize = ( int * )malloc( sizeof( int ) );
    ans = generate( size , returnSize, returnColumnSizes);
    for ( int x = 0 ; x < size ; x++ ) {
        for ( int y = 0 ; y <= x ; y++ ) {
            printf( " %d ", ans[x][y]);
        }
        printf("\n");
    }
    return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int ** matriz = NULL , ** aux = NULL;

    matriz = ( int ** )malloc( sizeof( int * ) * numRows );
    aux = matriz;

    *returnSize = numRows;

    *returnColumnSizes = ( int * )malloc( sizeof( int ) * numRows );

    for ( int rowSize = 0 ; rowSize < numRows ; rowSize++ ) {
        *aux = ( int * )malloc( sizeof( int ) * ( rowSize + 1 ) ); 
        returnColumnSizes[0][rowSize] = rowSize + 1;
        aux++;
    }
    
    for ( int row = 0 ; row < numRows ; row++ ) {
        for ( int collumn = 0 ; collumn <= row ; collumn++) {
            if ( collumn == 0 || collumn == row) {
                matriz[row][collumn] = 1;
            } else {
                matriz[row][collumn] = matriz[row - 1][collumn -1] + matriz[row-1][collumn];
            }
        }
    }
    return matriz;
}
