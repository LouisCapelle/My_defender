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
            clear_display(utils->window);
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
    game_t *game = malloc(sizeof(game_t));
    sfEvent event;
    sfMusic *song;
    sfVector2i mouse_pos;

    if (!game)
        return 84;
    if (init_game(game) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game->utils->window)) {
        display_background(game);
        sfRenderWindow_display(game->utils->window);
        if (event_type(event, game->utils) == 1)
            return 0;
    }
    sfMusic_destroy(song);
    sfRenderWindow_destroy(game->utils->window);
    return 0;
}