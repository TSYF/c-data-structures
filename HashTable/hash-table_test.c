#include "HashTable.h"
#include <stdio.h>

int main() {
    HashTable* hashTable = newHashTable(10);
    hashTable->set(hashTable, "key1", "value1");
    hashTable->set(hashTable, "key2", "value2");
    hashTable->set(hashTable, "key3", "value3");
    hashTable->set(hashTable, "key4", "value4");
    hashTable->set(hashTable, "key5", "value5");
    hashTable->set(hashTable, "key6", "value6");
    hashTable->set(hashTable, "key7", "value7");
    hashTable->set(hashTable, "key8", "value8");
    hashTable->set(hashTable, "key9", "value9");
    hashTable->set(hashTable, "key10", "value10");

    printf("%s\n", hashTable->toString(hashTable));

    destroyHashTable(hashTable);
}