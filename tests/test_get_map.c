/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** test_check_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macro_errors.h"
int **get_map(const char *path, const char *str);

Test(get_map_1, good_map){
  int **map = get_map("tests/test_good_map_1", "0123");

  cr_assert_eq(map[0][0], 1);
  cr_assert_eq(map[0][1], 2);
  cr_assert_eq(map[0][2], 3);
}

Test(get_map_2, good_map_1){
  int **map = get_map("tests/test_good_map_2", "0123");

  cr_assert_eq(map[0][0], 3);
  cr_assert_eq(map[0][1], 2);
  cr_assert_eq(map[0][2], 1);
}

Test(get_map_3, good_map){
  int **map = get_map("tests/test_good_map_3", "0123");

  cr_assert_eq(map[0][0], 3);
  cr_assert_eq(map[0][1], 0);
  cr_assert_eq(map[0][2], 2);
}

Test(get_map_4, good_map){
  int **map = get_map("tests/test_good_map_4", "0123");

  cr_assert_eq(map[0][0], 0);
  cr_assert_eq(map[0][1], 0);
  cr_assert_eq(map[0][2], 0);
  cr_assert_eq(map[1][0], 0);
  cr_assert_eq(map[1][1], 0);
  cr_assert_eq(map[1][2], 0);
  cr_assert_eq(map[2][0], 0);
  cr_assert_eq(map[2][1], 0);
  cr_assert_eq(map[2][2], 0);
}

Test(get_map_5, good_map){
  int **map = get_map("tests/test_not_good_map", "0123");

  cr_assert_eq(map, NULL);
}
