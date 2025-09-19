#ifndef DOUBLE_LINKED_H
#define DOUBLE_LINKED_H
#include <stddef.h>


typedef struct DoubleNode {

    void *data;
    struct DoubleNode *next;
    struct DoubleNode *prev;

}DoubleNode;

typedef struct {

    struct DoubleNode *head;
    struct DoubleNode *tail;
    size_t datasize;
    int size;

} DoublyLinkedList;


DoubleNode *DoublenodeInit();

void dll_set_node_data(DoubleNode *DoubleNode, void *data);

// Initializing and managing the linkedList
DoublyLinkedList dll_init(size_t size);

int dll_free(DoublyLinkedList *list);

int dll_is_empty(DoublyLinkedList *list);

int dll_size(const DoublyLinkedList *list);

// Inserting items in the linked list
void dll_push_front(DoublyLinkedList *list, DoubleNode *DoubleNode);

void dll_push_back(DoublyLinkedList *list, DoubleNode *DoubleNode);

void dll_insert_at(DoublyLinkedList *list, DoubleNode * indexNode , DoubleNode *insert);

// Removing items from the list
void dll_pop_front(DoublyLinkedList *list);

void dll_pop_back(DoublyLinkedList *list);

void dll_remove_at(DoublyLinkedList *list, DoubleNode *DoubleNode);

void dll_remove_value(DoublyLinkedList *list, void *data);

// Acessing the list
DoubleNode dll_get_at(DoublyLinkedList *list, DoubleNode *DoubleNode);

DoubleNode dll_find(DoublyLinkedList *list, void *data);

const char *dll_get_data(DoublyLinkedList *list, DoubleNode *DoubleNode);

// Utility

void dll_print(DoublyLinkedList *list);

void dll_reverse(DoublyLinkedList *list);

void dll_clone(DoublyLinkedList *list, DoublyLinkedList *copy);

#endif //DOUBLE_LINKED_H
