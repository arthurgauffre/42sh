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
    return write(2, str, my_strlen(str));
}
