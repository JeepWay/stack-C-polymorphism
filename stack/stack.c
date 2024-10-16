#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "stack.h"
#include "stack_char.h"
#include "stack_string.h"
#include "stack_int.h"

Stack* createStack(StackType type) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->topIndex = EMPTY_INDEX;
    stack->capacity = INIT_STACK_SIZE;
    stack->type = type;

    stack->isEmpty = (bool (*)(Stack *)) isEmptyStack;
    stack->isFull = (bool (*)(Stack *)) isFullStack;
    stack->size = (int (*)(Stack *)) sizeStack;
    stack->free = (void (*)(Stack *)) freeStack;

    switch (type) {
        case CHAR:
            stack->init = (void (*)(Stack *)) initCharStack;
            stack->push = (void (*)(Stack *, void *)) pushCharStack;
            stack->pop = (void* (*)(Stack *)) popCharStack;
            stack->top = (void* (*)(Stack *)) topCharStack;
            stack->print = (void (*)(Stack *)) printCharStack;
            break;
        case STRING:
            stack->init = (void (*)(Stack *)) initStringStack;
            stack->push = (void (*)(Stack *, void *)) pushStringStack;
            stack->pop = (void* (*)(Stack *)) popStringStack;
            stack->top = (void* (*)(Stack *)) topStringStack;
            stack->print = (void (*)(Stack *)) printStringStack;
            break;
        case INT:
            stack->init = (void (*)(Stack *)) initIntStack;
            stack->push = (void (*)(Stack *, void *)) pushIntStack;
            stack->pop = (void* (*)(Stack *)) popIntStack;
            stack->top = (void* (*)(Stack *)) topIntStack;
            stack->print = (void (*)(Stack *)) printIntStack;
            break;
        default:
            free(stack);
            return NULL;
    }

    stack->init(stack);
    return stack;
}

bool isEmptyStack(Stack *s) {
    return(s->topIndex == EMPTY_INDEX);
}

bool isFullStack(Stack *s) {
    return(s->topIndex >= (s->capacity - 1));
}

int sizeStack(Stack *s) {
    return s->topIndex + 1;
}

void freeStack(Stack *s) {
    free(s->elements);
    free(s);
}
