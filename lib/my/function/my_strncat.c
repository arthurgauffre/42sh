/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** return n char
*/

int my_strlen(char const *str);

char *my_strncat(char *dest ,char const *src ,int nb)
{
    int count;
    int count2;

    count = 0;
    count2 = 0;
    while (dest[count] != '\0') {
        count += 1;
    }
    while (src[count2] != '\0' && count2 < nb) {
        dest[count] = src[count2];
        count += 1;
        count2 += 1;
    }
    return (dest);
}
