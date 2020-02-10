/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

int init_struct_display(display_t *display)
{
    sfVector2f pos = {0, 0};
    sfVector2f offset = {5, 0};

    display->texture = sfTexture_createFromFile("utils/background.jpg", NULL);
    display->sprite = sfSprite_create();
    display->clock = sfClock_create();
    if (!display->sprite || !display->texture || !display->clock)
        return 84;
    display->pos = pos;
    display->offset = offset;
    return 0;
}