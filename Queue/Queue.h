#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int* data;
    size_t size;
    size_t capacity;

    int (*peek)(struct Queue*);
    int (*enqueue)(struct Queue*, int);
    int (*dequeue)(struct Queue*);
    int (*contains)(struct Queue*, int);
    void (*clear)(struct Queue*);
    bool (*is_empty)(struct Queue*);
    char* (*to_string)(struct Queue*);
} Queue;

Queue create_queue();

#endif