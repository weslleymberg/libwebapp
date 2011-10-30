#include <CUnit/CUnit.h>
#include <string.h>
#include "test_hash.h"
#include "../src/hash.h"

int test_hash_setup(void)
{
    return 0;
}

void test_hash_create_item(void)
{
    Hash* hash;
    hash = new_hash();
    hash_set(hash, "key 1", "value");
    CU_ASSERT(strcmp(hash->next->key, "key 1") == 0);
    CU_ASSERT(strcmp(hash->next->value, "value") == 0);
    hash_set(hash, "key 2", "value");
    CU_ASSERT(strcmp(hash->next->key, "key 1") == 0);
    CU_ASSERT(strcmp(hash->next->next->key, "key 2") == 0);
}

void test_hash_set_item(void)
{
    Hash* hash;
    hash = new_hash();
    hash_set(hash, "key", "value 1");
    CU_ASSERT(strcmp(hash->next->value, "value 1") == 0);
    hash_set(hash, "key", "value 2");
    CU_ASSERT(strcmp(hash->next->value, "value 2") == 0);
}

void test_hash_get_value(void)
{
    Hash* hash;
    char* value;
    hash = new_hash();
    hash_set(hash, "key", "value");
    value = hash_get(hash, "key");
    CU_ASSERT(strcmp(value, "value") == 0);
}

int test_hash_teardown(void)
{
    return 0;
}
