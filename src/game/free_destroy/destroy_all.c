/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy
*/

#include "my.h"

int destroy_all(game_t *game)
{
    if (!game)
        return 84;
    free_map(game);
}