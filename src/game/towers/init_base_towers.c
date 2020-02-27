/*
** EPITECH PROJECT, 2020
** init base
** File description:
** init base
*/

#include "my.h"

int set_scales(game_t *game)
{
    sfVector2f scale = {0.09, 0.09};

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
    sfVector2f pos_1;
    sfVector2f pos_2;
    sfVector2f pos_3;
    sfVector2f pos_4;
    sfVector2f pos_5;

    game->towers->base_texture = sfTexture_createFromFile
                                ("./utils/imgs/base_towers.png", NULL);
    create_sprites(game);
    set_scales(game);
}