/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(tablen, tablen, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = "Bonjour\0";
    tab[1] = "Salut\0";
    tab[2] = NULL;
    cr_assert_eq(my_tablen(tab), 2);
}

Test(builtins1, no_builtins, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = "Bonjour\0";
    tab[1] = "Salut\0";
    tab[2] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 2);
}

Test(builtins2, cd_builtin_error, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 4);
    tab[0] = "cd\0";
    tab[1] = "Salut\0";
    tab[2] = "Salut\0";
    tab[3] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 1);
}

Test(builtins3, cd_builtin_only, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 2);
    tab[0] = "cd\0";
    tab[1] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 0);
}

Test(builtins4, cd_builtin_dash, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = "cd\0";
    tab[1] = "-\0";
    tab[2] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 0);
}

Test(builtins5, cd_builtin_error_dash, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 4);
    tab[0] = "cd\0";
    tab[1] = "-\0";
    tab[2] = "Salut\0";
    tab[3] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 1);
}

Test(builtins6, cd_builtins_file, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = "cd\0";
    tab[1] = "lib/\0";
    tab[2] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 0);
}

Test(builtins7, cd_builtins_file_invalid, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = "cd\0";
    tab[1] = "zefezff/\0";
    tab[2] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 1);
}

Test(builtins8, env_display, .init = redirect_all_std) {
    char **tab = malloc(sizeof(char *) * 2);
    tab[0] = "setenv\0";
    tab[1] = NULL;
    cr_assert_eq(check_and_launch_mybuiltins(tab, &tab), 0);
}

Test(echo, echo_function, .init = redirect_all_std) {
    cr_assert_eq(is_echo(), 1);
}

Test(str_cut_end, str_cut_function, .init = redirect_all_std) {
    char *str = malloc(sizeof(char) * 5);
    str[0] = 'y';
    str[1] = 'e';
    str[2] = 'e';
    str[3] = 't';
    str[4] = '\0';
    cr_assert_str_eq(my_str_cut(str, 1, 1), "yee\0");
}

Test(str_cut_start, str_cut_function, .init = redirect_all_std) {
    char *str = malloc(sizeof(char) * 5);
    str[0] = 'y';
    str[1] = 'e';
    str[2] = 'e';
    str[3] = 't';
    str[4] = '\0';
    cr_assert_str_eq(my_str_cut(str, 1, 0), "eet\0");
}

Test(str_is_alpha1, str_is_alpha_function, .init = redirect_all_std) {
    char *str = malloc(sizeof(char) * 5);
    str[0] = 'y';
    str[1] = 'e';
    str[2] = 'e';
    str[3] = 't';
    str[4] = '\0';
    cr_assert_eq(my_str_isalphanum(str), 1);
}

Test(str_is_alpha0, str_is_alpha_function, .init = redirect_all_std) {
    char *str = malloc(sizeof(char) * 5);
    str[0] = '-';
    str[1] = '-';
    str[2] = '-';
    str[3] = '-';
    str[4] = '\0';
    cr_assert_eq(my_str_isalphanum(str), 0);
}

Test(replace_tab, replace_tab_function, .init = redirect_all_std) {
    char *str = malloc(sizeof(char) * 5);
    str[0] = '-';
    str[1] = ' ';
    str[2] = '\t';
    str[3] = '-';
    str[4] = '\0';
    cr_assert_str_eq(replace_tab_with_space(str), "-  -\0");
}


