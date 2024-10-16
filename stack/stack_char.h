#include <stdbool.h>

typedef struct CharStack {
    int topIndex;
    int capacity;   // changes dynamically
    char* elements; 
} CharStack;

CharStack* createCharStack();

void initCharStack(CharStack *s);

bool isFullCharStack(CharStack *s);

bool isEmptyCharStack(CharStack *s);

void resizeCharStack(CharStack *s);     // internal function

void pushCharStack(CharStack *s, char* c);

char* popCharStack(CharStack *s);

char* topCharStack(CharStack *s);

int sizeCharStack(CharStack *s);

void freeCharStack(CharStack *s);

void printCharStack(CharStack *s);