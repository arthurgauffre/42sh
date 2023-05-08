/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** display str
*/

#include <unistd.h>
#include "my.h"

int my_puterror(char const *str)
{
    int size = 0;
    if (str == NULL)
        return -1;
    size = my_strlen(str);
    if (size == -1)
        return -1;
    return write(2, str, size);
}
