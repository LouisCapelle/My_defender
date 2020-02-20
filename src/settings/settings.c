/*
** EPITECH PROJECT, 2020
** settings
** File description:
** settings
*/

#include "my.h"

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
    return 0;
}

int display_settings(game_t *game)
{
    sfVector2f scale = {1.5, 1.5};

    sfSprite_setScale(game->menu_pause->back_sprite, scale);
    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window,
        game->menu_pause->back_sprite, NULL);
}