/*
** EPITECH PROJECT, 2020
** live
** File description:
** live
*/

#include "my.h"

int live_enemies(game_t *game)
{
    int alive = 50;

    if (!game)
        return 84;
    game->enemies_one->alive = alive;
    if (sfSprite_getPosition(game->enemies_one->sprite).x
            <= sfSprite_getPosition(game->towers->base1_sprite).x) {
    }
    return 0;
}