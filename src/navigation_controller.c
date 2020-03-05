/*
** EPITECH PROJECT, 2020
** navigatoin controller
** File description:
** navigation_controller
*/

#include "my.h"

int navigation_controller(game_t *game)
{
    if (game->in_menu == 1) {
        display_background(game);
    } else if (game->in_menu == 0 && game->in_pause == 0
                && game->is_alive == 1) {
        if (display_game(game->utils->window, game) == 84)
            return 84;
        if (game->in_build == 1) {
            display_build_menu(game);
        }
    }
    if (navigation_controller_next(game) == 84)
        return 84;
    return 0;
}

int navigation_controller_next(game_t *game)
{
    if (game->in_pause == 1 && game->in_game == 0) {
        if (pause_menu(game) == 84)
            return 84;
    }
    if (game->in_settings == 1 && game->in_game == 0) {
        if (display_settings(game) == 84)
            return 84;
    }
    if (game->is_alive == 0 && game->in_game == 1) {
        if (display_background(game) == 84)
            return 84;
    }
    return 0;
}