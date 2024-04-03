/*
** EPITECH PROJECT, 2024
** gameoflife
** File description:
** error_handling.c
*/

#include <stdio.h>
#include "gameoflife.h"
#include "my_strlen.h"

static int check_character_map(char const *const *arr, size_t const *i)
{
    for (size_t j = 0; arr[*i][j] != '\0'; j += 1) {
        if (arr[*i][j] != '.' && arr[*i][j] != 'X')
            return ERROR;
    }
    return SUCCESS;
}

static int check_string_map(char const *const *arr)
{
    if (arr == NULL)
        return ERROR;
    for (size_t i = 0; arr[i] != NULL; i += 1)
        if (check_character_map(arr, &i) == ERROR)
            return ERROR;
    return SUCCESS;
}

static int check_line_size(char const *const *arr, int const len)
{
    if (arr == NULL)
        return ERROR;
    for (size_t i = 0; arr[i] != NULL; i += 1) {
        if (my_strlen(arr[i]) != len) {
            return ERROR;
        }
    }
    return SUCCESS;
}

int handle_errors(char const *const *arr)
{
    size_t len = 0;

    if (arr == NULL || arr[0] == NULL)
        return ERROR;
    if (check_string_map(arr) == ERROR)
        return ERROR;
    len = my_strlen(arr[0]);
    if (check_line_size(arr, len) == ERROR)
        return ERROR;
    return SUCCESS;
}
