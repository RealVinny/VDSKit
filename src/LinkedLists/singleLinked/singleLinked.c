#include "singleLinked.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


SingleNode *singlenodeInit() {

    SingleNode *node = malloc(sizeof(SingleNode));

    if (node == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }

    node->data = NULL;
    node->next = NULL;

    return node;



}

void sll_set_node_data(SingleNode * node, void * data) {

    node->data = data;

}

void sll_set_node_pointer(SingleNode * node, SingleNode *pNode) {

    node->next = pNode;

}

singleLinkedList sll_init(size_t size) {

    singleLinkedList *list = malloc(sizeof(singleLinkedList));

    list->dataSize = size;
    list -> head = NULL;
    list -> tail = NULL;

    return *list;

}

int sll_free(singleLinkedList * list) {

        free(list->head);
        list->head = NULL;
        free(list->tail);
        list->tail = NULL;
        list->size = 0;
        return 0;
}


int sll_is_empty(singleLinkedList * list) {

    if (list -> head == NULL) {
        return 1;
    }else {
        return 0;
    }
}

int sll_size(const singleLinkedList * list) {

    const SingleNode * crr = list -> head;

    int cnt = 0;

        while (crr != NULL) {
            cnt++;
        }

    return cnt;

}

// Inserting items in the linked list
void sll_push_front(singleLinkedList * list, SingleNode * sNode) {

    SingleNode *head = malloc(sizeof(SingleNode));

    if (!head) {
        printf("Memory allocation error\n");
        free(head);
        return;
    }

    head = list -> head;
    list -> head = sNode;
    sNode->next = head;

}

void sll_push_back(singleLinkedList * list, SingleNode * node) {

    if (list->head == NULL && list->tail == NULL) {
        list->head = node;
        list->tail = node;
    }else if (list->head != NULL) {

        SingleNode *tmp = list->head;
        list->head = node;
        node->next = tmp;

        if (list->size >= 1) {
            list->tail = tmp;
        }
        list->size++;

    }

}

void sll_insert_at(singleLinkedList * list, SingleNode * indexNode, SingleNode * insertNode) {

    SingleNode *curr = list -> head;

    while (curr-> next != indexNode) {
        curr= curr-> next;
    }
    curr -> next = insertNode;
    insertNode -> next = indexNode;

}

// Removing items from the list


void sll_remove_at(singleLinkedList * list, SingleNode * node) {

    SingleNode *curr = list -> head;

    while (curr->next != NULL) {
        if (curr == node) {
            SingleNode *tmp = node->next;
            node->next = tmp;
            free(curr);
            list->size--;
            return;
        }
        curr = curr->next;
    }

}

void sll_pop_front(singleLinkedList * list) {

    list -> head = list -> head -> next;

}

void sll_pop_back(singleLinkedList * list) {

    SingleNode *curr = list -> head;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }

    curr -> next = NULL;

}

void sll_remove_data(SingleNode * node) {

    node->data = NULL;
    free(node->data);

}

// Acessing the list
SingleNode sll_get_at(singleLinkedList * list, SingleNode * node) {

    SingleNode *curr = list->head;

    while (curr != node) {
        curr = curr->next;
    }

    return *curr;

}

SingleNode sll_find(singleLinkedList * list, void * data) {

    SingleNode *curr = list->head;

    while (curr->data != data) {
        curr = curr->next;
    }

    return *curr;

}

const char *sll_get_data(singleLinkedList *list, SingleNode *node) {


        if (node->data == NULL) {
            return NULL;
        }else {
                return node->data;
        }

}

// Utility

void sll_print(singleLinkedList * list) {

    SingleNode *curr = list->head;
    while (curr != NULL) {
        if (curr->data == NULL) {
            printf("NULL");
            curr = curr->next;
        }else {
            printf("%s\n", curr->data);
            curr = curr -> next;
        }
    }

}

void sll_reverse(singleLinkedList * list) {

}

void sll_clone(singleLinkedList * list, singleLinkedList * copy) {

}


