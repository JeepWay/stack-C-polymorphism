#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include "../stack/stack.h"

int main() {
    /**
     * charStack
     */
    Stack *charStack = createStack(CHAR);
    if (*(char*)charStack->top(charStack) == '\0') {
        printf("charStack is empty\n");
    }
    char c = 'a';
    charStack->push(charStack, &c);  // passed by reference
    char *poppedChar = (char *)charStack->pop(charStack);
    printf("Popped from char stack: %c\n\n", *poppedChar);
    charStack->free(charStack);

    /**
     * stringStack
     */
    Stack *stringStack = createStack(STRING);
    if (*(char*)stringStack->top(stringStack) == '\0') {
        printf("stringStack is empty\n");
    }
    char *str = "hello";
    stringStack->push(stringStack, str);
    char *poppedStr = (char *)stringStack->pop(stringStack);
    printf("Popped from string stack: %s\n\n", poppedStr);
    stringStack->free(stringStack);


    /**
     * intStack
     */
    Stack *intStack = createStack(INT);
    if (!intStack->top(intStack)) {
        printf("intStack is empty\n");
    }
    int i = 123;
    intStack->push(intStack, &i);
    int *poppedInt = (int *)intStack->pop(intStack);
    printf("Popped from int stack: %d\n\n", *poppedInt);
    intStack->free(intStack);

    return 0;
}
