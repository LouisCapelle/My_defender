/*
** EPITECH PROJECT, 2020
** rect
** File description:
** rect
*/

#include "my.h"

int move_enemys(game_t *game, sfClock *clock)
{
    int x = sfSprite_getPosition(game->enemys->sprite).x;
    int y = sfSprite_getPosition(game->enemys->sprite).y;

    sfSprite_setPosition(game->enemys->sprite, game->enemys->pos);
    sfRenderWindow_drawSprite(game->utils->window, game->enemys->sprite, NULL);
    if (x >= 0 && x <= 267 && y == 470) {
        game->enemys->pos.x = game->enemys->pos.x + 2;
    }
    if (y <= 470 && y >= 159 && x == 270) {
        game->enemys->pos.y = game->enemys->pos.y - 2;
    }
    move_enemies_two(game, clock, x, y);
    return 0;
}

int move_enemies_two(game_t *game, sfClock *clock, int x, int y)
{
    if (y == 156 && x >= 270 && x <= 708) {
        game->enemys->pos.x = game->enemys->pos.x + 2;
    }
    if (y >= 156 && y <= 700 && x == 712) {
        game->enemys->pos.y = game->enemys->pos.y + 2;
    }
    if (y >= 286 && x >= 712 && x < 1200) {
        game->enemys->pos.x = game->enemys->pos.x + 2;
    }
    if (sfSprite_getPosition(game->enemys->sprite).x >= 1200) {
        game->enemys->pos.x = 0;
        game->enemys->pos.y = 470;
        sfSprite_setPosition(game->enemys->sprite, game->enemys->pos);
    }
    return 0;
}