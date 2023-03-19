/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** return rev str
*/

int len(char const *str)
{
    int taille;

    taille = 0;
    while (str[taille] != '\0') {
        taille += 1;
    }
    return (taille);
}

char *my_revstr(char *str)
{
    int first;
    int last;
    char bcp;

    first = 0;
    last = len(str) - 1;
    while (first <= last) {
        bcp = str[first];
        str[first] = str[last];
        str[last] = bcp;
        first += 1;
        last -= 1;
    }
    return (str);
}
