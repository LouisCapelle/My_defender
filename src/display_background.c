/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_background(sfRenderWindow *window, display_t *display)
{
    sfSprite_setPosition(display->sprite, display->pos);
    sfRenderWindow_drawSprite(window, display->sprite, NULL);
    return 0;
}