/*
** EPITECH PROJECT, 2022
** flag_E
** File description:
** flag_E
*/

#include <stdarg.h>
#include "my.h"

static int my_put_float(long int nb)
{
    if (nb < 10) {
        my_putchar(nb + 48);
        return 0;
    }
}

static int display_e(int power)
{
    my_putchar('E');
    if (power >= 0) {
        my_putchar('+');
        if (power < 10) {
            my_putchar('0');
            my_put_float(power);
        }
    } else {
        my_putchar('-');
        power = power * -1;
        if (power < 10) {
            my_putchar('0');
            my_put_float(power);
        }
    }
}

static int display_double(double nb, int nb2, int precision)
{
    my_put_float(nb / 1);
    if (precision > 0) {
        my_putchar('.');
    }
    nb = nb - nb2;
    nb2 = 0;
    while (precision > 0) {
        nb = nb * 10;
        my_put_float(nb);
        nb2 = nb / 1;
        nb = nb - nb2;
        nb2 = 0;
        precision = precision - 1;
    }
}

static int function_ebis(int precisionbis, double arr, double nb, int power)
{
    int precision = precisionbis;
    while (precisionbis >= 0) {
        arr = arr / 10;
        precisionbis = precisionbis - 1;
    }
    nb = nb + arr;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    for (power; nb > 10; power++) {
        nb = nb / 10;
    }
    long int nb2 = nb / 1;
    display_double(nb, nb2, precision);
    display_e(power);
}

int function_e_maj(char const *format, int count, va_list list, int precision)
{
    double nb = va_arg(list, double);
    int power = 0;
    if (precision < 0) {
        precision = 6;
    }
    int precisionbis = precision;
    for (power; nb > 10; power++) {
        nb = nb / 10;
    }
    while (nb < 1 && nb > 0) {
        nb = nb * 10;
        power = power - 1;
    }
    double arr = 5;
    if (nb < 0) {
        arr = -arr;
    }
    function_ebis(precisionbis, arr, nb, power);
}
