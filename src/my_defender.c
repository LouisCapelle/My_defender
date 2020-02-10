/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "my.h"

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
    menu_t *screen;

    if (!display || !(window = init_struct_display(display)))
        return 84;
    init_screen_menu(window, screen);
    while (sfRenderWindow_isOpen(window)) {
        display_background(window, display);
        sfRenderWindow_display(window);
        event_type(event, window);
    }
    sfMusic_destroy(song);
    sfRenderWindow_destroy(window);
    return 0;
}