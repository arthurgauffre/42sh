/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** return 1 or 0 if is prime
*/

int my_is_prime(int nb)
{
    if (nb < 2) {
        return 0;
    }
    for (int k = 2; k < nb; k++) {
        if (nb % k == 0) {
            return 0;
        }
    }
    return (1);
}
