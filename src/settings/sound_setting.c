/*
** EPITECH PROJECT, 2020
** sounf settings
** File description:
** sound_setting
*/

#include "my.h"

int display_sound_settings(game_t * game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                            game->settings->moins_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->settings->plus_sprite, NULL);
}

int get_click(game_t *game, sfEvent event)
{

}

int init_sound_settings(game_t *game)
{
    sfVector2f pos1 = {700, 507};
    sfVector2f pos2 = {400, 500};
    sfVector2f scale1 = {0.1, 0.1};
    sfVector2f scale2 = {0.07, 0.07};

    game->settings->plus_sprite = sfSprite_create();
    game->settings->moins_sprite = sfSprite_create();
    game->settings->moins_texture = sfTexture_createFromFile
                                    ("./utils/imgs/moins.png", NULL);
    game->settings->plus_texture = sfTexture_createFromFile
                                    ("./utils/imgs/plus.png", NULL);
    sfSprite_setTexture(game->settings->plus_sprite,
                        game->settings->plus_texture, sfTrue);
    sfSprite_setTexture(game->settings->moins_sprite,
                        game->settings->moins_texture, sfTrue);
    sfSprite_setPosition(game->settings->moins_sprite, pos2);
    sfSprite_setPosition(game->settings->plus_sprite, pos1);
    sfSprite_setScale(game->settings->moins_sprite, scale1);
    sfSprite_setScale(game->settings->plus_sprite, scale2);
}