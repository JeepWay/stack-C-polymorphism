#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../stack/stack_char.h"

int main() {
    CharStack *stack = createCharStack();
    printf("topIndex:%d, capacity:%d\n", stack->topIndex, stack->capacity);

    pushCharStack(stack, "a");
    pushCharStack(stack, "b");
    pushCharStack(stack, "c");
    pushCharStack(stack, "d");
    pushCharStack(stack, "e");
    pushCharStack(stack, "f");
    pushCharStack(stack, "g");
    pushCharStack(stack, "h");
    pushCharStack(stack, "i");
    pushCharStack(stack, "j");
    pushCharStack(stack, "k");

    printf("pop char: %c\n", *popCharStack(stack)); // k
    printf("top char: %c\n", *topCharStack(stack)); // j

    pushCharStack(stack, "l");  //  l j i h g f e d c b a
    printCharStack(stack);
    return 0;
}