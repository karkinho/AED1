#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct container container;

struct container {
    int value;
};  

struct Node {
    container *info;
    void * left , * right; 
};

void Push( Node ** stump , int value );
void List( Node ** stump );
void PreOrdem( Node * node , int height );
Node **SearchPush( Node * node , int value );
void Pop( Node ** stump, int value );
Node * SearchPop( Node * node , int value );
bool FindReaplacePop( Node * node , container * replacement );

int main( int argc , char const *argv[] ) {
    Node *stump = NULL;
    List( &stump );
    Push( &stump , 10 );
    Push( &stump , 20 );
    Push( &stump , 15 );
    Push( &stump , 5 );
    Push( &stump , 50 );
    Push( &stump , 56 );
    Push( &stump , 27 );
    Push( &stump , 8 );
    Push( &stump , 12 );
    Push( &stump , 90 );
    Push( &stump , 1 );
    List( &stump );

    return 0;
}

void Push( Node ** stump , int value ) {
    Node * newNode = ( Node * )malloc( sizeof( Node ) ) , ** temp = NULL ;
    container * newContainer = ( container * )malloc( sizeof( container ) );
    newContainer->value = value;
    newNode->info = newContainer;
    newNode->left = NULL;
    newNode->right = NULL;
    if ( *stump == NULL ) {
        *stump = newNode;
        return;
    }
    temp = ( Node ** ) SearchPush( *stump , value );
    *temp = newNode;
}

Node **SearchPush( Node * node , int value ) {
    if( value < node->info->value ) {
        if( node->left == NULL ) {
            return ( Node ** )( &node->left );
        } else{
            return SearchPush( node->left , value );
        }
    } 
    if( value > node->info->value ) {
        if( node->right == NULL ) {
            return ( Node ** )( &node->right );
        } else{
            return SearchPush( node->right , value );
        }
    }
    if( value == node->info->value ) {
        return NULL;
    }
    return NULL;
}

void List( Node ** stump ) {
    if ( *stump == NULL ) {
        printf( "b_tree vaiza\n" );
        return;
    }
    PreOrdem( *stump , 0 );
}

void PreOrdem( Node * node  , int height ){
    for ( int i = 0; i < height ; i++ ) {
        printf( " | " );
    }
    printf( "%d\n", node->info->value );
    if( node->left != NULL ) {
        PreOrdem( node->left , height + 1 );
    }
    if( node->right != NULL ) {
        PreOrdem( node->right , height + 1 );
    }
    return;
}

/*void Pop( Node ** stump, int value ){
    if ( *stump == NULL ) {
        printf( "b_tree vaiza\n" );
        return;
    }
    container * replacement = NULL;
    Node * temp = SearchPop( *stump , value );
    if( temp->right == NULL && temp ) {

    }
    Node ** aux = FindReaplacePop( temp , replacement );
    
}
Node * SearchPop( Node * node , int value ) {
    if( node->info->value == value ) {
        return node;
    }
    if( node->info->value < value ) {
        return SearchPop( node->right , value );
    }
    if( node->info->value > value ) {
        return SearchPop( node->left , value );
    }
    return NULL;
}
bool FindReaplacePop( Node * node , container * replacement ){
    
}*/