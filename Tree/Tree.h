#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "Node.h"

typedef struct Tree_int {
    Node_int* root;

    Node_int* (*find)(const struct Tree_int* tree, const int data);
    Node_int* (*insert)(struct Tree_int* tree, const int data);
    void (*print)(const struct Tree_int* tree);
    // char* (*toString)(const Tree_int* tree);
} Tree_int;

Tree_int* newTree();
void destroyTree(Tree_int* tree);


#endif