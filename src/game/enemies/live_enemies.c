/*
** EPITECH PROJECT, 2020
** live
** File description:
** live
*/

#include "my.h"

int init_shut_enemies(game_t *game)
{
    sfVector2f scale = {0.1, 0.1};

    if (!game)
        return 84;
    game->enemies_one->shut = sfSprite_create();
    game->enemies_one->shut_texture = sfTexture_createFromFile
                ("./utils/imgs/shut.png", NULL);
    if (!game->enemies_one->shut || !game->enemies_one->shut_texture)
        return 84;
    sfSprite_setScale(game->enemies_one->shut, scale);
    sfSprite_setPosition(game->enemies_one->shut, game->enemies_one->pos);
    sfSprite_setTexture(game->enemies_one->shut,
                        game->enemies_one->shut_texture, sfTrue);
    sfRenderWindow_drawSprite(game->utils->window,
        game->enemies_one->shut, NULL);
    return 0;
}

int live_enemies(game_t *game)
{
    int alive = 50;

    if (!game)
        return 84;
    game->enemies_one->alive = alive;
    if (sfSprite_getPosition(game->enemies_one->sprite).x
            <= sfSprite_getPosition(game->towers->base1_sprite).x) {
        if (init_shut_enemies(game) == 84)
            return 84;
    }
    return 0;
}