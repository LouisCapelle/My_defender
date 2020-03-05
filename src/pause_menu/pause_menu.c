/*
** EPITECH PROJECT, 2020
** pause
** File description:
** pause
*/

#include "my.h"

int pause_menu(game_t *game)
{
    if (!game)
        return 84;
    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->back_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->main_sprite, NULL);
    sfRenderWindow_drawText(game->utils->window,
                            game->menu_pause->pause_text, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->quit_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->play_sprite, NULL);
    if (display_highlight_quit_pause(game) == 84
    || display_highlight_play_pause(game) == 84
    || display_highlight_main_pause(game) == 84)
        return 84;
    return 0;
}