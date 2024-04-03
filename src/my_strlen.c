/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i += 1);
    return i;
}
