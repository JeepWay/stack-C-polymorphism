#include <stdbool.h>

typedef enum StackType {
    CHAR,
    STRING,
    INT,
} StackType;

typedef struct Stack {
    int topIndex;
    int capacity;
    void *elements;
    StackType type;

    // function pointers
    void (*init)(struct Stack *s);
    void (*push)(struct Stack *s, void *element);
    void* (*pop)(struct Stack *s);
    void* (*top)(struct Stack *s);
    bool (*isFull)(struct Stack *s);
    bool (*isEmpty)(struct Stack *s);
    int (*size)(struct Stack *s);
    void (*free)(struct Stack *s);
    void (*print)(struct Stack *s);
} Stack;

Stack* createStack(StackType type);

bool isEmptyStack(Stack *s);

bool isFullStack(Stack *s);

int sizeStack(Stack *s);

void freeStack(Stack *s);
