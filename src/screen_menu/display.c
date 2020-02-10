/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_background(sfRenderWindow *window, display_t *display)
{
    sfSprite_setTexture(display->sprite, display->texture, sfFalse);
    sfSprite_setPosition(display->sprite, display->pos);
    sfRenderWindow_drawSprite(window, display->sprite, NULL);
    return 0;
}

int display_menu(sfRenderWindow *window, menu_t *screen)
{
    screen->pos.x = 500;
    screen->pos.y = 500;
    sfSprite_setPosition(screen->play_sprite, screen->pos);
    sfRenderWindow_drawSprite(window, screen->play_sprite, NULL);
}