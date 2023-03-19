/*
** EPITECH PROJECT, 2022
** flag_x
** File description:
** flag_x
*/

#include <stdarg.h>
#include "my.h"

int pfunction_x(int precision, unsigned int nbr, int nbr_digit, int nbr_0)
{
    while (nbr >= 16) {
        nbr_digit = nbr_digit + 1;
        nbr = nbr / 16;
    }
    nbr_digit = nbr_digit + 1;

    nbr_0 = precision - nbr_digit;

    if (precision <= nbr_digit) {
        return (0);
    }
    return (nbr_0);
}

int my_put_hexa(char const *format, va_list list, unsigned int nbr,
int precision)
{
    char *str = ("0123456789abcdef");
    int nbr_digit = 0;
    int nbr_0 = 0;
    int count = 0;

    if (precision > 0) {
        nbr_0 = pfunction_x(precision, nbr, nbr_digit, nbr_0);
        while (count != nbr_0) {
            my_putchar('0');
            count = count + 1;
        }
        precision = 0;
    }
    if (nbr < 16) {
        my_putchar(str[nbr]);
    } else {
        my_put_hexa(format, list, nbr / 16, 0);
        my_putchar(str[nbr % 16]);
    }
    return (0);
}

int function_x(char const *format, int count, va_list list, int precision)
{
    int nbr = va_arg(list, int);
    unsigned int tpm_nbr = (int)nbr;
    unsigned int negative_value = 4294967295;
    int nbr_digit = 0;

    if (nbr < 0) {
        negative_value = (negative_value + nbr) + 1;
        my_put_hexa(format, list, negative_value, precision);
        return (0);
    }
    my_put_hexa(format, list, tpm_nbr, precision);
    return (0);
}
