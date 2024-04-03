/*
** EPITECH PROJECT, 2024
** life_or_death
** File description:
** algo doing iteration of time
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameoflife.h"

static
int check_bot_botright_right(char **map, int const i, int const j)
{
    int count = 0;

    if (map[i + 1] != NULL) {
        if (map[i + 1][j] == 'X') {
            count += 1;
        }
        if (map[i + 1][j + 1] == 'X') {
            count += 1;
        }
    }
    if (map[i][j + 1] == 'X') {
        count += 1;
    }
    return (count);
}

static
int check_top_topright(char **map, int const i, int const j)
{
    int count = 0;

    if (i > 0) {
        if (map[i - 1][j] == 'X') {
            count += 1;
        }
        if (map[i - 1][j + 1] == 'X') {
            count += 1;
        }
    }
    return (count);
}

static
int check_left_botleft(char **map, int const i, int const j)
{
    int count = 0;

    if (j > 0) {
        if (map[i][j - 1] == 'X') {
            count += 1;
        }
    }
    if (j > 0 && map[i + 1] != NULL) {
        if (map[i + 1][j - 1] == 'X') {
            count += 1;
        }
    }
    return (count);
}

static
int check_top_left(char **map, int const i, int const j)
{
    if (i > 0 && j > 0) {
        if (map[i - 1][j - 1] == 'X') {
            return (1);
        }
    }
    return (0);
}

static
void check_around(char **map, char **new_map, int const i, int const j)
{
    int count = 0;

    count += check_top_left(map, i, j);
    count += check_left_botleft(map, i, j);
    count += check_top_topright(map, i, j);
    count += check_bot_botright_right(map, i, j);
    if (map[i][j] == '.') {
        if (count == 3) {
            new_map[i][j] = 'X';
        } else {
            new_map[i][j] = '.';
        }
    }
    if (map[i][j] == 'X') {
        if (count == 2 || count == 3) {
            new_map[i][j] = 'X';
        } else {
            new_map[i][j] = '.';
        }
    }
}

static
char **evolution(char **map, const int line)
{
    char **new_map = malloc(sizeof(char *) * (line + 1));

    if (!new_map)
        return (NULL);
    new_map[line] = NULL;
    for (int i = 0; i < line; i ++) {
        new_map[i] = strdup(map[i]);
        if (!new_map[i])
            return (NULL);
    }
    for (int i = 0; map[i] != NULL; i ++) {
        for (int j = 0; map[i][j] != '\0'; j ++) {
            check_around(map, new_map, i, j);
        }
    }
    for (int i = 0; i < line; i ++) {
        free(map[i]);
    }
    free(map);
    return (new_map);
}

int life_or_death(char **map, int time)
{
    int line = 0;

    if (!map || time < 0)
        return (ERROR);
    for (; map[line] != NULL; line ++) {
        if (!map[line])
            return (ERROR);
    }
    for (int i = 0; i < time; i ++) {
        map = evolution(map, line);
    }
    for (int i = 0; i < line; i ++) {
        if (printf("%s\n", map[i]) < 0) {
            return (ERROR);
        }
        free(map[i]);
    }
    free(map);
    return (SUCCESS);
}
