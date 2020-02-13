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
    }else if (game->in_menu == 0) {
        clear_display(game->utils->window);
    }else {
        return (84);
    }
}