#include <stdlib.h>
#include <string.h>
#include "hash.h"

Hash* new_hash()
{
    Hash* hash;
    hash = malloc(sizeof(Hash));
    hash->key = malloc(sizeof(char));
    hash->value = malloc(sizeof(char));
    hash->previous = NULL;
    hash->next = NULL;
    return hash;
}

void hash_set(Hash* hash, char* key, char* value)
{
    Hash* item;
    for (item = hash; item != NULL; item = item->next)
    {
        if (strcmp(item->key, key) == 0)
        {
            strcpy(item->value, value);
            return;
        }
        if (item->next == NULL)
        {
            Hash* last;
            last = item;
            item = malloc(sizeof(Hash));
            item->key = malloc(sizeof(char));
            item->value = malloc(sizeof(char));
            strcpy(item->key, key);
            strcpy(item->value, value);
            last->next = item;
            item->previous = last;
            item->next = NULL;
            return;
        }
    }
}

char* hash_get(Hash* hash, char* key)
{
    Hash* item;
    for (item = hash; item != NULL; item = item->next)
        if (strcmp(item->key, key) == 0)
            return item->value;
    return "";
}
