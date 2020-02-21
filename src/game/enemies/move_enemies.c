/*
** EPITECH PROJECT, 2020
** rect
** File description:
** rect
*/

#include "my.h"

int move_enemies_one(game_t *game, sfClock *clock)
{
    int x = sfSprite_getPosition(game->enemies_one->sprite).x;
    int y = sfSprite_getPosition(game->enemies_one->sprite).y;

    sfSprite_setPosition(game->enemies_one->sprite, game->enemies_one->pos);
    sfRenderWindow_drawSprite(game->utils->window,
        game->enemies_one->sprite, NULL);
    if (x >= 0 && x <= 267 && y == 490) {
        game->enemies_one->pos.x = game->enemies_one->pos.x + 2;
    }
    if (y <= 490 && y >= 159 && x == 270) {
        game->enemies_one->pos.y = game->enemies_one->pos.y - 2;
    }
    move_enemies_one_next(game, clock, x, y);
    return 0;
}

int move_enemies_one_next(game_t *game, sfClock *clock, int x, int y)
{
    if (y == 156 && x >= 270 && x <= 708) {
        game->enemies_one->pos.x = game->enemies_one->pos.x + 2;
    }
    if (y >= 156 && y <= 700 && x == 712) {
        game->enemies_one->pos.y = game->enemies_one->pos.y + 2;
    }
    if (y >= 286 && x >= 712 && x < 1200) {
        game->enemies_one->pos.x = game->enemies_one->pos.x + 2;
    }
    if (sfSprite_getPosition(game->enemies_one->sprite).x >= 990) {
        game->enemies_one->pos.x = 0;
        game->enemies_one->pos.y = 490;
        sfSprite_setPosition(game->enemies_one->sprite, game->enemies_one->pos);
    }
    return 0;
}

int move_enemies_two(game_t *game, sfClock *clock)
{
    int x = sfSprite_getPosition(game->enemies_two->sprite).x;
    int y = sfSprite_getPosition(game->enemies_two->sprite).y;

    sfSprite_setPosition(game->enemies_two->sprite, game->enemies_two->pos);
    sfRenderWindow_drawSprite(game->utils->window,
        game->enemies_two->sprite, NULL);
    if (x >= 0 && x <= 267 && y == 470) {
        game->enemies_two->pos.x = game->enemies_two->pos.x + 3;
    }
    if (y <= 470 && y >= 159 && x == 273) {
        game->enemies_two->pos.y = game->enemies_two->pos.y - 3;
    }
    move_enemies_two_next(game, clock, x, y);
    return 0;
}

int move_enemies_two_next(game_t *game, sfClock *clock, int x, int y)
{
    if (y == 155 && x >= 273 && x <= 708) {
        game->enemies_two->pos.x = game->enemies_two->pos.x + 3;
    }
    if (y >= 155 && y <= 300 && x == 714) {
        game->enemies_two->pos.y = game->enemies_two->pos.y + 3;
    }
    if (y == 305 && x >= 714 && x < 1200) {
        game->enemies_two->pos.x = game->enemies_two->pos.x + 3;
    }
    if (sfSprite_getPosition(game->enemies_two->sprite).x >= 990) {
        game->enemies_two->pos.x = 0;
        game->enemies_two->pos.y = 470;
        sfSprite_setPosition(game->enemies_two->sprite, game->enemies_two->pos);
    }
    return 0;
}

int move_enemies_three(game_t *game, sfClock *clock)
{
    int x = sfSprite_getPosition(game->enemies_three->sprite).x;
    int y = sfSprite_getPosition(game->enemies_three->sprite).y;

    sfSprite_setPosition(game->enemies_three->sprite, game->enemies_three->pos);
    sfRenderWindow_drawSprite(game->utils->window,
        game->enemies_three->sprite, NULL);
    if (x >= 0 && x <= 267 && y == 465) {
        game->enemies_three->pos.x = game->enemies_three->pos.x + 1;
    }
    if (y <= 465 && y >= 159 && x == 269) {
        game->enemies_three->pos.y = game->enemies_three->pos.y - 2;
    }
    move_enemies_three_next(game, clock, x, y);
    return 0;
}