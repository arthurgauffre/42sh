/*
** EPITECH PROJECT, 2022
** flag_f
** File description:
** flag_f
*/

#include <stdarg.h>
#include "my.h"

static double arround(double nb, int precision)
{
    double arr = 5;
    if (nb < 0) {
        arr = -arr;
    }
    while (precision >= 0) {
        arr = arr / 10;
        precision = precision - 1;
    }
    nb = nb + arr;
    return nb;
}

static int my_put_float(long int nb)
{
    if (nb < 10) {
        my_putchar(nb + 48);
        return 0;
    }
    my_put_float(nb / 10);
    my_putchar((nb % 10) + 48);
}

static int display_dec(int nb2, double nb, int precision)
{
    while (precision > 0) {
        nb = nb * 10;
        my_put_float(nb);
        nb2 = nb / 1;
        nb = nb - nb2;
        nb2 = 0;
        precision = precision - 1;
    }
}

int function_f(const char *format, int count, va_list list, int precision)
{
    double nb = va_arg(list, double);
    if (precision < 0) {
        precision = 6;
    }
    nb = arround(nb, precision);
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    my_put_float(nb / 1);
    long int nb2 = nb / 1;
    if (precision > 0) {
        my_putchar('.');
    }
    nb = nb - nb2;
    nb2 = 0;
    display_dec(nb2, nb, precision);
}
