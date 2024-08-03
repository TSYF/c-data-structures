#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

char* list_to_string(int list[], int length) {
    int strlength = length * 3 + 5;
    char* string = malloc(sizeof(char) * strlength);

    sprintf(string, "%s%s", string, "[ ");
    sprintf(string, "%s%d", string, list[0]);
    for (int i = 1; i < length; i++) {
        sprintf(string, "%s, %d", string, list[i]);
    }
    sprintf(string, "%s%s", string, " ]");

    return string;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node_int* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct Node_int* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}