/*
** EPITECH PROJECT, 2024
** gameoflife
** File description:
** gameoflife.c
*/

#include "gameoflife.h"
#include "handle_error.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

static void free_arr(char ***arr)
{
    if (*arr != NULL) {
        for (size_t i = 0; (*arr)[i] != NULL; i += 1)
            free((*arr)[i]);
        free(*arr);
    }
}

static int check_number(char const *number)
{
    if (number == NULL)
        return ERROR;
    for (size_t i = 0; number[i] != '\0'; i += 1)
        if (number[i] < '0' || number[i] > '9')
            return ERROR;
    return SUCCESS;
}

int gameoflife(int const argc, char const *const *argv)
{
    char **arr = NULL;
    int time = 0;

    if (argc != 3)
        return ERROR;
    if (argv == NULL || argv[1] == NULL || argv[2] == NULL)
        return ERROR;
    arr = parse_map(argv);
    if (handle_errors(arr) == ERROR) {
        free_arr(&arr);
        return ERROR;
    }
    if (check_number(argv[2]) == ERROR) {
        free_arr(&arr);
        return ERROR;
    }
    time = atoi(argv[2]);
    if (life_or_death(arr, time) == ERROR)
        return ERROR;
    return SUCCESS;
}
