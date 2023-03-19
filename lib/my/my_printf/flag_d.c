/*
** EPITECH PROJECT, 2022
** flag_d
** File description:
** flag_d
*/

#include <stdarg.h>
#include "my.h"

int function_d(const char *format, int count, va_list list, int precision)
{
    int nb = va_arg(list, int);
    int div = 10;
    int nb_digits = 1;
    if (precision == 0 && nb == 0) {
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb / div > 0) {
        nb_digits += 1;
        div = div * 10;
    }
    precision = precision - nb_digits;
    while (precision > 0) {
        my_putchar('0');
        precision -= 1;
    }
    my_put_nbr(nb);
}
