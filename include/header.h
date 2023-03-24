/*
** EPITECH PROJECT, 2023
** header
** File description:
** header of the program
*/

#include <signal.h>
#include <stdbool.h>


#ifndef HEADER
    #define HEADER
    #define OK 0
    #define KO 84

    int all_space_or_tab(char *str);
    void free_tab(char **tab);
    int my_tablen(char **tab);
    void prompt(void);
    int is_echo(void);
    int mysh(char **my_env);
    int start_shell(char ***env);
    char **my_envcpy(char **env);
    char *read_terminal(void);
    char *my_str_cut(char *str, int nb, int start_or_end);
    char *replace_tab_with_space(char *str);
    int check_and_launch_command(char *parser, char ***env);
    int check_and_launch_mybuiltins(char **tab, char ***env);
    int check_and_launch_binary(char **tab, char **env, char *parser);
    char **modif_var_env(char **env, char *var_env, char *new_var_env_value);
    char *get_new_var_env_value(char *old_var_env, char *var_env,
    char *new_var_env_value);
    int cd_builtin(char **tab, char **env);
    int unsetenv_builtin(char **tab, char ***env);
    int add_var_env_with_value(char **tab, char ***env);
    int add_var_env_with_no_value(char **tab, char ***env);
    int env_builtin(char **tab, char **env);
    int my_str_isalphanum(char const *str);
    char *get_inside_var_env(char **env, char *var_env);
    char *get_pwd(void);

#endif /* !HEADER */
