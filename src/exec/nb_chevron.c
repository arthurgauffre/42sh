/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** nb_chevron
*/

int nb_chevron_right(char *str)
{
    int nb_chevron = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '>')
            nb_chevron++;
    }
    return nb_chevron;
}

int nb_chevron_left(char *str)
{
    int nb_chevron = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<')
            nb_chevron++;
    }
    return nb_chevron;
}
