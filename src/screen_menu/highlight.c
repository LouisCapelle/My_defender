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

    if (mouse_position.y >= 473 && mouse_position.y <= 560
            && mouse_position.x >= 472 && mouse_position.x <= 652) {
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

    if (mouse_position.y >= 593 && mouse_position.y <= 688
            && mouse_position.x >= 473 && mouse_position.x <= 653) {
        sfSprite_setTexture(game->screen->quit_sprite,
                            game->screen->quit_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->screen->quit_sprite,
                            game->screen->quit_texture, sfTrue);
    }
}