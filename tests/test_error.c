/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** test_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <error.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_error, get_empty_error)
{
    cr_assert_str_eq(get_error(), "");
}

Test(set_error, null_message)
{
    set_error(NULL);

    cr_assert_str_eq(get_error(), "");
}

Test(set_error, empty_message)
{
    set_error("");

    cr_assert_str_eq(get_error(), "");
}

Test(set_error, override_message)
{
    set_error("absdfjhuqpsdfg");
    set_error("");

    cr_assert_str_eq(get_error(), "");
}

Test(set_error, regular_message)
{
    set_error("this is an error");

    cr_assert_str_eq(get_error(), "this is an error");
}

Test(epinet_perror, without_error, .init = redirect_all_stdout)
{
    epinet_perror("test");

    cr_assert_stderr_eq_str("test\n");
}

Test(epinet_perror, without_message_nor_error, .init = redirect_all_stdout)
{
    epinet_perror("");

    cr_assert_stderr_eq_str("\n");
}

Test(epinet_perror, with_message_and_error, .init = redirect_all_stdout)
{
    set_error("error");
    epinet_perror("message");

    cr_assert_stderr_eq_str("message: error\n");
}
