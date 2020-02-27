/*
** EPITECH PROJECT, 2020
** live
** File description:
** live
*/

#include "my.h"

int live_castle(game_t *game)
{
    if (sfSprite_getPosition(game->enemies_three->sprite).x >= 985) {
        game->castle->alive = game->castle->alive - 10;
        printf("alive -----> %i\n", game->castle->alive);
    }
    if (sfSprite_getPosition(game->enemies_one->sprite).x >= 985) {
        game->castle->alive = game->castle->alive - 10;
        printf("alive -----> %i\n", game->castle->alive);
    }
    if (sfSprite_getPosition(game->enemies_two->sprite).x >= 985) {
        game->castle->alive = game->castle->alive - 10;
        printf("alive -----> %i\n", game->castle->alive);
    }
    if (game->castle->alive == 0) {
        game->is_alive = 0;
    }
    return 0;
}