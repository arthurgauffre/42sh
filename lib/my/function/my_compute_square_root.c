/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** return int
*/

int power(int nb, int p);

int power(int nb, int p)
{
    int result;
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    result = nb * power(nb, p - 1);
    if (result > 2147483647) {
        return (0);
    }
    return (result);
}

int my_compute_square_root(int nb)
{
    int result;
    int digit;
    for (int k = 1; k <= nb; k++) {
        if (power(k, 2) == nb) {
            return (k);
        }
    }
    return (0);
}
