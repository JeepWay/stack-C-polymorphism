#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../stack/stack_string.h"

int main() {
    StringStack *stack = createStringStack();
    printf("topIndex:%d, capacity:%d\n", stack->topIndex, stack->capacity);

    pushStringStack(stack, "ab ab");
    pushStringStack(stack, "cd cd");
    pushStringStack(stack, "ef");
    pushStringStack(stack, "gh");
    pushStringStack(stack, "ij");
    pushStringStack(stack, "kl");

    popStringStack(stack);
    popStringStack(stack);
    pushStringStack(stack, "mn mn\n");

    printStringStack(stack);
    return 0;
}