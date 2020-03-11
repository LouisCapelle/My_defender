/*
** EPITECH PROJECT, 2020
** display_tower.c
** File description:
** display_towers
*/

#include "my.h"

int display_towers(game_t *game)
{
    if (!game)
        return 84;
    if (game->money->is_placing == 1)
        if (move_towers(game) == 84)
            return 84;
    if (display_base_towers(game) == 84)
        return 84;
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->tower1_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                    game->towers->tower2_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->tower_icon, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->tower2_icon, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->tower3_icon, NULL);
    return 0;
}