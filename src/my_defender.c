/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "my.h"

int event_type(sfEvent event, utils_t *utils, game_t *game)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(utils->window);

    while (sfRenderWindow_pollEvent(utils->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(utils->window);
        if ((mouse_position.y >= 476 && mouse_position.y <= 541 && game->in_menu == 1)
                && (mouse_position.x >= 483 && mouse_position.x <= 699)
                && (event.type == sfEvtMouseButtonPressed)) {
            game->in_menu = 0;
        }
        if ((mouse_position.y >= 574 && mouse_position.y <= 665 && game->in_menu == 1)
            && (mouse_position.x >= 475 && mouse_position.x <= 695)
            && (event.type == sfEvtMouseButtonPressed)) {
            return 1;
        }
        if (event.type == sfEvtKeyPressed && game->in_menu == 0
            && sfKeyboard_isKeyPressed(sfKeyEscape)){
            printf("ma bite\n");
            return 0;
        }
    }
    return 0;
}

int my_defender(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfEvent event;
    sfVector2i mouse_pos;

    if (!game)
        return 84;
    if (init_game(game) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game->utils->window)) {
        navigation_controller(game);
        sfRenderWindow_display(game->utils->window);
        if (event_type(event, game->utils, game) == 1)
            return 0;
    }
    sfRenderWindow_destroy(game->utils->window);
    return 0;
}