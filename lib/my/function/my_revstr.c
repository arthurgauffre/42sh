/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** return rev str
*/

#include <unistd.h>
#include "my.h"

char *my_revstr(char *str)
{
    int first = 0;
    int last = 0;
    char bcp;

    if (str == NULL)
        return NULL;
    if ((last = my_strlen(str) - 1) == - 2)
        return NULL;
    while (first <= last) {
        bcp = str[first];
        str[first] = str[last];
        str[last] = bcp;
        first += 1;
        last -= 1;
    }
    return str;
}
