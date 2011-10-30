#ifndef __HASH_H__
#define __HASH_H__

typedef struct hash
{
    char* key;
    char* value;
    struct hash* previous;
    struct hash* next;
} Hash;

Hash* new_hash();
void hash_set(Hash*, char*, char*);
char* hash_get(Hash*, char*);

#endif
