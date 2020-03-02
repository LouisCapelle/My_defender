/*
** EPITECH PROJECT, 2020
** display
** File description:
** display_build_menu
*/

#include "my.h"

int display_build_icon(game_t *game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                            game->build_menu->build_sprite, NULL);
}