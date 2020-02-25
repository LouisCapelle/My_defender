/*
** EPITECH PROJECT, 2020
** put_towers
** File description:
** put_towers
*/

#include "my.h"

int init_tower_icons(game_t *game)
{
    sfVector2f tower_icon_position = {500, 500};
    sfVector2f icon_scale = {0.2, 0.2};

    game->towers->tower_icon = sfSprite_create();
    sfSprite_setScale(game->towers->tower_icon, icon_scale);
    sfSprite_setPosition(game->towers->tower_icon, tower_icon_position);
    sfSprite_setTexture(game->towers->tower_icon,
                        game->towers->tower1_texture, sfTrue);
}

int init_money(game_t *game)
{
    game->money->is_placing = 0;
}

int move_towers(game_t *game)
{
    sfVector2f pos;

    pos.x = sfMouse_getPositionRenderWindow(game->utils->window).x;
    pos.y = sfMouse_getPositionRenderWindow(game->utils->window).y;
    sfRenderWindow_setMouseCursorVisible(game->utils->window, sfFalse);
    sfSprite_setPosition(game->towers->tower_icon, pos);
}

int place_towers(game_t *game, sfEvent event)
{
    game->money->is_placing = 0;
}

int put_towers(game_t *game, sfEvent event)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                (game->utils->window);
    if (event.type == sfEvtMouseButtonPressed &&
                    (mouse_position.x >= 505 && mouse_position.x <= 530
                    && mouse_position.y >= 551 && mouse_position.y <= 566)
                    && game->money->is_placing == 0) {
        game->money->is_placing = 1;
    }
    if (event.type == sfEvtMouseButtonReleased
        && game->money->is_placing == 1) {
        game->money->is_placing = 0;
        sfRenderWindow_setMouseCursorVisible(game->utils->window, sfTrue);
    }
}