/*
** EPITECH PROJECT, 2024
** gameoflife
** File description:
** parser.c
*/

#include "my_str_to_word_arr_s.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char **parse_map(char const *const *argv)
{
    int fd = 0;
    char **arr = NULL;
    char *buf = NULL;
    struct stat stats = {0};

    if (argv == NULL || argv[1] == NULL)
        return NULL;
    fd = open(argv[1], O_RDONLY);
    if (fd == - 1)
        return NULL;
    stat(argv[1], &stats);
    buf = malloc(sizeof(char) * (stats.st_size + 1));
    if (buf == NULL)
        return NULL;
    if (read(fd, buf, stats.st_size) < 0)
        return NULL;
    buf[stats.st_size] = '\0';
    arr = my_str_to_word_arr_s(buf, "\n");
    free(buf);
    return arr;
}
