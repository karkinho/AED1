#include <stdio.h>
#include <stdlib.h>
#define size 10


int main(){
    int ** matriz = NULL , ** aux = NULL;

    matriz = ( int ** )malloc( sizeof( int * ) * size );
    aux = matriz;
    for ( int rowSize = 0 ; rowSize < size ; rowSize++ ) {
        *aux = ( int * )malloc( sizeof( int ) * ( rowSize + 1 ) ); 
        aux++;
    }
    
    for ( int row = 0 ; row < size ; row++ ) {
        for ( int collumn = 0 ; collumn < row ; collumn++) {
            if ( collumn == 0 || collumn == row) {
                matriz[row][collumn] = 1;
            } else {
                matriz[row][collumn] = matriz[row - 1][collumn -1] + matriz[row-1][collumn];
            }
        }
    }
    
    for ( int x = 0 ; x < size ; x++ ) {
        for ( int y = 0 ; y < x ; y++ ) {
            printf( " %d ", matriz[x][y]);
        }
        printf("\n");
    }

    free(matriz);
    matriz = NULL;
    aux = NULL;
    return 0;
}