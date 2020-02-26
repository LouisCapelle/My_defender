/*
** EPITECH PROJECT, 2020
** settings
** File description:
** settings
*/

#include "my.h"

void init_settings(game_t *game)
{
    sfVector2f pos = {1100, 20};
    sfVector2f scale = {0.3, 0.3};
    sfVector2f pos_esc = {200, 100};

    game->settings->sprite = sfSprite_create();
    game->settings->texture = sfTexture_createFromFile
            ("utils/imgs/settings.png", NULL);
    game->settings->esc_sprite = sfSprite_create();
    game->settings->font = sfFont_createFromFile("./utils/font/arial.ttf");
    game->settings->esc_texture = sfTexture_createFromFile
            ("utils/imgs/esc.jpeg", NULL);
    game->settings->esc_text = sfText_create();
    game->settings->esc_text_two = sfText_create();
    sfSprite_setScale(game->settings->sprite, scale);
    sfSprite_setTexture(game->settings->sprite,
            game->settings->texture, sfTrue);
    sfSprite_setPosition(game->settings->sprite, pos);
    sfSprite_setTexture(game->settings->esc_sprite,
            game->settings->esc_texture, sfTrue);
    sfSprite_setPosition(game->settings->esc_sprite, pos_esc);
    init_sound_settings(game);
}

int display_settings(game_t *game)
{
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale_esc = {0.5, 0.5};

    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfSprite_setScale(game->menu_pause->back_sprite, scale);
    sfSprite_setScale(game->settings->esc_sprite, scale_esc);
    sfText_setFont(game->settings->esc_text, game->settings->font);
    sfText_setFont(game->settings->esc_text_two, game->settings->font);
    sfText_setString(game->settings->esc_text,
        "In the game menu, you can access to the pause menu !\n");
    sfText_setString(game->settings->esc_text_two,
        "In the settings menu you can come back to the game !");
    display_settings_menu(game);
    display_sound_settings(game);
    return 0;
}

int display_settings_menu(game_t *game)
{
    sfVector2f pos_text = {350, 110};
    sfVector2f pos_two = {350, 160};
    sfText_setCharacterSize(game->settings->esc_text, 25);
    sfText_setCharacterSize(game->settings->esc_text_two, 25);
    sfText_setPosition(game->settings->esc_text, pos_text);
    sfText_setPosition(game->settings->esc_text_two, pos_two);
    sfRenderWindow_drawSprite(game->utils->window,
        game->menu_pause->back_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
        game->settings->esc_sprite, NULL);
    sfRenderWindow_drawText(game->utils->window,
        game->settings->esc_text, NULL);
    sfRenderWindow_drawText(game->utils->window,
        game->settings->esc_text_two, NULL);
    return 0;
}