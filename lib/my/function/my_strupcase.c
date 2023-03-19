/*
** EPITECH PROJECT, 2022
** strupcase
** File description:
** return str
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 32);
        }
    }
    return str;
}
