/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "my.h"

int event_type(sfEvent event, utils_t *utils)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(utils->window);

    while (sfRenderWindow_pollEvent(utils->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(utils->window);
        if ((mouse_position.y >= 476 && mouse_position.y <= 541)
                && (mouse_position.x >= 483 && mouse_position.x <= 699)
                && (event.type == sfEvtMouseButtonPressed)) {
            printf("bite\n");
        }
        if ((mouse_position.y >= 574 && mouse_position.y <= 665)
            && (mouse_position.x >= 475 && mouse_position.x <= 695)
            && (event.type == sfEvtMouseButtonPressed)) {
            return 1;
        }
    }
    return 0;
}
int my_defender(void)
{
    utils_t *utils = malloc(sizeof(utils_t));
    display_t *display = malloc(sizeof(display_t));
    menu_t *screen = malloc(sizeof(menu_t));
    sfEvent event;
    sfMusic *song;
    sfVector2i mouse_pos;

    if (!display || !(utils->window = init_struct_display(display, utils)))
        return 84;
    init_screen_menu(utils, screen);
    while (sfRenderWindow_isOpen(utils->window)) {
        display_background(utils, display, screen);
        init_screen_menu(utils, screen);
        sfRenderWindow_display(utils->window);
        if (event_type(event, utils) == 1)
            return 0;
    }
    sfMusic_destroy(song);
    sfRenderWindow_destroy(utils->window);
    return 0;
}