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

    game->enemies_one->shut = sfSprite_create();
    game->enemies_one->shut_texture = sfTexture_createFromFile
                ("./utils/imgs/shut.png", NULL);
    sfSprite_setScale(game->enemies_one->shut, scale);
    sfSprite_setPosition(game->enemies_one->shut, game->enemies_one->pos);
    sfSprite_setTexture(game->enemies_one->shut,
                        game->enemies_one->shut_texture, sfTrue);
    sfRenderWindow_drawSprite(game->utils->window,
        game->enemies_one->shut, NULL);
}

int live_enemies(game_t *game)
{
    int alive = 50;

    // game->castle->alive = alive;
    if (sfSprite_getPosition(game->enemies_one->sprite).x
            <= sfSprite_getPosition(game->towers->base1_sprite).x) {
        init_shut_enemies(game);
    }
    return 0;
}