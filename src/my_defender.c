/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "my.h"

sfRenderWindow *create_window(display_t *display)
{
    display->video_mode.width = 1200;
    display->video_mode.height = 700;
    display->video_mode.bitsPerPixel = 32;

    display->window = sfRenderWindow_create(display->video_mode,
                "MyWindow", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(display->window, 60);
    return (display->window);
}

void event_type(sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
    }
}

int my_defender(sfRenderWindow *window)
{
    display_t *display = malloc(sizeof(display_t));
    sfEvent event;
    sfMusic *song;

    if (init_struct_display(display) == 84 || !display)
        return 84;
    window = create_window(display);
    if (!window) return 84;
    sfSprite_setTexture(display->sprite, display->texture, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setPosition(display->sprite, display->pos);
        sfRenderWindow_drawSprite(window, display->sprite, NULL);
        sfRenderWindow_display(window);
        event_type(event, window);
    }
    sfMusic_destroy(song);
    sfRenderWindow_destroy(window);
    return 0;
}