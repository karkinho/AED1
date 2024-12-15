#include "lib.h"

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main( int argc , char const *argv[] ) {
    int * returnSize = ( int *)malloc( sizeof( int ) );
    int ** returnColumnSizes = ( int **)malloc( sizeof( int *) );
    int test1[3] = {0,1,1};
    printMatrix( threeSum( test1 , 3 , returnSize , returnColumnSizes ) , returnSize , returnColumnSizes );
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int ** ans = (int **)malloc( sizeof( int *) ) , ** aux = NULL;
    *ans = (int *)malloc( sizeof( int ) );
    *returnColumnSizes = (int *)malloc( sizeof( int ) );
    **returnColumnSizes = 0;
    *returnSize = 0;
    
    for ( int first = 0; first < numsSize ; first++ ) {
        for ( int second = 1 + first; second < numsSize; second++ ) {
            for ( int third = 1 + second ; third < numsSize ; third++ ) {
                if ( nums[first] + nums[second] + nums[third] == 0 ) {
                    *returnSize += 1;
                    ans = ( int ** )realloc( ans , sizeof( int *) * *returnSize );
                    aux = ans;
                    for ( int  i = 1; i < *returnSize ; i++ , aux++ );
                    *aux = ( int * )malloc( sizeof( int ) * 3);
                    *aux[first] = nums[first];
                    *aux[second] = nums[second];
                    *aux[third] = nums[third];
                    aux = returnColumnSizes;
                    for ( int  i = 1; i < *returnSize ; i++ , aux++ );
                    *aux = ( int * )malloc( sizeof( int ) );
                    **aux = 3;
                    aux = NULL;
                }
            }
        } 
    }
    return ans;
}