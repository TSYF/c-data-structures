#include <stdio.h>
#include "ArrayList.h"

int main(void) {
    ArrayList arr = create_array_list();
    
    arr.push(&arr, 1);
    arr.push(&arr, 2);
    arr.push(&arr, 3);
    arr.push(&arr, 4);
    arr.push(&arr, 5);

    printf("%d\n", arr.get(&arr, 0));
    printf("%d\n", arr.get(&arr, 1));
    printf("%d\n", arr.get(&arr, 2));
    printf("%d\n", arr.get(&arr, 3));
    printf("%d\n", arr.get(&arr, 4));
    
    printf("Set: %d\n", arr.set(&arr, 5, 100));
    printf("Full Array: %s\n", arr.to_string(&arr));
    printf("Sixth: %d\n", arr.get(&arr, 5));

    printf("Push: %d\n", arr.push(&arr, 6));
    printf("Full Array: %s\n", arr.to_string(&arr));
    printf("Last: %d\n", arr.get(&arr, -1)); 
    
    printf("Pop: %d\n", arr.pop(&arr));
    printf("Full Array: %s\n", arr.to_string(&arr));
    printf("Last: %d\n", arr.get(&arr, -1)); 
    
    printf("Shift: %d\n", arr.shift(&arr));
    printf("Full Array: %s\n", arr.to_string(&arr));
    printf("first: %d\n", arr.get(&arr, 0));
    
    printf("Unshift: %d\n", arr.unshift(&arr, 100));
    printf("Full Array: %s\n", arr.to_string(&arr));
    printf("First: %d\n", arr.get(&arr, 0)); 
    
    free(arr.data);
    return 0;
}