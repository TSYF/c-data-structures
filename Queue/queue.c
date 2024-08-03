#include <stdio.h>
#include "Queue.h"

int main(void) {
    Queue queue = create_queue();
    
    queue.enqueue(&queue, 1);
    printf("%d\n", queue.peek(&queue));
    queue.enqueue(&queue, 2);
    printf("%d\n", queue.peek(&queue));
    queue.enqueue(&queue, 3);
    printf("%d\n", queue.peek(&queue));
    queue.enqueue(&queue, 4);
    printf("%d\n", queue.peek(&queue));
    queue.enqueue(&queue, 5);

    printf("1: %d\n", queue.enqueue(&queue, 100));
    printf("2: %s\n", queue.to_string(&queue));
    printf("3: %d\n", queue.contains(&queue, 100));

    printf("1: %d\n", queue.enqueue(&queue, 6));
    printf("2: %s\n", queue.to_string(&queue));
    printf("3: %d\n", queue.contains(&queue, 100));
    
    printf("1: %d\n", queue.dequeue(&queue));
    printf("2: %s\n", queue.to_string(&queue));
    
    printf("1: %d\n", queue.dequeue(&queue));
    printf("2: %s\n", queue.to_string(&queue));
    
    printf("1: %d\n", queue.enqueue(&queue, 100));
    printf("2: %s\n", queue.to_string(&queue));
    printf("3: %d\n", queue.peek(&queue)); 
    
    free(queue.data);
    return 0;
}