#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#include "stack_char.h"

CharStack* createCharStack() {
    CharStack *s = (CharStack*)malloc(sizeof(CharStack));
    initCharStack(s);
    return s;
}

void initCharStack(CharStack *s) {
    s->topIndex = EMPTY_INDEX;
    s->capacity = INIT_STACK_SIZE;
    s->elements = (char*)malloc(s->capacity * sizeof(char));
}

bool isFullCharStack(CharStack *s) {
    return(s->topIndex >= (s->capacity - 1));
}

bool isEmptyCharStack(CharStack *s) {
    return(s->topIndex == EMPTY_INDEX);
}

void resizeCharStack(CharStack *s) {
    s->capacity *= 2;
    s->elements = (char*)realloc(s->elements, sizeof(char) * s->capacity);
}

void pushCharStack(CharStack *s, char *c) {
    if (isFullCharStack(s)) {
        resizeCharStack(s);
    }
    s->elements[++(s->topIndex)] = *c;
}

char* popCharStack(CharStack *s) {
    if (isEmptyCharStack(s)) {
        return "\0";    // Return a pointer to the NUL character for comparison purposes
    }
    return &(s->elements[s->topIndex--]);
}

char* topCharStack(CharStack *s) {
    if (isEmptyCharStack(s)) {
        return "\0";    // Return a pointer to the NUL character for comparison purposes    
    }
    return &(s->elements[s->topIndex]);
}

int sizeCharStack(CharStack *s) {
    return s->topIndex + 1;
}

void freeCharStack(CharStack *s) {
    free(s->elements);
    free(s);
}

void printCharStack(CharStack *s) {
    printf("topIndex:%d, capacity:%d\n", s->topIndex, s->capacity);
    printf("stack elements from top: ");
    for (int i = s->topIndex; i >= 0; i--) {
        printf("%c ", s->elements[i]);
    }
    printf("\n");
}