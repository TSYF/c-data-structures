#include "LinkedList.h"
#include <stdio.h>

int main() {
    
    LinkedList_int list = *linked_list_int_constructor();
    for (int i = 0; i < 12; i++) {
        list.push(&list, i + 1); 
    }

    printf("%s\n", list.to_string(&list));
    list.remove(&list, 5);
    printf("%s\n", list.to_string(&list));
    list.remove(&list, 7);
    printf("%s\n", list.to_string(&list));
    list.insert(&list, 1, 99);
    printf("%s\n", list.to_string(&list));
    
    printf("%d\n", list.retrieve(&list, 10)); 
}