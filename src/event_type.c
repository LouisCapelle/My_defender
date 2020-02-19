/*
** EPITECH PROJECT, 2020
** event_type
** File description:
** event_type
*/

#include "my.h"

int event_type_menu(sfEvent event, sfVector2i mouse_position, game_t *game)
{
    if ((mouse_position.y >= 476 && mouse_position.y <= 541
        && game->in_menu == 1)
            && (mouse_position.x >= 483 && mouse_position.x <= 699)
            && (event.type == sfEvtMouseButtonPressed)) {
        game->in_menu = 0;
        game->in_game = 1;
        return 0;
    }
    if ((mouse_position.y >= 574 && mouse_position.y <= 665
        && game->in_menu == 1)
        && (mouse_position.x >= 475 && mouse_position.x <= 695)
        && (event.type == sfEvtMouseButtonPressed)) {
        return 1;
    }
    return 0;
}

int event_type_settings(sfEvent event, sfVector2i mouse_position, game_t *game)
{
    if ((mouse_position.y >= 1100 && mouse_position.y <= 1110
        && game->in_settings == 1)
        && (mouse_position.x >= 20 && mouse_position.x <= 30)
        && (event.type == sfEvtMouseButtonPressed)) {
        game->in_settings = 1;
        return 1;
    }
    return 0;
}

int event_type_pause(sfEvent event, sfVector2i mouse_position, game_t *game)
{
    if ((mouse_position.y >= 455 && mouse_position.y <= 529
        && game->in_pause == 1)
            && (mouse_position.x >= 437 && mouse_position.x <= 802)
            && (event.type == sfEvtMouseButtonPressed)) {
        game->in_pause = 0;
        game->in_game = 1;
    }
    if ((mouse_position.y >= 553 && mouse_position.y <= 655
        && game->in_pause == 1)
        && (mouse_position.x >= 437 && mouse_position.x <= 794)
        && (event.type == sfEvtMouseButtonPressed)) {
        game->in_pause = 0;
        game->in_game = 0;
        game->in_menu = 1;
    }
    return 0;
}

int get_escape(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && game->in_pause == 1
        && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->in_pause = 0;
        game->in_game = 1;
        return 1;
    }
    if (event.type == sfEvtKeyPressed && game->in_game == 1
            && sfKeyboard_isKeyPressed(sfKeyEscape)){
        game->in_pause = 1;
        game->in_game = 0;
        return 0;
    }
    if (event.type == sfEvtKeyPressed && game->in_settings == 1
            && sfKeyboard_isKeyPressed(sfKeyEscape)){
        game->in_pause = 0;
        game->in_settings = 1;
        game->in_game = 0;
        return 0;
    }
}

int event_type(sfEvent event, utils_t *utils, game_t *game)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(utils->window);

    while (sfRenderWindow_pollEvent(utils->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(utils->window);
        if (event_type_menu(event, mouse_position, game) == 1
            || event_type_pause(event, mouse_position, game) == 1)
        if (event_type_settings(event, mouse_position, game) == 1) {
            display_settings(game);
            return 1;
        }
        get_escape(game, event);
    }
    return 0;
}