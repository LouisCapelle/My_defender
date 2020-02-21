/*
** EPITECH PROJECT, 2020
** move
** File description:
** move
*/

#include "my.h"

int move_enemies_three_next(game_t *game, sfClock *clock, int x, int y)
{
    if (y == 155 && x >= 269 && x <= 708) {
        game->enemies_three->pos.x = game->enemies_three->pos.x + 1;
    }
    if (y >= 155 && y <= 300 && x == 710) {
        game->enemies_three->pos.y = game->enemies_three->pos.y + 3;
    }
    if (y == 305 && x >= 710 && x < 1200) {
        game->enemies_three->pos.x = game->enemies_three->pos.x + 3;
    }
    if (sfSprite_getPosition(game->enemies_three->sprite).x >= 990) {
        game->enemies_three->pos.x = 0;
        game->enemies_three->pos.y = 465;
        sfSprite_setPosition(game->enemies_three->sprite,
            game->enemies_three->pos);
    }
    return 0;
}