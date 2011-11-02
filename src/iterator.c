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
    while (strncmp(text + *i, separator, separator_lenght) != 0 && text[*i] != '\0')
        (*i)++;
    part = malloc(sizeof(char));
    strncpy(part, text + begin, *i - begin);
    *i = *i + separator_lenght;
    return part;
}
