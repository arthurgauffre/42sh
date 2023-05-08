/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** return int
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int result;
    int digit;
    for (int k = 1; k <= nb; k++) {
        if (my_compute_power_rec(k, 2) == nb)
            return k;
    }
    return 0;
}
