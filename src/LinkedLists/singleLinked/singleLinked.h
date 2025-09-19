//
// Created by leo on 08/06/25.
//

#ifndef SINGLELINKED_H
#define SINGLELINKED_H
#include <stddef.h>
#include <stdlib.h>

typedef struct  SingleNode{

    void *data;
    struct SingleNode  *next;

}SingleNode;


typedef struct {

    SingleNode *head;
    SingleNode *tail;
    size_t dataSize;
    int size;

} singleLinkedList;


// Managing nodes
SingleNode *singlenodeInit();
void sll_set_node_data(SingleNode  * node, void * data);


// Initializing and managing the linkedList
singleLinkedList sll_init(size_t size);
int sll_free(singleLinkedList * list);
int sll_is_empty(singleLinkedList * list);
int sll_size(const singleLinkedList * list);

// Inserting items in the linked list
void sll_push_front(singleLinkedList * list, SingleNode * node);
void sll_push_back(singleLinkedList * list,  SingleNode * node);
void sll_insert_at(singleLinkedList * list, SingleNode * node, SingleNode * insert);

// Removing items from the list
void sll_pop_front(singleLinkedList * list);
void sll_pop_back(singleLinkedList * list);
void sll_remove_at(singleLinkedList * list, SingleNode * node);
void sll_remove_value(singleLinkedList * list, void * data);

// Acessing the list
SingleNode sll_get_at(singleLinkedList * list, SingleNode * node);
SingleNode sll_find(singleLinkedList * list, void * data);

const char *sll_get_data(singleLinkedList * list, SingleNode *node);

// Utility

void sll_print(singleLinkedList * list);
void sll_reverse(singleLinkedList * list);
void sll_clone(singleLinkedList * list, singleLinkedList * copy);

#endif //SINGLELINKED_H
