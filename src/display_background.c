/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_background(utils_t *utils, display_t *display, menu_t *screen)
{
    sfSprite_setPosition(display->sprite, display->pos);
    sfRenderWindow_drawSprite(utils->window, display->sprite, NULL);
    return 0;
}