#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinked.h"

DoubleNode *DoublenodeInit() {

    DoubleNode *Dnd = malloc(sizeof(DoubleNode));

    if (Dnd == NULL) {
        printf("Memory allocation failed for DoublenodeInit()\n");
        return NULL;
    }

    Dnd->data = NULL;
    Dnd->next = NULL;
    Dnd->prev = NULL;

    return Dnd;

}

void dll_set_node_data(DoubleNode * node, void * data) {

    node->data = malloc(sizeof(node->data) +2);
    memcpy(node->data, data, sizeof(data) +2);

}

void dll_set_node_next(DoubleNode* DoubleNode, struct DoubleNode *pNode) {

    DoubleNode->next = pNode;

}

void dll_set_node_prev(DoubleNode* DoubleNode, struct DoubleNode *pNode) {
    DoubleNode->prev = pNode;
}

DoublyLinkedList dll_init(size_t dataSize) {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->datasize = dataSize;
    list -> head = NULL;
    list -> tail = NULL;

    return *list;

}

int dll_free(DoublyLinkedList * list) {

        free(list->head);
        list->head = NULL;
        free(list->tail);
        list->tail = NULL;
        list->size = 0;
        return 0;

}


int dll_is_empty(DoublyLinkedList * list) {

    if (list -> head == NULL) {
        return 1;
    }else {
        return 0;
    }
}

int dll_size(const DoublyLinkedList * list) {

    const struct DoubleNode * crr = list -> head;

    int cnt = 0;

        while (crr != NULL) {
            crr = crr->next;
            cnt++;
        }

    return cnt;

}

// Inserting items in the linked list
void dll_push_front(DoublyLinkedList * list, DoubleNode* sNode) {

    if (list->head == NULL && list->tail == NULL) {
        list->head = sNode;
        list->tail = sNode;
    }else {

        DoubleNode *temp= malloc(sizeof(DoubleNode));

        if (!temp) {

            printf("Memory allocation failed for dll_push_front()\n");
            free(temp);

        }


       temp = list->head;
        list->head = sNode;
        sNode->next = temp;
        temp->prev = sNode;


    }



}

void dll_push_back(DoublyLinkedList * list, DoubleNode * DoubleNode) {

    list -> tail = DoubleNode;
    DoubleNode -> next = NULL;


}

void dll_insert_at(DoublyLinkedList * list, DoubleNode * indexNode, DoubleNode * insertNode) {

    DoubleNode *curr = list -> head;

    while (curr-> next != indexNode) {
        curr= curr-> next;
    }

    curr -> next = insertNode;
    insertNode->prev = curr;
    insertNode -> next = indexNode;
    indexNode->prev = insertNode;

}

// Removing items from the list


void dll_remove_at(DoublyLinkedList * list, DoubleNode * node) {

    DoubleNode *curr = list -> head;

    while (curr->next != node) {
            curr = curr -> next;
    }

    curr -> next = node->next;
    node->next->prev = curr;


}

void dll_pop_front(DoublyLinkedList * list) {

    list -> head = list -> head -> next;

}

void dll_pop_back(DoublyLinkedList * list) {

    DoubleNode *curr = list -> head;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }

    curr -> next = NULL;

}

void dll_remove_value(DoublyLinkedList * list, void * data) {

    DoubleNode * curr = list->head;

    while (curr != NULL) {

        curr = curr -> next;
        if (curr->data == data) {
            curr->data = NULL;
        }

    }



}

// Acessing the list
DoubleNode dll_get_at(DoublyLinkedList * list, DoubleNode * node) {

    DoubleNode *curr = list->head;

    while (curr != node) {
        curr = curr->next;
    }

    return *curr;

}

DoubleNode dll_find(DoublyLinkedList * list, void * data) {

    DoubleNode *curr = malloc(sizeof(DoubleNode));
    if (!curr) {
        printf("Memory allocation failed for dll_find()\n");
        free(curr);

    }

    curr = list->head;

    while (curr->data != data) {
        curr = curr->next;
    }

    return *curr;

}

const char *dll_get_data(DoublyLinkedList *list, DoubleNode *DoubleNode) {


        if (DoubleNode->data == NULL) {
            return NULL;
        }else {
                return DoubleNode->data;
        }

}

// Utility

void dll_print(DoublyLinkedList * list) {

    DoubleNode *curr = malloc(sizeof(DoubleNode));
    if (!curr) {
        printf("Memory allocation failed for dll_print()\n");
        free(curr);
    }

    curr = list->head;

    while(curr != NULL) {
        printf("%s\n", curr->data);
        curr = curr -> next;
    }

    free(curr);

}

void dll_reverse(DoublyLinkedList * list) {

}

void dll_clone(DoublyLinkedList * list, DoublyLinkedList * copy) {

}


