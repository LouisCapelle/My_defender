/*
** EPITECH PROJECT, 2020
** highlight
** File description:
** highlight
*/

#include "my.h"

int display_highlight_play(game_t *game)
{
    sfVector2i mouse_position
    = sfMouse_getPositionRenderWindow(game->utils->window);

    if (mouse_position.y >= 476 && mouse_position.y <= 541
            && mouse_position.x >= 483 && mouse_position.x <= 699) {
        sfSprite_setTexture(game->screen->play_sprite,
                            game->screen->play_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->screen->play_sprite,
                            game->screen->play_texture, sfTrue);
    }
}

int display_highlight_quit(game_t *game)
{
    sfVector2i mouse_position
    = sfMouse_getPositionRenderWindow(game->utils->window);

    if (mouse_position.y >= 574 && mouse_position.y <= 665
            && mouse_position.x >= 475 && mouse_position.x <= 695) {
        sfSprite_setTexture(game->screen->quit_sprite,
                            game->screen->quit_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->screen->quit_sprite,
                            game->screen->quit_texture, sfTrue);
    }
}