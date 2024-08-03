#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "utils/utils.h"
#define M_PHI 1.6180339887498948482045868343656381177203091798058
#define FOR_EACH(startAt, endAt) for (int i = startAt; i < endAt; i++)

static int _get(ArrayList* arr, int index);
static int _set(ArrayList* arr, int index, int value);
static int _push(ArrayList* arr, int item);
static int _pop(ArrayList* arr);
static int _shift(ArrayList* arr);
static int _unshift(ArrayList* arr, int item);
static char* _to_string(ArrayList* arr);

ArrayList create_array_list() {
    static ArrayList arr;
    arr.data = NULL;
    arr.size = 0;
    arr.capacity = 0;

    arr.get = _get;
    arr.set = _set;
    arr.push = _push;
    arr.pop = _pop;
    arr.shift = _shift;
    arr.unshift = _unshift;

    arr.to_string = _to_string;

    return arr;
}

static int _get(ArrayList* arr, int index) {
    if (index < 0) {
        index = arr->size + index;
    }
    
    return arr->data[index];
}

static int _set(ArrayList* arr, int index, int value) {
    if (index > arr->size) {
        return -1;
    }

    if (index < 0) {
        index = arr->size + index;
    }

    if (index == arr->size) {
        if (arr->capacity == arr->size) {
            arr->capacity = arr->capacity == 0 ? 4 : arr->capacity * 2;
            arr->data = realloc(arr->data, arr->capacity * sizeof(int));
        }
        arr->size++;
    } 
    return arr->data[index] = value;
}

static int _push(ArrayList* arr, int item) {
    if (arr->size >= arr->capacity) {
        size_t new_cap = round(arr->capacity * M_PHI);
        arr->capacity = arr->capacity == 0 ? 4 : new_cap;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
    }

    arr->data[arr->size++] = item;
    return arr->data[arr->size - 1];
}

static int _pop(ArrayList* arr) {
    if (arr->size == 0) {
        return -1; // Array is empty
    }

    int last_element = arr->data[arr->size - 1];
    arr->size--;
    arr->capacity--;

    return last_element;
}

static int _shift(ArrayList* arr) {
    if (arr->size == 0) {
        return -1; // Array is empty
    }

    int first_element = arr->data[0];

    // Shift the array by moving the memory
    for (int i = 0; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;
    return first_element;
}

static int _unshift(ArrayList* arr, int item) {
    if (arr->size >= arr->capacity) {
        size_t new_cap = round((arr->capacity + 1) * M_PHI);
        arr->capacity = arr->capacity == 0 ? 4 : new_cap;
        void* reallOK = realloc(arr->data, new_cap);
        if (reallOK == NULL) {
            perror("Error reallocating memory\n");
            return -1;
        }
        arr->data = (int*)reallOK;
    }

    // Shift the array by moving the memory starting from the end
    for (int i = arr->size; i > 0; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = item;
    arr->size++;
    return arr->data[0];
}

static char* _to_string(ArrayList* arr) {
    return list_to_string(arr->data, arr->size);
}