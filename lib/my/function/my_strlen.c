/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** len str
*/

int my_strlen(char const *str)
{
    int taille;

    taille = 0;
    while (str[taille] != '\0') {
        taille += 1;
    }
    return (taille);
}
