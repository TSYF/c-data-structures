#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>

typedef struct ArrayList {
    int* data;
    size_t size;
    size_t capacity;

    int (*get)(struct ArrayList*, int);
    int (*set)(struct ArrayList*, int, int);
    int (*push)(struct ArrayList*, int);
    int (*pop)(struct ArrayList*);
    int (*shift)(struct ArrayList*);
    int (*unshift)(struct ArrayList*, int);
    char* (*to_string)(struct ArrayList*);
} ArrayList;

ArrayList create_array_list();

#endif