/*
** EPITECH PROJECT, 2020
** pause_highlight
** File description:
** highlight
*/

#include "my.h"

int display_highlight_play_pause(game_t *game)
{
    sfVector2i mouse_position
    = sfMouse_getPositionRenderWindow(game->utils->window);

    if (!game)
        return 84;
    if (mouse_position.y >= 334 && mouse_position.y <= 427
            && mouse_position.x >= 500 && mouse_position.x <= 682) {
        sfSprite_setTexture(game->menu_pause->play_sprite,
                            game->menu_pause->play_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->menu_pause->play_sprite,
                            game->menu_pause->play_texture, sfTrue);
    }
    return 0;
}

int display_highlight_main_pause(game_t *game)
{
    sfVector2i mouse_position
    = sfMouse_getPositionRenderWindow(game->utils->window);

    if (!game)
        return 84;
    if (mouse_position.y >= 448 && mouse_position.y <= 543
            && mouse_position.x >= 501 && mouse_position.x <= 680) {
        sfSprite_setTexture(game->menu_pause->main_sprite,
                            game->menu_pause->main_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->menu_pause->main_sprite,
                            game->menu_pause->main_texture, sfTrue);
    }
    return 0;
}

int display_highlight_quit_pause(game_t *game)
{
    sfVector2i mouse_position
    = sfMouse_getPositionRenderWindow(game->utils->window);

    if (!game)
        return 84;
    if (mouse_position.y >= 563 && mouse_position.y <= 660
            && mouse_position.x >= 502 && mouse_position.x <= 681) {
        sfSprite_setTexture(game->menu_pause->quit_sprite,
                            game->menu_pause->quit_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->menu_pause->quit_sprite,
                            game->menu_pause->quit_texture, sfTrue);
    }
    return 0;
}