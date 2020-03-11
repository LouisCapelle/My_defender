/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

int init_tower2_icon(game_t *game)
{
    sfVector2f tower_icon_position = {840, 85};
    sfVector2f icon_scale = {0.25, 0.25};

    game->towers->tower2_texture = sfTexture_createFromFile("./utils/imgs/tower2.png", NULL);
    game->towers->tower2_icon = sfSprite_create();
    sfSprite_setScale(game->towers->tower2_icon, icon_scale);
    sfSprite_setPosition(game->towers->tower2_icon, tower_icon_position);
    sfSprite_setRotation(game->towers->tower2_icon, 180);
    sfSprite_setTexture(game->towers->tower2_icon,
                        game->towers->tower2_texture, sfTrue);
}

int init_tower3_icon(game_t *game)
{
    sfVector2f tower_icon_position = {880, 85};
    sfVector2f icon_scale = {0.25, 0.25};

    game->towers->tower3_texture = sfTexture_createFromFile("./utils/imgs/tower3.png", NULL);
    game->towers->tower3_icon = sfSprite_create();
    sfSprite_setScale(game->towers->tower3_icon, icon_scale);
    sfSprite_setPosition(game->towers->tower3_icon, tower_icon_position);
    sfSprite_setRotation(game->towers->tower3_icon, 180);
    sfSprite_setTexture(game->towers->tower3_icon,
                        game->towers->tower3_texture, sfTrue);
}

int init_tower_icons(game_t *game)
{
    sfVector2f tower_icon_position = {800, 85};
    sfVector2f icon_scale = {0.2, 0.2};

    init_tower2_icon(game);
    init_tower3_icon(game);
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