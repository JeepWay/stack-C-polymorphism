# Implementation of a Stack with Function Pointers to Simulate Polymorphism in C Language

## Description
* The stack is implemented using array.
* The stack uses function pointers to simulate polymorphism in C language.
* The function pointers are used to point to the real implementation of common stack operations, 
e.g., push, pop, and top, like [std::stack](https://cplusplus.com/reference/stack/stack/) in C++.
* This project is default to support the data type of `int`, `char`, and `string`, but it can be easily extended 
to support other data types, e.g., `float`, `double` and so on.

## Function Pointers
* `void (*init)(struct Stack *s)`: Initialize the stack.
* `void (*push)(struct Stack *s, void *element)`: Push an element into the stack.
* `void* (*pop)(struct Stack *s)`: Pop an element from the stack.
* `void* (*top)(struct Stack *s)`: Get the top element of the stack.
* `bool (*isFull)(struct Stack *s)`: Check if the stack is full.
* `bool (*isEmpty)(struct Stack *s)`: Check if the stack is empty.
* `int (*size)(struct Stack *s)`: Get the current size of the stack.
* `void (*free)(struct Stack *s)`: Free the memory occupied by the stack.
* `void (*print)(struct Stack *s)`: Print the information of the stack.

## Simple Usage
1. Compile the source code to object files.
    ```bash
    $ make test_stack
    $ gcc -c -o <your_program>.o <your_program>.c
    ```
2. Link the object files to the executable file.
    ```bash
    $ gcc -Wall -o <your_program> <your_program>.o stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o
    $ ./<your_program>
    ```
3. Demo of stack of `int` data type.
    ```cpp
    #include "stack/stack.h"
    int main() {
        Stack *stack = createStack(INT);
        if (!stack->top(stack)) {
            printf("stack is empty\n");
        }
        int i = 123;
        stack->push(stack, &i);
        int *poppedInt = (int *)stack->pop(stack);
        printf("Popped from int stack: %d\n\n", *poppedInt);
        stack->free(stack);
        return 0;
    }
    ```
4. Demo of stack of `char` data type.
    ```cpp
    #include "stack/stack.h"
    int main() {
        Stack *stack = createStack(CHAR);
        if (*(char*)stack->top(stack) == '\0') {
            printf("stack is empty\n");
        }
        char c = 'a';
        stack->push(stack, &c);  // passed by reference
        char *poppedChar = (char *)stack->pop(stack);
        printf("Popped from char stack: %c\n\n", *poppedChar);
        stack->free(stack);
        return 0;
    }
    ```

## Key Note
* The parameter passed to `createStack` is the type of the stack, which can be `INT`, `CHAR`, or `STRING`. You can also see the supported data types in the `struct StackTyp`e of [`stack/stack.h`](https://github.com/JeepWay/stack-C-polymorphism/blob/main/stack/stack.h).
* When using `push`, you need to pass the memory address of the data to be pushed into the stack, because the function pointer of `push` is defined as `void (*push)(struct Stack *s, void *element)`.
* When using `pop` and `top`, you need to cast the return value to the correct data type, just like using `malloc()` in C, to avoid the warning of `incompatible pointer type`, beacuse the return value is a `void *` pointer.
* When stack is empty during `pop` and `top`: 
    * For `INT` type, the return value of `pop` and `top` are `NULL`.
    * For `CHAR` type, the return value of `pop` and `top` are `"\0"`.
    * For `STRING` type, the return value of `pop` and `top` are `"\0"`.

## Test
* Test stack with polymorphism
    ```bash
    make test TARGET=test_stack
    ```
* Test stack of int
    ```bash
    make test TARGET=test_stack_int   
    ```
* Test stack of char
    ```bash
    make test TARGET=test_stack_char   
    ```
* Test stack of string
    ```bash
    make test TARGET=test_stack_string   
    ```

## Extension
If you want to extend the stack to support other data types, e.g., `float`, `double`, you can follow the steps below:
1. Add a new stack file, e.g., `stack_float.c` and `stack_float.h` in the `stack` directory.
2. Implement the stack functions in `stack_float.c` and declare the functions in `stack_float.h`.
3. Add the new rules in the `Makefile` to compile the new stack files.
    ```makefile
    OBJS_STACK = stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o stack/stack_float.o 
    ```
4. Update `enum StackType` in `stack/stack.h` to support the new data type.
5. Update `stack/stack.c` to support the new data type.
    * Add `#include "stack_float.h"`
    * Add the switch case according to the new data type in `createStack` function.
6. Re-compile the source code and link the object files to the executable file.
    ```bash
    $ make test_stack
    $ gcc -c -o <your_program>.o <your_program>.c
    $ gcc -Wall -o <your_program> <your_program>.o stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o stack/stack_float.o
    $ ./<your_program>
    ```