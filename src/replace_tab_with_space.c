/*
** EPITECH PROJECT, 2023
** replace_tab
** File description:
** replace_tab
*/

char *replace_tab_with_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return str;
}
