#include <stdio.h>
#include <stdlib.h>
#define size 10


int main(){
    int ** matriz = NULL , ** aux = NULL;

    matriz = ( int ** )malloc( sizeof( int * ) * size );
    aux = matriz;
    for ( int i = 0 ; i < size ; i++ ) {
        *aux = ( int * )malloc( sizeof( int ) * size ); 
        aux++;
    }
    
    for ( int x = 0 ; x < size ; x++ ) {
        for ( int y = 0 ; y < size ; y++ ) {
            matriz[x][y] = size;
        }
    }
  
    for ( int x = 0 ; x < size ; x++ ) {
        for ( int y = 0 ; y < size ; y++ ) {
            printf( " %d ", matriz[x][y]);
        }
        printf("\n");
    }


    free(matriz);
    matriz = NULL;
    aux = NULL;
    return 0;
}