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

    typedef struct sh_data_s {
        char **tab_parser;
        char ***env;
        char **tab_pipe;
        int **pipes;
        char *old_parser;
        int nb_pipes;
        int nb_actual_command;
    } sh_data_t;

    void pipes_connexion(sh_data_t sh_data);
    int all_space_or_tab(char *str);
    void free_tab(char **tab);
    void free_int_tab(int **tab);
    int my_tablen(char **tab);
    void prompt(void);
    int is_echo(void);
    int mysh(char **my_env);
    int start_shell(char ***env);
    char **my_envcpy(char **env);
    char *read_terminal(void);
    void free_child_env(char **tab_command, sh_data_t sh_data, char **tab);
    char *my_str_cut(char *str, int nb, int start_or_end);
    char *replace_tab_with_space(char *str);
    int check_and_launch_command(char **tab_command, char *parser, char ***env,
    char *old_parser);
    int check_and_launch_mybuiltins(char **tab_command, sh_data_t sh_data);
    int check_and_launch_binary(char **tab_command, sh_data_t sh_data,
    char **tab);
    char **modif_var_env(char **env, char *var_env, char *new_var_env_value);
    char *get_new_var_env_value(char *old_var_env, char *var_env,
    char *new_var_env_value);
    int cd_builtin(char **tab, char **env);
    int unsetenv_builtin(char **tab, char ***env);
    int add_var_env_with_value(char **tab, char ***env);
    int add_var_env_with_no_value(char **tab, char ***env);
    int my_str_isalphanum(char const *str);
    char *get_inside_var_env(char **env, char *var_env);
    char *get_pwd(void);

#endif /* !HEADER */
