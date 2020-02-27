/*
** EPITECH PROJECT, 2020
** init base
** File description:
** init base
*/

#include "my.h"

int set_positions_base(game_t *game)
{
    sfVector2f pos_1 = {50, 50};
    sfVector2f pos_2 = {100, 100};
    sfVector2f pos_3 = {150, 150};
    sfVector2f pos_4 = {200, 200};
    sfVector2f pos_5 = {250, 250};

    sfSprite_setPosition(game->towers->base1_sprite, pos_1);
    sfSprite_setPosition(game->towers->base2_sprite, pos_2);
    sfSprite_setPosition(game->towers->base3_sprite, pos_3);
    sfSprite_setPosition(game->towers->base4_sprite, pos_4);
    sfSprite_setPosition(game->towers->base5_sprite, pos_5);
}

int set_scales(game_t *game)
{
    sfVector2f scale = {0.06, 0.06};

    sfSprite_setScale(game->towers->base1_sprite, scale);
    sfSprite_setScale(game->towers->base2_sprite, scale);
    sfSprite_setScale(game->towers->base3_sprite, scale);
    sfSprite_setScale(game->towers->base4_sprite, scale);
    sfSprite_setScale(game->towers->base5_sprite, scale);
}

int create_sprites(game_t *game)
{
    game->towers->base1_sprite = sfSprite_create();
    game->towers->base2_sprite = sfSprite_create();
    game->towers->base3_sprite = sfSprite_create();
    game->towers->base4_sprite = sfSprite_create();
    game->towers->base5_sprite = sfSprite_create();
    sfSprite_setTexture(game->towers->base1_sprite,
                        game->towers->base_texture, sfTrue);
    sfSprite_setTexture(game->towers->base2_sprite,
                        game->towers->base_texture, sfTrue);
    sfSprite_setTexture(game->towers->base3_sprite,
                        game->towers->base_texture, sfTrue);
    sfSprite_setTexture(game->towers->base4_sprite,
                        game->towers->base_texture, sfTrue);
    sfSprite_setTexture(game->towers->base5_sprite,
                        game->towers->base_texture, sfTrue);
}

int init_base_towers(game_t *game)
{
    game->towers->base_texture = sfTexture_createFromFile
                                ("./utils/imgs/base_towers.png", NULL);
    create_sprites(game);
    set_scales(game);
    set_positions_base(game);
}