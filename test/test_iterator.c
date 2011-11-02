#include <CUnit/CUnit.h>
#include <string.h>
#include "test_iterator.h"
#include "../src/iterator.h"

int test_iterator_setup(void)
{
    return 0;
}

void test_iterator_next(void)
{
    char text[] = "First line.\r\nSecond line.";
    char* line;
    int i;
    i = 0;
    line = iterator_next(text, &i, "\r\n");
    CU_ASSERT(strcmp(line, "First line.") == 0);
    line = iterator_next(text, &i, "\r\n");
    CU_ASSERT(strcmp(line, "Second line.") == 0);
}

void test_iterator_next_line(void)
{
    char text[] = "First line.\r\nSecond line.";
    char* line;
    int i;
    i = 0;
    line = iterator_next_line(text, &i);
    CU_ASSERT(strcmp(line, "First line.") == 0);
    line = iterator_next_line(text, &i);
    CU_ASSERT(strcmp(line, "Second line.") == 0);
}

void test_iterator_next_word(void)
{
    char text[] = "Two words.";
    char* word;
    int i;
    i = 0;
    word = iterator_next_word(text, &i);
    CU_ASSERT(strcmp(word, "Two") == 0);
    word = iterator_next_word(text, &i);
    CU_ASSERT(strcmp(word, "words.") == 0);
}

int test_iterator_teardown(void)
{
    return 0;
}
