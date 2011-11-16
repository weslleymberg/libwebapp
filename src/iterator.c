#include <stdlib.h>
#include <string.h>
#include "iterator.h"

char* iterator_next(char* text, int* i, char* separator)
{
    char* part;
    int begin;
    int separator_lenght;
    separator_lenght = strlen(separator);
    begin = *i;
    if (text[*i] == '\0')
        return NULL;
    while (strncmp(text + *i, separator, separator_lenght) != 0 && text[*i] != '\0')
        (*i)++;
    part = malloc(*i - begin);
    strncpy(part, text + begin, *i - begin);
    *i = *i + separator_lenght;
    return part;
}

char* iterator_next_line(char* text, int* i)
{
    return iterator_next(text, i, "\r\n");
}

char* iterator_next_word(char* text, int* i)
{
    return iterator_next(text, i, " ");
}
