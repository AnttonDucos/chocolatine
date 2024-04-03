#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "gameoflife.h"

static void setup()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(gameoflife, null_av)
{
    const char **av = NULL;
    cr_assert_eq((gameoflife(3, av)), 84);
}

Test(gameoflife, invalid_nbr_arg)
{
    const char *av[] = {(char []) {"test"}, (char []) {"test"}, (char []) {"test"}};
    cr_assert_eq((gameoflife(4, av)), 84);
}

Test(gameoflife, null_string_two)
{
    const char *av[] = {(char []) {"test"}, NULL, (char []) {"test"}};
    cr_assert_eq((gameoflife(3, av)), 84);
}

Test(gameoflife, null_strinf_three)
{
    const char *av[] = {(char []) {"test"}, (char []) {"test"}, NULL};
    cr_assert_eq((gameoflife(3, av)), 84);
}

Test(gameoflife, invalid_pass)
{
    const char *av[] = {(char []) {"test"}, (char []) {"test"}, (char []) {"test"}};
    cr_assert_eq((gameoflife(3, av)), 84);
}

Test(gameoflife, invalid_map_size)
{
    const char *av[] = {(char []) {"test"}, (char []) {"tests/size.txt"}, (char []) {"1"}};
    cr_assert_eq((gameoflife(3, av)), 84);
}

Test(gameoflife, invalid_map_char)
{
    const char *av[] = {(char []) {"test"}, (char []) {"tests/char.txt"}, (char []) {"1"}};
    cr_assert_eq((gameoflife(3, av)), 84);
}

Test(gameoflife, invalid_time)
{
    const char *av[] = {(char []) {"test"}, (char []) {"tests/map.txt"}, (char[]) {"test"}};
    cr_assert_eq((gameoflife(3, av)), 84);
}

Test(gameoflife, valid_map_1/*, .init = setup*/)
{
    const char *av[] = {(char []) {"test"}, (char []) {"tests/map.txt"}, (char[]) {"2"}};
    cr_assert_eq((gameoflife(3, av)), 0);
    //cr_assert_stdout_eq_str("......\n..XX..\n..XX..\n......\n");
}
