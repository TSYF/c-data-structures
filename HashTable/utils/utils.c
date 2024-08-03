#include "utils.h"

char* table_to_string(HashTable* hashTable) {
    int strlength = hashTable->size * 3 + 5;
    char* string = malloc(sizeof(char) * strlength);

    sprintf(string, "%s%s", string, "{ ");
    for (int i = 0; i < hashTable->size; i++) {
        if (hashTable->data[i] != NULL) {
            sprintf(string, "%s%s: %s", string, hashTable->data[i], hashTable->data[i]);
        }
    }
    sprintf(string, "%s%s", string, " }");

    return string;
}