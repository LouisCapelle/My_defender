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
        game->is_alive = 1;
        game->in_menu = 0;
        game->in_pause = 0;
        game->in_settings = 0;
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
    if ((mouse_position.y >= 333 && mouse_position.y <= 429
        && game->in_pause == 1)
            && (mouse_position.x >= 500 && mouse_position.x <= 680)
            && (event.type == sfEvtMouseButtonPressed)) {
        game->in_pause = 0;
        game->in_game = 1;
    }
    if ((mouse_position.y >= 451 && mouse_position.y <= 537
        && game->in_pause == 1)
        && (mouse_position.x >= 440 && mouse_position.x <= 746)
        && (event.type == sfEvtMouseButtonPressed)) {
        game->in_pause = 0;
        game->in_game = 0;
        game->in_menu = 1;
    }
    if ((mouse_position.y >= 563 && mouse_position.y <= 657
        && game->in_pause == 1)
        && (mouse_position.x >= 500 && mouse_position.x <= 680)
        && (event.type == sfEvtMouseButtonPressed)) {
        return 1;
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
            && sfKeyboard_isKeyPressed(sfKeyEscape)
            && game->in_build == 0){
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
        get_click(game, event);
        put_towers(game, event);
        get_build(game, event, mouse_position);
    }
    return 0;
}