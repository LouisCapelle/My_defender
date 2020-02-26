/*
** EPITECH PROJECT, 2020
** put_towers
** File description:
** put_towers
*/

#include "my.h"

int init_tower_icons(game_t *game)
{
    sfVector2f tower_icon_position = {800, 85};
    sfVector2f icon_scale = {0.2, 0.2};

    game->towers->tower_icon = sfSprite_create();
    sfSprite_setScale(game->towers->tower_icon, icon_scale);
    sfSprite_setPosition(game->towers->tower_icon, tower_icon_position);
    sfSprite_setRotation(game->towers->tower_icon, 180);
    game->towers->square = sfSprite_create();
    sfSprite_setTexture(game->towers->tower_icon,
                        game->towers->tower1_texture, sfTrue);
}

int move_towers(game_t *game)
{
    sfVector2f pos;

    sfSprite_setRotation(game->towers->tower_icon, 0);
    pos.x = sfMouse_getPositionRenderWindow(game->utils->window).x;
    pos.y = sfMouse_getPositionRenderWindow(game->utils->window).y;
    sfRenderWindow_setMouseCursorVisible(game->utils->window, sfFalse);
    sfSprite_setPosition(game->towers->tower_icon, pos);
}

int place_towers(game_t *game, sfVector2i position)
{
    sfVector2f pos;

    pos.x = position.x;
    pos.y = position.y;
    sfRenderWindow_setMouseCursorVisible(game->utils->window, sfTrue);
    init_tower_icons(game);
    game->money->in_bank -= 1500;
    update_money(game);
    sfSprite_setTexture(game->towers->tower2_sprite,
                        game->towers->tower1_texture, sfTrue);
    sfSprite_setPosition(game->towers->tower2_sprite, pos);
}

int put_towers(game_t *game, sfEvent event)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                (game->utils->window);

    if (event.type == sfEvtMouseButtonPressed &&
                    (mouse_position.x >= 774 && mouse_position.x <= 800
                    && mouse_position.y >= 19 && mouse_position.y <= 84)
                    && game->money->is_placing == 0) {
        game->money->is_placing = 1;
    }
    if (event.type == sfEvtMouseButtonReleased
        && game->money->is_placing == 1) {
        game->money->is_placing = 0;
        place_towers(game, mouse_position);
    }
}