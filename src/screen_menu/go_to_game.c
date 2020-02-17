/*
** EPITECH PROJECT, 2020
** going to game
** File description:
** go_to_game
*/

#include "my.h"

void menu_display(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    display_game(window, game);
}