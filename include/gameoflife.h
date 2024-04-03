/*
** EPITECH PROJECT, 2024
** gameoflife
** File description:
** gameoflife.h
*/

#ifndef GAMEOFLIFE_H_
    #define GAMEOFLIFE_H_
    #define SUCCESS 0
    #define ERROR 84

int gameoflife(int const argc, char const *const *argv);
int life_or_death(char **map, int const time);

#endif
