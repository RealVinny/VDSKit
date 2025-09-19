#include "dynamicStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>





void dynamic_node_set_data(DynamicNode *node, void *data) {

   node->data = malloc(node->dataSize);
    memcpy(node->data, data, node->dataSize+1);

}


DynamicNode *dynamic_node_init(size_t dataSize) {

   DynamicNode *node = malloc(sizeof(DynamicNode));

    if (!node) {
        printf("There was a problem allocating memory!");
        free(node);
       return NULL;
    }

    node->dataSize = dataSize;
    node->data = malloc(dataSize);
    node->next = NULL;
    return node;


}


DynamicStack * dynamic_stack_init(size_t dataSize) {
    DynamicStack * stack = malloc(sizeof(DynamicStack));

    if (!stack) {
        printf("There was a problem allocating memory!");
        return NULL;

    }

    stack->top = NULL;
    stack->size = 0;
    stack->dataSize = dataSize;

    return stack;
}

void dynamic_stack_push(DynamicStack * stack, DynamicNode * node) {

    DynamicNode *temp = malloc(sizeof(DynamicNode));
    temp = dynamic_node_init(node->dataSize);

    if (!temp) {
        printf("There was a problem allocating memory!");
        free(temp);
        return;

    }

    if (stack->top == NULL) {
        stack->top = node;
        free(temp);
    }else {
        temp = stack->top;
        stack->top = node;
        node->next = temp;

    }





}


void dynamic_stack_pop(DynamicStack * stack) {

    stack->top = stack->top->next;

}

void dynamic_stack_print(DynamicStack * stack) {

    DynamicNode * node = malloc(sizeof(DynamicNode));
    node = dynamic_node_init(stack->top->dataSize);
    node = stack->top;

    while (node) {
        printf("%s\n", node->data);
        node = node->next;
    }


}