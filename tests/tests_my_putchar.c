/*
** EPITECH PROJECT, 2019
** test_my_putchar.c
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_putchar, simple)
{
    cr_redirect_stdout();
    my_putchar('t');
    cr_expect_stdout_eq_str("t");
}

Test(my_putchar, return_null)
{
    cr_redirect_stdout();
    cr_assert_eq(my_putchar(1), NULL);
}