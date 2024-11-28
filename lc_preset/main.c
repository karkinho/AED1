#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void insertList( struct ListNode* l , int times );
void printList( struct ListNode* l );

struct ListNode {
     int val;
    struct ListNode *next;
};

int main(int argc, char const *argv[])
{
    return 0;
}

void insertList( struct ListNode* l , int times ){
    for (int i = 0; i < times; i++)
    {
        l->val = 9;
        l->next = ( struct ListNode* )malloc( sizeof( struct ListNode* ));
        l = l->next;
    }
    l->val = 9;
    l->next = NULL;
    return;
}

void printList( struct ListNode* l ){
    for ( int i = 0  ; l->next != NULL ; l = l->next)
    {
        printf( "%d", l->val );
    }
    printf( "%d\n", l->val );
}
