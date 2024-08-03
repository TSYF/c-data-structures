#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include "Node.h"

typedef struct LinkedList_int {
    Node_int* head;
    int length;

    void (*push)(struct LinkedList_int* list, int data);
    void (*insert)(struct LinkedList_int* list, int index,int data);
    void (*remove)(struct LinkedList_int* list, int index);
    int (*retrieve)(struct LinkedList_int* list, int index);
    char* (*to_string)(struct LinkedList_int* list);
} LinkedList_int;

LinkedList_int* linked_list_int_constructor();

/* 
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

LinkedList *createLinkedList();
void insertAtHead(LinkedList *list, int data);
void insertAtTail(LinkedList *list, int data);
void insertAtIndex(LinkedList *list, int index, int data);
void removeAtIndex(LinkedList *list, int index);
void removeFromHead(LinkedList *list);
void removeFromTail(LinkedList *list);
int getAtIndex(LinkedList *list, int index);
void printList(LinkedList *list);
void freeLinkedList(LinkedList *list);
 */
#endif // LINKEDLIST_H