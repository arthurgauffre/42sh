/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** display nb (int not char)
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        if (nb == -2147483648) {
            my_putchar('-');
            my_putchar('2');
            nb = (nb % 2000000000) * -1;
        } else {
            my_putchar('-');
            nb = -nb;
        }
    }
    if (nb < 10) {
        my_putchar(nb + 48);
        return 0;
    }
    my_put_nbr(nb / 10);
    my_putchar((nb % 10) + 48);
}
