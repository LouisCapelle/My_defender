/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "my.h"

int my_defender(game_t *game)
{
    sfEvent event;
    sfVector2i mouse_pos;

    if (!game || init_game(game) == 84
    || music_game(game) == 84 || init_settings(game) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game->utils->window)) {
        if (navigation_controller(game) == 84)
            return 84;
        sfRenderWindow_display(game->utils->window);
        if (event_type(event, game->utils, game) == 1)
            return 0;
    }
    return 0;
}