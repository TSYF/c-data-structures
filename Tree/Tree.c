#include "Tree.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

Node_int* _find(const Tree_int* tree, const int data);
Node_int* _insert(Tree_int* tree, const int data);
void _print(const Tree_int* tree);
// char* _toString(const Tree_int* tree);

Tree_int* newTree() {
    Tree_int* tree = malloc(sizeof(Tree_int));
    tree->root = NULL;
    tree->find = _find;
    tree->insert = _insert;
    tree->print = _print;
    // tree->toString = _toString;
    return tree;
}

void destroyTree(Tree_int* tree) {
    free(tree);
}

Node_int* _find(const Tree_int* tree, const int data) {
    for (
        Node_int* node = tree->root;
        node != NULL;
        node = node->right
    ) {
        if (node->data == data) {
            return node;
        }
    }
    return NULL;
}

Node_int* _insert(Tree_int* tree, const int data) {
    Node_int* node = newNode(data);
    if (tree->root == NULL) {
        tree->root = node;
        return node;
    }

    Node_int* parent = tree->root;
    while (parent != NULL) {
        if (parent->data > data) {
            if (parent->left == NULL) {
                parent->left = node;
                return node;
            }
            parent = parent->left;
        } else {
            if (parent->right == NULL) {
                parent->right = node;
                return node;
            }
            parent = parent->right;
        }
    }
}

void _print(const Tree_int* tree) {
    print2D(tree->root);
}