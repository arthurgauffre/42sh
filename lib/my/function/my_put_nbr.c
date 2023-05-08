/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** display nb (int not char)
*/

#include "my.h"

static int print_negative(int nb)
{
    if (nb == -2147483648) {
        if (my_putchar('-') == -1)
            return -1;
        if (my_putchar('2') == -1)
            return -1;
        nb = (nb % 2000000000) * -1;
    } else {
        if (my_putchar('-') == -1)
            return -1;
        nb = -nb;
    }
    return nb;
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        if ((nb = print_negative(nb)) == -1)
            return -1;
    }
    if (nb < 10) {
        if (my_putchar(nb + 48) == -1)
            return -1;
        return 0;
    }
    if (my_put_nbr(nb / 10) == -1)
        return -1;
    if (my_putchar((nb % 10) + 48) == -1)
        return -1;
}
