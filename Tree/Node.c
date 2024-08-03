#include "Node.h"
#include <stdlib.h>

Node_int* newNode(const int data) {
    Node_int* node = malloc(sizeof(Node_int));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destroyNode(Node_int* node) {
    free(node);
}