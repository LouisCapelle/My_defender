/*
** EPITECH PROJECT, 2020
** event
** File description:
** event
*/

#include "my.h"

int event_type_menu(sfEvent event, sfVector2i mouse_position, game_t *game)
{
    if ((mouse_position.y >= 473 && mouse_position.y <= 560
        && game->in_menu == 1)
            && (mouse_position.x >= 472 && mouse_position.x <= 652)
            && (event.type == sfEvtMouseButtonPressed)) {
        game->in_menu = 0;
        game->in_game = 1;
        return 0;
    }
    if ((mouse_position.y >= 593 && mouse_position.y <= 688
        && game->in_menu == 1)
        && (mouse_position.x >= 473 && mouse_position.x <= 653)
        && (event.type == sfEvtMouseButtonPressed)) {
        return 1;
    }
    return 0;
}

int event_type_settings(sfEvent event, sfVector2i mouse_position, game_t *game)
{
    if ((mouse_position.x >= 1100 && mouse_position.x <= 1160
        && game->in_game == 1)
        && (mouse_position.y >= 35 && mouse_position.y <= 82)
        && (event.type == sfEvtMouseButtonPressed)) {
        game->in_pause = 0;
        game->in_game = 0;
        game->in_menu = 0;
        game->in_settings = 1;
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
        game->in_settings = 0;
        game->in_game = 1;
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
            || event_type_pause(event, mouse_position, game) == 1){
            return 1;
        }
        event_type_settings(event, mouse_position, game);
        get_escape(game, event);
    }
    return 0;
}