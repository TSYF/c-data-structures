#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    int* data;
    size_t size;
    size_t capacity;

    int (*peek)(struct Stack*);
    int (*push)(struct Stack*, int);
    int (*pop)(struct Stack*);
    int (*contains)(struct Stack*, int);
    void (*clear)(struct Stack*);
    bool (*is_empty)(struct Stack*);
    char* (*to_string)(struct Stack*);
} Stack;

Stack create_stack();

#endif