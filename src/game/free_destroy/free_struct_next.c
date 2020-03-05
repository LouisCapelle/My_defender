/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#include "my.h"

int destroy_sprite_next(game_t *game, menu_t *screen, display_t *display)
{
    if (!game || !screen || !display)
        return 84;
    sfSprite_destroy(game->towers->base1_sprite);
    sfSprite_destroy(game->towers->base2_sprite);
    sfSprite_destroy(game->towers->base3_sprite);
    sfSprite_destroy(game->towers->base4_sprite);
    sfSprite_destroy(game->towers->tower_icon);
    sfSprite_destroy(game->towers->square);
    sfSprite_destroy(game->towers->tower1_sprite);
    sfSprite_destroy(game->towers->tower2_sprite);
    sfSprite_destroy(game->terrain->background_sprite);
    sfSprite_destroy(game->castle->sprite);
    sfSprite_destroy(game->settings->sprite);
    sfSprite_destroy(game->settings->esc_sprite);
    sfSprite_destroy(game->settings->plus_sprite);
    sfSprite_destroy(game->settings->moins_sprite);
    return 0;
}