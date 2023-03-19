/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** task02
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

char *my_strncpy(char *dest, char const *src, int n)
{
    int count;
    int len_src;
    count = 0;
    len_src = my_strlen(src);
    while (src[count] != '\0' && count < n) {
        dest[count] = src[count];
        count += 1;
    }
    if (n > len_src) {
        while (dest[count] != '\0') {
            dest[count] = '\0';
                count += 1;
        }
    }
    return (dest);
}
