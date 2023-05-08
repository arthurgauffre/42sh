/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** return str
*/

#include <unistd.h>
#include "my.h"

static int my_isalpha(char ch)
{
    if ((ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z') &&
    (ch < '0' || ch > '9'))
        return 0;
    return 1;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    if (str == NULL)
        return NULL;
    if ((str = my_strlowcase(str)) == NULL)
        return NULL;
    if (my_isalpha(str[i]) == 1)
        str[i] = (str[i] - 32);
    i += 1;
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') && my_isalpha(str[i - 1]) == 0) {
            str[i] = (str[i] - 32);
            i += 1;
        } else
            i += 1;
    }
    return str;
}
