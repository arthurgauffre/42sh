/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** return power
*/

int my_compute_power_rec(int nb, int p)
{
    long int result = 0;
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    result = nb * my_compute_power_rec(nb, p - 1);
    if (result > 2147483647)
        return -1;
    return result;
}
