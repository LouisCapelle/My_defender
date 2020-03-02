/*
** EPITECH PROJECT, 2020
** init book
** File description:
** init_book
*/

#include "my.h"

int init_build_icons(game_t *game)
{
    sfVector2f pos_1 = {500, 500};
    sfVector2f pos_2 = {200, 200};
    sfVector2f pos_3 = {3, 3};
    sfVector2f scale = {0.4, 0.4};

    sfSprite_setPosition(game->build_menu->tower1_icon, pos_1);
    sfSprite_setPosition(game->build_menu->tower2_icon, pos_2);
    sfSprite_setPosition(game->build_menu->tower3_icon, pos_3);
    sfSprite_setScale(game->build_menu->tower1_icon, scale);
    sfSprite_setScale(game->build_menu->tower2_icon, scale);
    sfSprite_setScale(game->build_menu->tower3_icon, scale);
}

int create_icons(game_t *game)
{
    game->build_menu->blank_sprite = sfSprite_create();
    game->build_menu->build_sprite = sfSprite_create();
    game->build_menu->tower1_icon = sfSprite_create();
    game->build_menu->tower2_icon = sfSprite_create();
    game->build_menu->tower3_icon = sfSprite_create();
}

int set_textures(game_t *game)
{
    game->build_menu->blank_texture = sfTexture_createFromFile
                                    ("./utils/imgs/blank.png", NULL);
    game->build_menu->build_texture = sfTexture_createFromFile
                                    ("./utils/imgs/book.png", NULL);
    game->build_menu->tower1_texture = sfTexture_createFromFile
                                    ("./utils/imgs/tower.png", NULL);
    game->build_menu->tower2_texture = sfTexture_createFromFile
                                    ("./utils/imgs/tower2.png", NULL);
    game->build_menu->tower3_texture = sfTexture_createFromFile
                                    ("./utils/imgs/tower3.png", NULL);
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
}

int init_build_menu(game_t *game)
{
    sfVector2f pos = {1000, 30};
    sfVector2f pos_blank = {310, 150};
    sfVector2f scale = {0.2, 0.2};
    sfVector2f scale_blank = {0.4, 0.4};

    create_icons(game);
    set_textures(game);
    sfSprite_setPosition(game->build_menu->build_sprite, pos);
    sfSprite_setPosition(game->build_menu->blank_sprite, pos_blank);
    sfSprite_setScale(game->build_menu->build_sprite, scale);
    sfSprite_setScale(game->build_menu->blank_sprite, scale_blank);
    init_build_icons(game);
}