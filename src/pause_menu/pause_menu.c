/*
** EPITECH PROJECT, 2020
** pause
** File description:
** pause
*/

#include "my.h"

int pause_menu(game_t *game)
{
    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->back_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->main_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->play_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->quit_sprite, NULL);
    sfRenderWindow_drawText(game->utils->window,
                            game->menu_pause->pause_text, NULL);
    return 0;
}