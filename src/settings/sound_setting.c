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
    sfRenderWindow_drawText(game->utils->window,
                            game->settings->sound_text, NULL);
    printf("ma bite en ski");
}

int get_click(game_t *game, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->utils->window);

    sfText_setString(game->settings->sound_text,
                my_itoa(sfMusic_getVolume(game->utils->song)));
    if (event.type == sfEvtMouseButtonPressed && game->in_settings == 1
        && (mouse.x >= 407 && mouse.x <= 443
        && mouse.y >= 510 && mouse.y <= 543)) {
        sfMusic_setVolume(game->utils->song,
                            sfMusic_getVolume(game->utils->song) - 10);
    }
    if (event.type == sfEvtMouseButtonPressed && game->in_settings == 1
        && (mouse.x >= 706 && mouse.x <= 733
        && mouse.y >= 516 && mouse.y <= 539)) {
        sfMusic_setVolume(game->utils->song,
                            sfMusic_getVolume(game->utils->song) + 10);
    }
}

int init_text_sound(game_t * game)
{
    sfVector2f pos = {542, 500};
    game->settings->sound_text = sfText_create();
    sfText_setFont(game->settings->sound_text, game->menu_pause->font);
    sfText_setCharacterSize(game->settings->sound_text, 40);
    sfText_setPosition(game->settings->sound_text, pos);
    sfText_setString(game->settings->sound_text,
                my_itoa(sfMusic_getVolume(game->utils->song)));
}

int init_sound_settings(game_t *game)
{
    sfVector2f pos1 = {700, 507};
    sfVector2f pos2 = {400, 500};
    sfVector2f scale1 = {0.1, 0.1};
    sfVector2f scale2 = {0.07, 0.07};

    init_text_sound(game);
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