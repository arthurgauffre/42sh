/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** test_check_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macro_errors.h"
int sandpile(const char *argv[]);

Test(sandpile, example_subject){
  cr_redirect_stdout();
  const char *argv[] = {"./sandpile", "tests/ex_1", "0123", "2"};

  cr_assert_eq(sandpile(argv), SUCCESS);

  cr_assert_stdout_eq_str("131\n111\n031\n");
}
