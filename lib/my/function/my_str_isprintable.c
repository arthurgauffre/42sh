/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** return int
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            return 0;
        }
    }
    return 1;
}
