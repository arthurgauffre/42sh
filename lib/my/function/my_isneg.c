/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** return 'N' or 'P'
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        if (my_putchar('N') == -1)
            return -1;
    } else {
        if (my_putchar('P') == -1)
            return -1;
    }
    return 0;
}
