#include "LinkedList.h"
#include <string.h>
#include <stdio.h>

static Node_int* _iterate(LinkedList_int* list, int index); 
static Node_int* _create_node_int(int data); 
static void _destroy_node_int(Node_int* node); 
static void _push_node_int(LinkedList_int* list, int data);
static void _insert_node_int(LinkedList_int* list, int index, int data); 
static void _remove_node_int(LinkedList_int* list, int index);
static int _retrieve_data_int(LinkedList_int* list, int index);
static char* _to_string_int(LinkedList_int* list);

LinkedList_int* linked_list_int_constructor() {
    static LinkedList_int new_list;
    new_list.head = NULL;
    new_list.length = 0;

    new_list.push = _push_node_int;
    new_list.insert = _insert_node_int;
    new_list.remove = _remove_node_int;
    new_list.retrieve = _retrieve_data_int;
    new_list.to_string = _to_string_int;

    return &new_list;
}

static Node_int* _create_node_int(int data) {
    Node_int* new_node;
    new_node = malloc(sizeof(Node_int));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

static void _push_node_int(LinkedList_int* list, int data) {
    Node_int* new_node = _create_node_int(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->length++;
        return;
    }

    Node_int* current_node = list->head;
    list->head = new_node;
    new_node->next = current_node;
    
    list->length++;
}

static Node_int* _iterate(LinkedList_int* list, int index) {
    if (index < 0 || index >= list->length) {
        perror("Index out of bounds");
        exit(9);
    }
    Node_int* current_node = list->head;
    for (int i = 0; i < index; i++) {
        printf("LinkedList.c:41 > _iterate > for loop - Iteration\n");
        current_node = current_node->next;
    }
    return current_node;
}

static void _destroy_node_int(Node_int* node) {
    free(node);
}

static void _insert_node_int(LinkedList_int* list, int index, int data) {
    Node_int* new_node = _create_node_int(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->length++;
        return;
    }
    
    if (index >= list->length) {

        Node_int* current_node = list->head;
        while (current_node->next != NULL) {
            printf("LinkedList.c:61 > _insert_node_int > while loop - Iteration\n");
            current_node = current_node->next;
        }
        current_node->next = new_node;
        list->length++;
        return;
    }

    if (index < 0) {
        perror("Index out of bounds");
        exit(9);
    }

    Node_int* current_node = _iterate(list, index - 1);
    Node_int* index_node = current_node->next;
    current_node->next = new_node;
    new_node->next = index_node;
    list->length++;
}


static int _retrieve_data_int(LinkedList_int* list, int index) {
    Node_int* current_node = _iterate(list, index);
    return current_node->data;
}

static void _remove_node_int(LinkedList_int* list, int index) {
    Node_int* current_node = _iterate(list, index);
    Node_int* previous_node = current_node->next;
    Node_int* next = current_node->next;
    current_node->next = next->next; 
    _destroy_node_int(previous_node);
    list->length--;
}

static char* _to_string_int(LinkedList_int* list) {
    int string_length = sizeof(char) * list->length * 3 + 3;
    char* string = malloc(string_length);
    Node_int* current_node = list->head;
    sprintf(string, "%c%d", '[', current_node->data);

    for (
        current_node = current_node->next;
        current_node != NULL;
        current_node = current_node->next
    ) {
        printf("LinkedList.c:106 > _to_string_int > for loop - Iteration\n");
        sprintf(string, "%s, %d", string, current_node->data);
    }

    sprintf(string, "%s%s", string, "]\0");
    return string;
}