/*
** EPITECH PROJECT, 2023
** header
** File description:
** header of the program
*/

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include "struct.h"

#ifndef HEADER
    #define HEADER
    #define OK 0
    #define KO 84

    sh_data_t *init_pipe_data(sh_data_t *data, char **tab);
    void free_data(sh_data_t sh_data);
    void pipes_connexion(sh_data_t data);
    int loop_and(sh_data_t *data);
    int loop_pipe(sh_data_t *data);
    int all_space_or_tab(char *str);
    void free_tab(char **tab);
    void free_int_tab(int **tab);
    char **split_str_to_tab_with_wtr_separator(char* str, char* separator);
    int my_tablen(char **tab);
    void prompt(char const *prompt_str);
    int is_echo(void);
    int nb_chevron(char *str);
    char *load_fd_in_str(int fd);
    int mysh(char **my_env);
    int start_shell(char ***env);
    char **my_envcpy(char **env);
    void print_prompt(char const *prompt_str);
    char *read_terminal(void);
    char *backslash_check_count(char *parser);
    void free_child_env(char **tab_command, sh_data_t sh_data, char **tab);
    char *my_str_cut(char *str, int nb, int start_or_end);
    char *replace_tab_with_space(char *str);
    int check_and_launch_command(sh_data_t *data);
    int check_and_launch_mybuiltins(sh_data_t *data);
    int check_and_launch_binary(sh_data_t *data);
    char **modif_var_env(char **env, char *var_env, char *new_var_env_value);
    char *get_new_var_env_value(char *old_var_env, char *var_env,
    char *new_var_env_value);
    int cd_builtin(sh_data_t *data);
    int unsetenv_builtin(char **tab, char ***env);
    int add_var_env_with_value(char **tab, char ***env);
    int add_var_env_with_no_value(char **tab, char ***env);
    int my_str_isalphanum(char const *str);
    char *get_inside_var_env(char **env, char *var_env);
    char *get_pwd(void);
    void display_exec_error(int wstatus);
    int display_child_error(char *str);
    void child_connection(sh_data_t sh_data);
    int invalid_null_function(char *parser, int value);
    int is_null_command(char *parser);
    void child_connection(sh_data_t sh_data);
    char *load_file_in_mem(char const *filepath);
    int history(char *input, char *history_path);
    history_t *add_node(history_t *head, history_data_t data);
    void free_list(history_t *head);
    int print_list(history_t *head, char *input, FILE *fd);
    int count_nodes(history_t *head);
    int write_in_file(char *name, char *content);
    char *get_path_history(char *path);
    sh_data_t init_data(char ***env);
    char *add_char(char *command, int c, int *index);
    char *sup_char(char *commande, int *index);
    char *get_command(char *const prompt_char);
    void display_history(char *path_history);
    int check_exit(char *parser);

#endif /* !HEADER */
