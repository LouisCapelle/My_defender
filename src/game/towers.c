/*
** EPITECH PROJECT, 2020
** towers
** File description:
** towers
*/

#include "my.h"
#include <time.h>

void rotate_tower_two(game_t *game, sfTime time, float seconds)
{
    if (game->towers->go_to_base == 1){

        time = sfClock_getElapsedTime(game->towers->clock);
        seconds = time.microseconds / 100000.0;
        if (seconds < 32){
            sfSprite_rotate(game->towers->tower1_sprite, -0.5);
        }
        if (seconds > 34){
            seconds = 0;
            game->towers->go_to_base = 0;
            game->towers->go_to_zero = 1;
            sfClock_restart(game->towers->clock);
        }
    }
}

void rotate_tower(game_t *game)
{
    sfTime time;
    float seconds = 0;
    float position = sfSprite_getRotation(game->towers->tower1_sprite);

    if (game->towers->go_to_zero == 1){
        time = sfClock_getElapsedTime(game->towers->clock);
        seconds = time.microseconds / 100000.0;
        if (seconds < 32){
            sfSprite_rotate(game->towers->tower1_sprite, 0.5);
        }
        if (seconds > 34){
            seconds = 0;
            game->towers->go_to_base = 1;
            game->towers->go_to_zero = 0;
            sfClock_restart(game->towers->clock);
        }
    }
    rotate_tower_two(game, time, seconds);
}

void init_towers(game_t *game)
{
    sfVector2f origin = {70.5, 260};
    sfVector2f pos_tower1 = {380, 540};
    sfVector2f pos_tower2 = {2000, 2000};
    sfVector2f scale_tower = {0.3, 0.3};

    init_tower_icons(game);
    game->towers->go_to_base = 0;
    game->towers->go_to_zero = 1;
    game->towers->tower1_sprite = sfSprite_create();
    game->towers->tower2_sprite = sfSprite_create();
    game->towers->tower1_texture = sfTexture_createFromFile
                                ("./utils/imgs/tower.png", NULL);
    sfSprite_setScale(game->towers->tower1_sprite, scale_tower);
    sfSprite_setScale(game->towers->tower2_sprite, scale_tower);
    sfSprite_setTexture(game->towers->tower1_sprite,
                        game->towers->tower1_texture, sfTrue);
    sfSprite_setOrigin(game->towers->tower1_sprite, origin);
    sfSprite_setPosition(game->towers->tower1_sprite, pos_tower1);
    sfSprite_setPosition(game->towers->tower2_sprite, pos_tower2);
    sfSprite_setRotation(game->towers->tower1_sprite, 300);
}