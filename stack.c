//
//  stack.c
//  
//
//  Created by Katie Pan on 8/8/16.
//
//

#include "stack.h"
#include <string.h>
#include <stdlib.h>

struct NODE {
    char * data;
    struct NODE * next;
};

struct STACK {
    struct NODE * head;
};

struct STACK *STACK_create() {
    struct STACK * stack = (struct STACK *) malloc(sizeof(struct STACK));
    if(!stack)
        return NULL;
    
    stack->head = NULL;
    return stack;
}

int STACK_push(struct STACK *stack, char *data){
    struct NODE * node;
    node = (struct NODE *)malloc(sizeof(struct NODE));
    if(!node)
        return 0;
    
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    return 1;
}

char *STACK_pop(struct STACK *stack){
    if(!stack)
        return NULL;
    if(!stack->head)
        return NULL;
    struct NODE * oldNode = stack->head;
    char * data = stack->head->data;
    stack->head = stack->head->next;
    
    free(oldNode);
    
    return data;
}

void STACK_destroy(struct STACK * stack){
    free(stack);
}
