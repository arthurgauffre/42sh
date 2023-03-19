/*
** EPITECH PROJECT, 2022
** flag_u
** File description:
** flag_u
*/

#include <stdarg.h>
#include "my.h"

unsigned int pfunction_u(int precision, unsigned int nbr)
{
    int nbr_digit = 0;
    int nbr_0 = 0;
    unsigned int nbr_tpm = nbr;

    nbr_digit = count_digit(nbr_tpm);

    nbr_0 = precision - nbr_digit;

    if (nbr_digit > 0) {
        for (int i = 0; i != nbr_0; i++) {
            my_putchar('0');
        }
    }
    return (nbr);
}

int display_number(char const *format, va_list list, unsigned int nbr,
int precision)
{
    if (precision > 0) {
        pfunction_u(precision, nbr);
        precision = 0;
    }

    if (nbr < 10) {
        my_putchar(nbr + 48);
    } else {
        display_number(format, list, nbr / 10, 0);
        my_putchar(nbr % 10 + 48);
    }
    return (0);
}

int function_u(char const *format, int count, va_list list, int precision)
{
    int nbr = va_arg(list, int);
    unsigned int tpm_nbr = (int)nbr;
    unsigned int negative_value = 4294967295;

    if (nbr < 0) {
        negative_value = (negative_value + nbr) + 1;
        if (precision > 0) {
            pfunction_u(precision, negative_value);
            precision = 0;
        }
        display_number(format, list, negative_value, precision);
        return (0);
    }
    display_number(format, list, tpm_nbr, precision);
    return (0);
}
