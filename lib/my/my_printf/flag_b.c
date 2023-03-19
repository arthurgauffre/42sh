/*
** EPITECH PROJECT, 2022
** flag_b
** File description:
** flag_b
*/

#include <stdarg.h>
#include "my.h"

int my_put_binary(int nbr)
{
    if (nbr < 2) {
        my_putchar(nbr + 48);
        return 0;
    }
    my_put_binary(nbr / 2);
    my_putchar((nbr % 2) + 48);
    return (0);
}

int function_b(char const *format, int count, va_list list, int precision)
{
    unsigned int nbr = va_arg(list, unsigned int);

    my_put_binary(nbr);
    return (0);
}
