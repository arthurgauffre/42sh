/*
** EPITECH PROJECT, 2023
** get_word
** File description:
** get_word
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *get_word(char const *str, int count, char separator)
{
    int str_count = 0;
    int word_size = 0;

    if (str == NULL)
        return NULL;
    if ((word_size = len_word(str, count, separator)) == -1)
        return NULL;
    char *str_tmp = malloc(sizeof(char) *
    (word_size + 1));
    if (str_tmp == NULL)
        return NULL;
    str_tmp[word_size] = '\0';
    while (str[count] != '\0' && str[count] != separator) {
        str_tmp[str_count] = str[count];
        str_count += 1;
        count += 1;
    }
    return str_tmp;
}
