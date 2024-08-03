#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "utils/utils.h"
#define M_PHI 1.6180339887498948482045868343656381177203091798058
#define FOR_EACH(startAt, endAt) for (int i = startAt; i < endAt; i++)

static int _peek(Queue* queue);
static int _contains(Queue* queue, int value);
static int _enqueue(Queue* queue, int item);
static int _dequeue(Queue* queue);
static char* _to_string(Queue* queue);
static bool _is_empty(Queue* queue);
static void _clear(Queue* queue);

Queue create_queue() {
    static Queue queue;
    queue.data = NULL;
    queue.size = 0;
    queue.capacity = 0;

    queue.peek = _peek;
    queue.contains = _contains;
    queue.enqueue = _enqueue;
    queue.dequeue = _dequeue; 
    queue.is_empty = _is_empty;
    queue.clear = _clear;

    queue.to_string = _to_string;

    return queue;
}

static int _peek(Queue* queue) {
    return queue->data[queue->size - 1];
}

static int _contains(Queue* queue, int value) {
    FOR_EACH(0, queue->size) {
        if (queue->data[i] == value) {
            return i;
        }
    }
    return -1;
}

static int _enqueue(Queue* queue, int item)  {
    if (queue->size == queue->capacity) {
        size_t new_cap = round((queue->capacity + 1) * M_PHI);
        queue->capacity = queue->capacity == 0 ? 4 : new_cap;
        void* reallOK = realloc(queue->data, new_cap * sizeof(int));
        if (reallOK == NULL) {
            perror("Error reallocating memory\n");
            return -1;
        }
        queue->data = (int*)reallOK;
    }

    // Shift the array by moving the memory starting from the end
    for (int i = queue->size; i > 0; i--) {
        queue->data[i] = queue->data[i - 1];
    }
    queue->data[0] = item;
    queue->size++;
    return queue->data[0];
}

static int _dequeue(Queue* queue) {
    if (queue->size == 0) {
        return -1; // Array is empty
    }

    int last_element = queue->data[queue->size - 1];
    queue->size--;
    queue->capacity--;

    return last_element;
}

static void _clear(Queue* queue) {
    free(queue->data);
    queue->capacity = 10;
    queue->data = malloc(sizeof(int) * queue->capacity);
    queue->size = 0;
}

static bool _is_empty(Queue* queue) {
    return queue->size == 0;
}

static char* _to_string(Queue* queue) {
    return list_to_string(queue->data, queue->size);
}