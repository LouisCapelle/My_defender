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

    if (!game)
        return 84;
    if (init_game(game) == 84 || music_game(game))
        return 84;
    init_settings(game);
    while (sfRenderWindow_isOpen(game->utils->window)) {
        navigation_controller(game);
        sfRenderWindow_display(game->utils->window);
        if (event_type(event, game->utils, game) == 1)
            return 0;
    }
    return 0;
}