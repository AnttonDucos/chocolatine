/*
** EPITECH PROJECT, 2024
** my_str_to_word_arr_s.c
** File description:
** my_str_to_word_arr_s
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_strlen.h"

static ssize_t is_not_separator(char c, char const *delim)
{
    size_t len = 0;
    size_t count = 0;

    if (delim == NULL)
        return -1;
    len = my_strlen(delim);
    for (size_t i = 0; delim[i] != '\0'; i += 1) {
        if (c != delim[i] && c != '\0') {
            count += 1;
        }
    }
    if (count == len)
        return 0;
    return 1;
}

static char **alloc_elem_in_arr(char const *str, char const *delim)
{
    char **arr = NULL;
    int count = 0;

    if (str == NULL)
        return NULL;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (is_not_separator(str[i], delim) == 1)
            count += 1;
    arr = malloc(sizeof(char *) * (count + 2));
    if (arr == NULL)
        return NULL;
    for (int i = 0; i <= count + 1; i += 1)
        arr[i] = NULL;
    return arr;
}

static char **create_arr(char const *str, char const *delim)
{
    char **arr = NULL;
    size_t len = 0;
    size_t y = 0;

    arr = alloc_elem_in_arr(str, delim);
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (is_not_separator(str[i], delim) == 0 &&
            is_not_separator(str[i + 1], delim) == 0)
            len += 1;
        if (is_not_separator(str[i], delim) == 0 &&
            is_not_separator(str[i + 1], delim) == 1) {
            len += 1;
            arr[y] = malloc(sizeof(char) * (len + 1));
            arr[y][len] = '\0';
            y += 1;
            len = 0;
        }
    }
    return arr;
}

static
ssize_t assign_str_to_arr(char **arr, char const *str, char const *delim)
{
    size_t a = 0;
    size_t y = 0;

    if (arr == NULL && str == NULL)
        return -1;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (is_not_separator(str[i], delim) == 0 &&
            is_not_separator(str[i + 1], delim) == 0) {
            arr[a][y] = str[i];
            y += 1;
        }
        if (is_not_separator(str[i], delim) == 0 &&
            is_not_separator(str[i + 1], delim) == 1) {
            arr[a][y] = str[i];
            a += 1;
            y = 0;
        }
    }
    return 0;
}

char **my_str_to_word_arr_s(char const *str, char const *delim)
{
    char **arr = NULL;

    if (str == NULL)
        return NULL;
    arr = create_arr(str, delim);
    if (assign_str_to_arr(arr, str, delim) == -1)
        return NULL;
    return arr;
}
