/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** enemies
*/

#include "my.h"

int init_enemies_one(game_t *game, sfClock *clock)
{
    sfVector2f pos  = {0, 490};

    if (!game || !clock)
        return 84;
    game->enemies_one->sprite = sfSprite_create();
    game->enemies_one->texture = sfTexture_createFromFile
            ("utils/imgs/enemies.png", NULL);
    if (!game->enemies_one->sprite || !game->enemies_one->texture)
        return 84;
    sfSprite_setTexture(game->enemies_one->sprite,
        game->enemies_one->texture, sfTrue);
    game->enemies_one->pos = pos;
    return 0;
}

int init_enemies_two(game_t *game, sfClock *clock)
{
    sfVector2f pos_two  = {0, 470};

    if (!game || !clock)
        return 84;
    game->enemies_two->sprite = sfSprite_create();
    game->enemies_two->texture = sfTexture_createFromFile
            ("utils/imgs/enemies.png", NULL);
    if (!game->enemies_two->sprite || !game->enemies_two->texture)
        return 84;
    sfSprite_setTexture(game->enemies_two->sprite,
        game->enemies_two->texture, sfTrue);
    game->enemies_two->pos = pos_two;
    return 0;
}

int init_enemies_three(game_t *game, sfClock *clock)
{
    sfVector2f pos_two  = {0, 465};

    if (!game || !clock)
        return 84;
    game->enemies_three->sprite = sfSprite_create();
    game->enemies_three->texture = sfTexture_createFromFile
            ("utils/imgs/enemies.png", NULL);
    if (!game->enemies_three->sprite || !game->enemies_three->texture)
        return 84;
    sfSprite_setTexture(game->enemies_three->sprite,
        game->enemies_three->texture, sfTrue);
    game->enemies_three->pos = pos_two;
    return 0;
}