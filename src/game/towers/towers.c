/*
** EPITECH PROJECT, 2020
** towers
** File description:
** towers
*/

#include "my.h"
#include <time.h>

int rotate_tower_two(game_t *game, sfTime time, float seconds)
{
    if (!game)
        return 84;
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
    return 0;
}

int rotate_tower(game_t *game)
{
    sfTime time;
    float seconds = 0;
    float position = sfSprite_getRotation(game->towers->tower1_sprite);
    if (!game)
        return 84;
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
    if (rotate_tower_two(game, time, seconds) == 84)
        return 84;
    return 0;
}

int init_towers(game_t *game)
{
    sfVector2f scale_tower = {0.3, 0.3};
    if (!game || init_tower_icons(game) == 84)
        return 84;
    game->towers->go_to_base = 0;
    game->towers->go_to_zero = 1;
    game->towers->tower1_sprite = sfSprite_create();
    game->towers->tower2_sprite = sfSprite_create();
    game->towers->tower1_texture = sfTexture_createFromFile
                                ("./utils/imgs/tower.png", NULL);
    if (!game->towers->tower1_sprite || !game->towers->tower2_sprite
    || !game->towers->tower1_texture)
        return 84;
    sfSprite_setScale(game->towers->tower1_sprite, scale_tower);
    sfSprite_setScale(game->towers->tower2_sprite, scale_tower);
    return 0;
}

int init_towers_next(game_t *game)
{
    sfVector2f origin = {70.5, 260};
    sfVector2f pos_tower1 = {380, 540};
    sfVector2f pos_tower2 = {2000, 2000};

    if (!game)
        return 84;
    sfSprite_setTexture(game->towers->tower1_sprite,
                        game->towers->tower1_texture, sfTrue);
    sfSprite_setOrigin(game->towers->tower1_sprite, origin);
    sfSprite_setPosition(game->towers->tower1_sprite, pos_tower1);
    sfSprite_setPosition(game->towers->tower2_sprite, pos_tower2);
    sfSprite_setRotation(game->towers->tower1_sprite, 300);
    return 0;
}