#include <stdbool.h>

typedef struct StringStack {
    int topIndex;
    int capacity;   // changes dynamically
    char** elements; 
} StringStack;

StringStack* createStringStack();

void initStringStack(StringStack *s);

bool isFullStringStack(StringStack *s);

bool isEmptyStringStack(StringStack *s);

void resizeStringStack(StringStack *s);     // internal function

void pushStringStack(StringStack *s, char* str);

char* popStringStack(StringStack *s);

char* topStringStack(StringStack *s);

int sizeStringStack(StringStack *s);

void freeStringStack(StringStack *s);

void printStringStack(StringStack *s);