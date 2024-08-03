#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

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