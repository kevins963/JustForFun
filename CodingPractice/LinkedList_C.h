#ifndef LINKED_LIST_C_H__
#define LINKED_LIST_C_H__

#include <stdint.h>
#include <stdlib.h>
#include <iostream>

typedef struct linked_list
{
    int16_t data;
    struct linked_list * pNextNode;
} linked_list;

using namespace std;

class LinkedList_C
{
public:
    void TestAll();

//private:
    static linked_list* create_node( int16_t data );
    static void push_back( linked_list ** listNode, int16_t data );
    static void push_back_single_pointer( linked_list * listNode, int16_t data );
    static void print_list( linked_list * list );
};

void LinkedList_C::push_back( linked_list ** listNode, int16_t data )
{
    linked_list *node = *listNode;
    linked_list *insertNode = create_node( data );

    //Check if list is empty
    if( node == NULL )
    {
        *listNode = insertNode;
    }
    else
    {

        while( node->pNextNode != NULL )
        {
            node = node->pNextNode;
        }

        node->pNextNode = insertNode;
    }
}

void LinkedList_C::push_back_single_pointer( linked_list * listNode, int16_t data )
{
    linked_list *node = listNode;
    linked_list *insertNode = create_node( data );

    //Check if list is empty
    if( node == NULL )
    {
        listNode = insertNode;
    }
    else
    {

        while( node->pNextNode != NULL )
        {
            node = node->pNextNode;
        }

        node->pNextNode = insertNode;
    }
}

linked_list* LinkedList_C::create_node( int16_t data )
{
    linked_list* node = (linked_list *)malloc( sizeof( linked_list ) );
    node->data = data;
    node->pNextNode = NULL;

    return node;
}

void LinkedList_C::TestAll()
{
    linked_list* list = NULL;
    linked_list* list2 = NULL;

    push_back( &list, 1 );
    push_back( &list, 2 );
    push_back( &list, 3 );
    push_back( &list, 4 );

    push_back_single_pointer( list2, 1 );
    push_back_single_pointer( list2, 2 );
    push_back_single_pointer( list2, 3 );
    push_back_single_pointer( list2, 4 );

    print_list( list );
    print_list( list2 );
}

void LinkedList_C::print_list( linked_list * list )
{
    cout << "[ ";

    while( list != 0 )
    {
        cout<< list->data << ", ";
        list = list->pNextNode;
    }
    cout << " ] \n";

}

#endif