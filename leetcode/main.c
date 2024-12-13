#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

void function();
void test();

int main( int argc , char const *argv[] ) {
    test();
    return 0;
}

void test(){
    printf( "%d\n" , function() );
}
