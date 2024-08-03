#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Tree_int* tree = newTree();
    tree->insert(tree, 1);
    tree->insert(tree, 3);
    tree->insert(tree, 2);
    tree->insert(tree, 6);
    tree->insert(tree, 4);
    tree->insert(tree, 5);
    tree->insert(tree, 7);
    tree->insert(tree, 8);
    tree->insert(tree, 10);
    tree->insert(tree, 9);

    tree->print(tree);

    destroyTree(tree);
}