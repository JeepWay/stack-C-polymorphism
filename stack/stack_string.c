#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#include "stack_string.h"

StringStack* createStringStack() {
    StringStack *s = (StringStack*)malloc(sizeof(StringStack));
    initStringStack(s);
    return s;
}

void initStringStack(StringStack *s) {
    s->topIndex = EMPTY_INDEX;
    s->capacity = INIT_STACK_SIZE;
    s->elements = (char**)malloc(s->capacity * sizeof(char *));
}

bool isFullStringStack(StringStack *s) {
    return(s->topIndex >= (s->capacity - 1));
}

bool isEmptyStringStack(StringStack *s) {
    return(s->topIndex == EMPTY_INDEX);
}

void resizeStringStack(StringStack *s) {
    s->capacity *= 2;
    s->elements = (char**)realloc(s->elements, s->capacity * sizeof(char *));
}

void pushStringStack(StringStack *s, char* str) {
    if (isFullStringStack(s)) {
        resizeStringStack(s);
    }
    s->elements[++(s->topIndex)] = str;
}

char* popStringStack(StringStack *s) {
    if (isEmptyStringStack(s)) {
        return "\0";    // Return a pointer to the NUL character for comparison purposes
    }
    return s->elements[s->topIndex--];
}

char* topStringStack(StringStack *s) {
    if (isEmptyStringStack(s)) {
        return "\0";    // Return a pointer to the NUL character for comparison purposes
    }
    return s->elements[s->topIndex];
}

int sizeStringStack(StringStack *s) {
    return s->topIndex + 1;
}

void freeStringStack(StringStack *s) {
    free(s->elements);
    free(s);
}

void printStringStack(StringStack *s) {
    printf("topIndex:%d, capacity:%d\n", s->topIndex, s->capacity);
    printf("stack elements from top: ");
    for (int i = s->topIndex; i >= 0; i--) {
        printf("%s ", s->elements[i]);
    }
    printf("\n");
}