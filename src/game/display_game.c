/*
** EPITECH PROJECT, 2020
** display_game
** File description:
** display_game
*/

#include "my.h"

void display_game(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(game->display->sprite, game->display->texture, sfFalse);
    sfSprite_setPosition(game->display->sprite, game->display->pos);
    sfRenderWindow_drawSprite(game->utils->window, game->display->sprite, NULL);
}