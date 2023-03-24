/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-arthur.gauffre
** File description:
** all_space_or_tab
*/

int all_space_or_tab(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            return 1;
    }
    return 0;
}
