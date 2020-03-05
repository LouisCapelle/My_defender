/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy
*/

#include "my.h"

int destroy_all(game_t *game, display_t *display, menu_t *screen)
{
    if (!game || !display || !screen)
        return 84;
    sfMusic_destroy(game->utils->song);
    sfRenderWindow_destroy(game->utils->window);
    if (free_map(game) == 84 || destroy_texture(game, screen, display) == 84
    || destroy_utils(game, display) == 84
    || destroy_sprite(game, screen, display) == 84)
        return 84;
    return 0;
}