/*
** EPITECH PROJECT, 2020
** highlight
** File description:
** highlight
*/

#include "my.h"

int display_highlight_play(sfRenderWindow *window, menu_t *screen,
display_t *display)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);

    if (mouse_position.y >= 476 && mouse_position.y <= 541
            && mouse_position.x >= 483 && mouse_position.x <= 699) {
        sfSprite_setTexture(screen->play_sprite,
                            screen->play_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(screen->play_sprite,
                            screen->play_texture, sfTrue);
    }
}

int display_highlight_quit(sfRenderWindow *window, menu_t *screen,
display_t *display)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);

    if (mouse_position.y >= 574 && mouse_position.y <= 665
            && mouse_position.x >= 475 && mouse_position.x <= 695) {
        sfSprite_setTexture(screen->quit_sprite,
                            screen->quit_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(screen->quit_sprite,
                            screen->quit_texture, sfTrue);
    }
}