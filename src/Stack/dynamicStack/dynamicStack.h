#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include <stddef.h>
#include <stdlib.h>

typedef struct DynamicNode {

    void * data;
    size_t dataSize;
    struct DynamicNode* next;


}DynamicNode;

typedef struct DynamicStack {

    struct DynamicNode *top;
    int size;
    size_t dataSize;


}DynamicStack;

DynamicNode *dynamic_node_init(size_t dataSize);
void dynamic_node_set_data(DynamicNode *node, void *data);

DynamicStack * dynamic_stack_init(size_t dataSize);

void dynamic_stack_push(DynamicStack * stack, DynamicNode* node);
void dynamic_stack_pop(DynamicStack * stack);

void dynamic_stack_print(DynamicStack * stack);


#endif //DYNAMICSTACK_H