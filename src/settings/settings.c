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
    sfVector2f pos_esc = {200, 100};

    game->settings->sprite = sfSprite_create();
    game->settings->texture = sfTexture_createFromFile
            ("utils/imgs/settings.png", NULL);
    game->settings->esc_sprite = sfSprite_create();
    game->settings->esc_texture = sfTexture_createFromFile
            ("utils/imgs/esc.jpeg", NULL);
    game->settings->esc_text = sfText_create();
    sfSprite_setScale(game->settings->sprite, scale);
    sfSprite_setTexture(game->settings->sprite,
            game->settings->texture, sfTrue);
    sfSprite_setPosition(game->settings->sprite, pos);
    sfSprite_setTexture(game->settings->esc_sprite,
            game->settings->esc_texture, sfTrue);
    sfSprite_setPosition(game->settings->esc_sprite, pos_esc);
    return 0;
}

int display_settings(game_t *game)
{
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale_esc = {0.5, 0.5};
    sfVector2f pos_text = {350, 120};

    sfSprite_setScale(game->menu_pause->back_sprite, scale);
    sfSprite_setScale(game->settings->esc_sprite, scale_esc);
    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfText_setFont(game->settings->esc_text, game->menu_pause->font);
    sfText_setCharacterSize(game->settings->esc_text, 30);
    sfText_setString(game->settings->esc_text, "In the game menu, you access to the pause menu\n In the settings menu you come back to the game !");
    sfText_setPosition(game->settings->esc_text, pos_text);
    sfRenderWindow_drawSprite(game->utils->window,
        game->menu_pause->back_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
        game->settings->esc_sprite, NULL);
    sfRenderWindow_drawText(game->utils->window,
        game->settings->esc_text, NULL);

}