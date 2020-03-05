/*
** EPITECH PROJECT, 2020
** init book
** File description:
** init_book
*/

#include "my.h"

int init_build_icons(game_t *game)
{
    sfVector2f pos_1 = {350, 170};
    sfVector2f pos_2 = {350, 305};
    sfVector2f pos_3 = {350, 420};
    sfVector2f scale = {0.3, 0.3};

    if (!game)
        return 84;
    sfSprite_setPosition(game->build_menu->tower1_icon, pos_1);
    sfSprite_setPosition(game->build_menu->tower2_icon, pos_2);
    sfSprite_setPosition(game->build_menu->tower3_icon, pos_3);
    sfSprite_setScale(game->build_menu->tower1_icon, scale);
    sfSprite_setScale(game->build_menu->tower2_icon, scale);
    sfSprite_setScale(game->build_menu->tower3_icon, scale);
    return 0;
}

int create_icons(game_t *game)
{
    if (!game)
        return 84;
    game->build_menu->blank_sprite = sfSprite_create();
    game->build_menu->build_sprite = sfSprite_create();
    game->build_menu->tower1_icon = sfSprite_create();
    game->build_menu->tower2_icon = sfSprite_create();
    game->build_menu->tower3_icon = sfSprite_create();
    if (!game->build_menu->blank_sprite || !game->build_menu->build_sprite
    || !game->build_menu->tower1_icon || !game->build_menu->tower2_icon
    || !game->build_menu->tower3_icon)
        return 84;
    return 0;
}

int set_textures(game_t *game)
{
    if (!game)
        return 84;
    game->build_menu->blank_texture = sfTexture_createFromFile
                                    ("./utils/imgs/blank.jpg", NULL);
    game->build_menu->build_texture = sfTexture_createFromFile
                                    ("./utils/imgs/book.png", NULL);
    game->build_menu->tower1_texture = sfTexture_createFromFile
                                    ("./utils/imgs/tower.png", NULL);
    game->build_menu->tower2_texture = sfTexture_createFromFile
                                    ("./utils/imgs/tower2.png", NULL);
    game->build_menu->tower3_texture = sfTexture_createFromFile
                                    ("./utils/imgs/tower3.png", NULL);
    if (!game->build_menu->blank_texture || !game->build_menu->build_texture
    || !game->build_menu->tower1_texture || !game->build_menu->tower2_texture
    || !game->build_menu->tower3_texture || set_texture_next(game) == 84)
        return 84;
    return 0;
}

int set_texture_next(game_t *game)
{
    if (!game)
        return 84;
    sfSprite_setTexture(game->build_menu->tower1_icon,
                            game->build_menu->tower1_texture, sfTrue);
    sfSprite_setTexture(game->build_menu->tower2_icon,
                            game->build_menu->tower2_texture, sfTrue);
    sfSprite_setTexture(game->build_menu->tower3_icon,
                            game->build_menu->tower3_texture, sfTrue);
    sfSprite_setTexture(game->build_menu->build_sprite,
                            game->build_menu->build_texture, sfTrue);
    sfSprite_setTexture(game->build_menu->blank_sprite,
                        game->build_menu->blank_texture, sfTrue);
    return 0;
}

int init_build_menu(game_t *game)
{
    sfVector2f pos = {1000, 30};
    sfVector2f pos_blank = {310, 150};
    sfVector2f scale = {0.2, 0.2};
    sfVector2f scale_blank = {0.4, 0.4};

    if (create_icons(game) == 84
    || set_textures(game) == 84
    || init_text_build(game) == 84)
        return 84;
    sfSprite_setPosition(game->build_menu->build_sprite, pos);
    sfSprite_setPosition(game->build_menu->blank_sprite, pos_blank);
    sfSprite_setScale(game->build_menu->build_sprite, scale);
    sfSprite_setScale(game->build_menu->blank_sprite, scale_blank);
    if (init_build_icons(game) == 84)
        return 84;
    return 0;
}