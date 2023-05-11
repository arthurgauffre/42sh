/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** built_in
*/

#include "header.h"
#ifndef FLAGS_H_
    #define FLAGS_H_

    struct my_flags_t {
        char const* flag;
        int(*tab)(sh_data_t *data);
    };
    typedef struct my_flags_t my_flags;
    const my_flags FUNCTION_TAB[] = {
        {flag : "cd", tab : &cd_builtin},
        {flag : "env", tab : &env_builtin},
        {flag : "setenv", tab : &setenv_builtin},
        {flag : "unsetenv", tab : &unsetenv_builtin},
        {flag : "!", tab : &display_history}
    };
    #define nb_builtin 5
#endif /* FLAGS_H_ */
