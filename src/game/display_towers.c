/*
** EPITECH PROJECT, 2020
** display_tower.c
** File description:
** display_towers
*/

#include "my.h"

int display_towers(game_t *game)
{
    if (game->money->is_placing == 1) {
        move_towers(game);
    }
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->tower1_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->tower_icon, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                    game->towers->tower2_sprite, NULL);
}