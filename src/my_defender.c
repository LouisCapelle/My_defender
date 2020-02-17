/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "my.h"

int my_defender(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfEvent event;
    sfVector2i mouse_pos;

    if (!game)
        return 84;
    if (init_game(game) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game->utils->window)) {
        navigation_controller(game);
        sfRenderWindow_display(game->utils->window);
        if (event_type(event, game->utils, game) == 1)
            return 0;
    }
    sfRenderWindow_destroy(game->utils->window);
    return 0;
}