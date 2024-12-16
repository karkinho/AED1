#include "lib.h"

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main( int argc , char const *argv[] ) {
    int * returnSize = ( int *)malloc( sizeof( int ) );
    int ** returnColumnSizes = ( int **)malloc( sizeof( int *) );
    
    // int test1[6] = {-1,0,1,2,-1,-4}; // [[-1,-1,2],[-1,0,1]]
    // int ** ans = threeSum( test1 , 6 , returnSize , returnColumnSizes );

    int test2[11] = {-1,0,1,2,-1,-4,-2,-3,3,0,4}; // [[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
    int ** ans = threeSum( test2 , 11 , returnSize , returnColumnSizes );
    printMatrix( ans , returnSize , returnColumnSizes );
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int ** ans = (int **)malloc( sizeof( int *) ) , ** aux = NULL , flag = 0 ;
    *ans = (int *)malloc( sizeof( int ) );
    *returnSize = 0;

    qsort( nums , numsSize , sizeof(int) , comp );
    
    for ( int first = 0; first < numsSize ; first++ ) {
        for ( int second = 1 + first; second < numsSize; second++ ) {
            for ( int third = 1 + second ; third < numsSize ; third++ ) {
                if ( nums[first] + nums[second] + nums[third] == 0 ) {
                    for ( int row = 0; row < *returnSize ; row++ ) {
                        if ( nums[first] == ans[row][0] && nums[second] == ans[row][1] && nums[third] == ans[row][2] ) {
                            flag = 1;
                            break;
                        }
                    }  
                    if ( flag < 1 ){
                        *returnSize += 1;
                        ans = ( int ** )realloc( ans , sizeof( int *) * *returnSize );
                        aux = ans;
                        for ( int  i = 1; i < *returnSize ; i++ , aux++ );                   
                        *aux = ( int * )malloc( sizeof( int ) * 3);
                        aux = ans;
                        aux[*returnSize - 1][0] = nums[first];
                        aux[*returnSize - 1][1] = nums[second];
                        aux[*returnSize - 1][2] = nums[third];
                    }
                    flag = 0;
                }
            }
        } 
    }
    *returnColumnSizes = ( int * )malloc( sizeof( int ) * *returnSize); 
    for ( int i = 0; i < *returnSize; i++ ) {
        returnColumnSizes[0][i] = 3;
    }
    return ans;
}