/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int init_castle(game_t *game)
{
    sfVector2f pos = {980, 180};
    sfVector2f scale = {0.1, 0.1};

    game->castle->sprite = sfSprite_create();
    game->castle->texture = sfTexture_createFromFile
            ("utils/imgs/castle.jpeg", NULL);
    sfSprite_setScale(game->enemys->sprite, scale);
    sfSprite_setTexture(game->castle->sprite, game->castle->texture, sfTrue);
    sfSprite_setPosition(game->castle->sprite, pos);
    sfRenderWindow_drawSprite(game->utils->window, game->castle->sprite, NULL);
    return 0;
}

int init_settings(game_t *game)
{
    sfVector2f pos = {1100, 20};
    sfVector2f scale = {0.3, 0.3};

    game->settings->sprite = sfSprite_create();
    game->settings->texture = sfTexture_createFromFile
            ("utils/imgs/settings.png", NULL);
    sfSprite_setScale(game->settings->sprite, scale);
    sfSprite_setTexture(game->settings->sprite,
            game->settings->texture, sfTrue);
    sfSprite_setPosition(game->settings->sprite, pos);
    sfRenderWindow_drawSprite(game->utils->window,
        game->settings->sprite, NULL);
    return 0;
}