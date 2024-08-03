#ifndef NODE_H
#define NODE_H

typedef struct Node_int {
    int data;
    struct Node_int* left;
    struct Node_int* right;
} Node_int;

Node_int* newNode(const int data);
void destroyNode(Node_int* node);

#endif