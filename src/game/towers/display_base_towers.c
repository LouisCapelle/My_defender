/*
** EPITECH PROJECT, 2020
** display base towers
** File description:
** display_base_towers
*/

#include "my.h"

int display_base_towers(game_t *game)
{
    if (!game)
        return 84;
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->base1_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->base2_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->base3_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->towers->base4_sprite, NULL);
    return 0;
}