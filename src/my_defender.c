/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "my.h"

void event_type(sfEvent event, utils_t *utils)
{
    while (sfRenderWindow_pollEvent(utils->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(utils->window);
    }
}

int my_defender(void)
{
    utils_t *utils = malloc(sizeof(utils_t));
    display_t *display = malloc(sizeof(display_t));
    menu_t *screen = malloc(sizeof(menu_t));
    sfEvent event;
    sfMusic *song;

    if (!display || !(utils->window = init_struct_display(display, utils)))
        return 84;
    init_screen_menu(utils, screen);
    while (sfRenderWindow_isOpen(utils->window)) {
        display_background(utils, display, screen);
        init_screen_menu(utils, screen);
        sfRenderWindow_display(utils->window);
        event_type(event, utils);
    }
    sfMusic_destroy(song);
    sfRenderWindow_destroy(utils->window);
    return 0;
}