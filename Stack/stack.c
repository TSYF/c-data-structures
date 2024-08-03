#include <stdio.h>
#include "Stack.h"

int main(void) {
    Stack stack = create_stack();
    
    stack.push(&stack, 1);
    printf("First: %d\n", stack.peek(&stack));
    stack.push(&stack, 2);
    printf("First: %d\n", stack.peek(&stack));
    stack.push(&stack, 3);
    printf("First: %d\n", stack.peek(&stack));
    stack.push(&stack, 4);
    printf("First: %d\n", stack.peek(&stack));
    stack.push(&stack, 5);

    printf("Pushed: %d\n", stack.push(&stack, 100));
    printf("Full: %s\n", stack.to_string(&stack));
    printf("Contains 100: %d\n", stack.contains(&stack, 100));

    printf("Pushed: %d\n", stack.push(&stack, 6));
    printf("Full: %s\n", stack.to_string(&stack));
    printf("Contains 100: %d\n", stack.contains(&stack, 100));
    
    printf("Popped: %d\n", stack.pop(&stack));
    printf("Full: %s\n", stack.to_string(&stack));
    
    printf("Popped: %d\n", stack.pop(&stack));
    printf("Full: %s\n", stack.to_string(&stack));
    
    printf("Pushed: %d\n", stack.push(&stack, 100));
    printf("Full: %s\n", stack.to_string(&stack));
    printf("First: %d\n", stack.peek(&stack));

    printf("Full: %s\n", stack.to_string(&stack));
    stack.clear(&stack);
    printf("Full: %s\n", stack.to_string(&stack));
    
    
    free(stack.data);
    return 0;
}