/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** display str
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int size = 0;
    if (str == NULL)
        return -1;
    if ((size = my_strlen(str)) == -1)
        return -1;
    if (write(1, str, size) == -1)
        return -1;
    return size;
}
