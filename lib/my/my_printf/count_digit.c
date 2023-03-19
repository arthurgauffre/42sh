/*
** EPITECH PROJECT, 2022
** count_digit
** File description:
** count_digit
*/

int count_digit(unsigned int nbr_tpm)
{
    int nbr_digit = 0;

    while (nbr_tpm >= 10) {
        nbr_digit = nbr_digit + 1;
        nbr_tpm = nbr_tpm / 10;
    }
    nbr_digit = nbr_digit + 1;
    return (nbr_digit);
}
