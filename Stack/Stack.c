#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "utils/utils.h"
#define M_PHI 1.6180339887498948482045868343656381177203091798058
#define FOR_EACH(startAt, endAt) for (int i = startAt; i < endAt; i++)

static int _push(Stack* stack, int item);
static int _pop(Stack* stack);
static int _peek(Stack* queue);
static int _contains(Stack* queue, int value);
static char* _to_string(Stack* queue);
static bool _is_empty(Stack* queue);
static void _clear(Stack* queue);

Stack create_stack() {
    static Stack stack;
    stack.data = NULL;
    stack.size = 0;
    stack.capacity = 0;

    stack.peek = _peek;
    stack.contains = _contains;
    stack.push = _push;
    stack.pop = _pop;
    stack.is_empty = _is_empty;
    stack.clear = _clear;

    stack.to_string = _to_string;

    return stack;
}

static int _peek(Stack* stack) {
    return stack->data[0];
}

static int _contains(Stack* stack, int value) {
    FOR_EACH(0, stack->size) {
        if (stack->data[i] == value) {
            return i;
        }
    }
    return -1;
}

static int _pop(Stack* stack) {
    if (stack->size == 0) {
        return -1; // Array is empty
    }

    int first_element = stack->data[0];

    // Shift the array by moving the memory
    for (int i = 0; i < stack->size - 1; i++) {
        stack->data[i] = stack->data[i + 1];
    }

    stack->size--;
    return first_element;
}

static int _push(Stack* stack, int item) {
    if (stack->size >= stack->capacity) {
        size_t new_cap = round((stack->capacity + 1) * M_PHI);
        stack->capacity = stack->capacity == 0 ? 4 : new_cap;
        void* reallOK = realloc(stack->data, new_cap);
        if (reallOK == NULL) {
            perror("Error reallocating memory\n");
            return -1;
        }
        stack->data = (int*)reallOK;
    }

    // Shift the array by moving the memory starting from the end
    for (int i = stack->size; i > 0; i--) {
        stack->data[i] = stack->data[i - 1];
    }
    stack->data[0] = item;
    stack->size++;
    return stack->data[0];
}

static char* _to_string(Stack* stack) {
    return list_to_string(stack->data, stack->size);
}

static bool _is_empty(Stack* stack) {
    return stack->size == 0;
}

static void _clear(Stack* stack) {
    free(stack->data);
    stack->capacity = 10;
    stack->data = malloc(sizeof(int) * stack->capacity);
    stack->size = 0;
}