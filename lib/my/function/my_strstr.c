/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** return str
*/

#include "my.h"
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2);

char *my_strstr(char *str, char const *to_find)
{
    for (int k = 0; str[k] != '\0'; k++) {
        if (my_strcmp(&str[k], to_find) == 0) {
            return (&str[k]);
        }
    }
    return 0;
}
