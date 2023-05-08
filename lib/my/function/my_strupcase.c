/*
** EPITECH PROJECT, 2022
** strupcase
** File description:
** return str
*/

#include <unistd.h>

char *my_strupcase(char *str)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 32);
    }
    return str;
}
