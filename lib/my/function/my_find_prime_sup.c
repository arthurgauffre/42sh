/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** return prime nb
*/

int my_is_prime(int nb);

int prime_nb(int nb)
{
    for (int k = nb; k > nb - 1; k++) {
        if (my_is_prime(k) == 1){
            return (k);
        }
    }
}

int my_find_prime_sup(int nb)
{
    int result;
    if (nb < 2) {
        return (2);
    }
    if (my_is_prime(nb) == 0) {
        return (prime_nb(nb));
    }
    return (nb);
}
