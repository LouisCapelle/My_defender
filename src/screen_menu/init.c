/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

sfRenderWindow *init_struct_display(display_t *display)
{
    sfVector2f pos = {0, 0};
    sfVector2f offset = {5, 0};

    display->texture = sfTexture_createFromFile("utils/imgs/background.jpg",
                                                                    NULL);
    display->sprite = sfSprite_create();
    display->clock = sfClock_create();
    if (!display->sprite || !display->texture || !display->clock)
        return NULL;
    display->pos = pos;
    display->offset = offset;
    display->video_mode.width = 1200;
    display->video_mode.height = 700;
    display->video_mode.bitsPerPixel = 32;

    display->window = sfRenderWindow_create(display->video_mode,
                "MyDefender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(display->window, 60);
    return (display->window);
}

int init_screen_menu(sfRenderWindow *window, menu_t *screen)
{
    screen->play_texture = sfTexture_createFromFile
                                    ("utils/imgs/play_button.png", NULL);
    screen->play_sprite = sfSprite_create();
    sfSprite_setTexture(screen->play_sprite, screen->play_texture, sfTrue);
    display_menu(window, screen);
}