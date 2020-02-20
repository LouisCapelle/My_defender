/*
** EPITECH PROJECT, 2020
** towers
** File description:
** towers
*/

#include "my.h"
#include <time.h>

void rotate_tower(game_t *game)
{
    sfTime time;
    float seconds = 0;
    float position = sfSprite_getRotation(game->terrain->tower1_sprite);

    if (game->terrain->go_to_zero == 1){
        time = sfClock_getElapsedTime(game->terrain->clock);
        seconds = time.microseconds / 100000.0;
        if (seconds < 32){
            sfSprite_rotate(game->terrain->tower1_sprite, 0.5);
        }
        if (seconds > 34){
            seconds = 0;
            game->terrain->go_to_base = 1;
            game->terrain->go_to_zero = 0;
            sfClock_restart(game->terrain->clock);
        }
    }
    if (game->terrain->go_to_base == 1){

        time = sfClock_getElapsedTime(game->terrain->clock);
        seconds = time.microseconds / 100000.0;
        if (seconds < 32){
            sfSprite_rotate(game->terrain->tower1_sprite, -0.5);
        }
        if (seconds > 34){
            seconds = 0;
            game->terrain->go_to_base = 0;
            game->terrain->go_to_zero = 1;
            sfClock_restart(game->terrain->clock);
        }
    }
}

void init_towers(game_t *game)
{
    sfVector2f pos_tower1 = {330, 540};
    sfVector2f origin = {64, 64};

    game->terrain->go_to_base = 0;
    game->terrain->go_to_zero = 1;
    game->terrain->tower1_sprite = sfSprite_create();
    game->terrain->tower1_texture = sfTexture_createFromFile
                                ("./utils/imgs/tower1.png", NULL);
    sfSprite_setTexture(game->terrain->tower1_sprite,
                        game->terrain->tower1_texture, sfTrue);
    sfSprite_setPosition(game->terrain->tower1_sprite, pos_tower1);
    sfSprite_setOrigin(game->terrain->tower1_sprite, origin);
    sfSprite_setRotation(game->terrain->tower1_sprite, 300);
}