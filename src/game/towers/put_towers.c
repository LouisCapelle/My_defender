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

    if (!game || init_base_towers(game) == 84)
        return 84;
    game->towers->tower_icon = sfSprite_create();
    if (!game->towers->tower_icon)
        return 84;
    sfSprite_setScale(game->towers->tower_icon, icon_scale);
    sfSprite_setPosition(game->towers->tower_icon, tower_icon_position);
    sfSprite_setRotation(game->towers->tower_icon, 180);
    game->towers->square = sfSprite_create();
    if (!game->towers->square)
        return 84;
    sfSprite_setTexture(game->towers->tower_icon,
                        game->towers->tower1_texture, sfTrue);
    return 0;
}

int move_towers(game_t *game)
{
    sfVector2f pos;

    if (!game)
        return 84;
    sfSprite_setRotation(game->towers->tower_icon, 0);
    pos.x = sfMouse_getPositionRenderWindow(game->utils->window).x;
    pos.y = sfMouse_getPositionRenderWindow(game->utils->window).y;
    sfRenderWindow_setMouseCursorVisible(game->utils->window, sfFalse);
    sfSprite_setPosition(game->towers->tower_icon, pos);
    return 0;
}

int check_in_case(game_t *game, sfVector2i position)
{
    if (!game)
        return 84;
    if ((position.x <= 310 + 40 && position.x >= 310 - 40)
        && (position.y <= 110 + 40 && position.y >= 110 - 40)) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

int place_towers(game_t *game, sfVector2i position)
{
    sfVector2f pos;

    if (!game)
        return 84;
    pos.x = position.x;
    pos.y = position.y;
    sfRenderWindow_setMouseCursorVisible(game->utils->window, sfTrue);
    if (init_tower_icons(game) == 84)
        return 84;
    game->money->in_bank -= 1500;
    if (update_money(game) == 84)
        return 84;
    sfSprite_setTexture(game->towers->tower2_sprite,
                        game->towers->tower1_texture, sfTrue);
    if (check_in_case(game, position) == 1) {
        sfSprite_setPosition(game->towers->tower2_sprite, pos);
    }
    return 0;
}

int put_towers(game_t *game, sfEvent event)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                (game->utils->window);

    if (!game)
        return 84;
    if (event.type == sfEvtMouseButtonPressed &&
                    (mouse_position.x >= 774 && mouse_position.x <= 800
                    && mouse_position.y >= 19 && mouse_position.y <= 84)
                    && game->money->is_placing == 0) {
        game->money->is_placing = 1;
    }
    if (event.type == sfEvtMouseButtonReleased
        && game->money->is_placing == 1) {
        game->money->is_placing = 0;
        if (place_towers(game, mouse_position) == 84)
            return 84;
    }
    return 0;
}