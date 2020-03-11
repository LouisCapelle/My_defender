/*
** EPITECH PROJECT, 2020
** put_towers
** File description:
** put_towers
*/

#include "my.h"

int move_towers(game_t *game, int i)
{
    sfVector2f pos;

    if (!game)
        return 84;
    sfSprite_setRotation(game->towers->tower_icon, 0);
    pos.x = sfMouse_getPositionRenderWindow(game->utils->window).x;
    pos.y = sfMouse_getPositionRenderWindow(game->utils->window).y;
    sfRenderWindow_setMouseCursorVisible(game->utils->window, sfFalse);
    if (i == 1) {
        sfSprite_setPosition(game->towers->tower_icon, pos);
    }
    if (i == 2) {
        sfSprite_setPosition(game->towers->tower2_icon, pos);
    }
    if (i == 3){
        sfSprite_setPosition(game->towers->tower3_icon, pos);
    }
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

int place_towers2(game_t *game, sfVector2i position)
{
    sfVector2f pos;

    if (!game)
        return 84;
    pos.x = position.x;
    pos.y = position.y;
    sfSprite_setRotation(game->towers->tower_icon, 180);
    sfRenderWindow_setMouseCursorVisible(game->utils->window, sfTrue);
    if (init_tower_icons(game) == 84)
        return 84;
    game->money->in_bank -= 1500;
    if (update_money(game) == 84)
        return 84;
    sfSprite_setTexture(game->towers->tower3_sprite,
                        game->towers->tower2_texture, sfTrue);
    sfSprite_setPosition(game->towers->tower3_sprite, pos);
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
int put_towers2(game_t *game, sfEvent event)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                (game->utils->window);

    if (!game)
        return 84;
    if (event.type == sfEvtMouseButtonPressed &&
                    (mouse_position.x >= 811 && mouse_position.x <= 841
                    && mouse_position.y >= 19 && mouse_position.y <= 84)
                    && game->money->is_placing == 0) {
        game->money->is_placing = 2;
    }
    if (event.type == sfEvtMouseButtonReleased && game->money->is_placing == 2) {
        game->money->is_placing = 0;
        place_towers2(game, mouse_position);
    }
    return 0;
}