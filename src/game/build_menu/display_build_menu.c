/*
** EPITECH PROJECT, 2020
** display
** File description:
** display_build_menu
*/

#include "my.h"

int get_build(game_t *game, sfEvent event, sfVector2i mouse_position)
{
    if (event.type == sfEvtMouseButtonPressed &&
            (mouse_position.x >= 1003 && mouse_position.x <= 1079)
            && (mouse_position.y >= 34 && mouse_position.y <= 90)
            && game->in_game == 1) {
        game->in_build = 1;
    }
    if (event.type == sfEvtKeyPressed && game->in_build == 1
            && sfKeyboard_isKeyPressed(sfKeyEscape)){
        game->in_build = 0;
    }
}

int display_build_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                            game->build_menu->blank_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->build_menu->tower1_icon, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->build_menu->tower2_icon, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->build_menu->tower3_icon, NULL);
}

int display_build_icon(game_t *game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                            game->build_menu->build_sprite, NULL);
}