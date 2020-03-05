/*
** EPITECH PROJECT, 2020
** init base
** File description:
** init base
*/

#include "my.h"

int set_positions_base(game_t *game)
{
    sfVector2f pos_1 = {310, 110};
    sfVector2f pos_2 = {355, 510};
    sfVector2f pos_3 = {650, 250};
    sfVector2f pos_4 = {850, 380};

    if (!game)
        return 84;
    sfSprite_setPosition(game->towers->base1_sprite, pos_1);
    sfSprite_setPosition(game->towers->base2_sprite, pos_2);
    sfSprite_setPosition(game->towers->base3_sprite, pos_3);
    sfSprite_setPosition(game->towers->base4_sprite, pos_4);
    return 0;
}

int set_scales(game_t *game)
{
    sfVector2f scale = {0.06, 0.06};

    if (!game)
        return 84;
    sfSprite_setScale(game->towers->base1_sprite, scale);
    sfSprite_setScale(game->towers->base2_sprite, scale);
    sfSprite_setScale(game->towers->base3_sprite, scale);
    sfSprite_setScale(game->towers->base4_sprite, scale);
    return 0;
}

int create_sprites(game_t *game)
{
    if (!game)
        return 84;
    game->towers->base1_sprite = sfSprite_create();
    game->towers->base2_sprite = sfSprite_create();
    game->towers->base3_sprite = sfSprite_create();
    game->towers->base4_sprite = sfSprite_create();
    if (!game->towers->base1_sprite || !game->towers->base2_sprite
    || !game->towers->base3_sprite || !game->towers->base4_sprite)
        return 84;
    sfSprite_setTexture(game->towers->base1_sprite,
                        game->towers->base_texture, sfTrue);
    sfSprite_setTexture(game->towers->base2_sprite,
                        game->towers->base_texture, sfTrue);
    sfSprite_setTexture(game->towers->base3_sprite,
                        game->towers->base_texture, sfTrue);
    sfSprite_setTexture(game->towers->base4_sprite,
                        game->towers->base_texture, sfTrue);
    return 0;
}

int init_base_towers(game_t *game)
{
    if (!game)
        return 84;
    game->towers->base_texture = sfTexture_createFromFile
                                ("./utils/imgs/base_towers.png", NULL);
    if (create_sprites(game) == 84 || set_scales(game) == 84
    || set_positions_base(game) == 84)
        return 84;
    return 0;
}