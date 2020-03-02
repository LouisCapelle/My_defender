/*
** EPITECH PROJECT, 2020
** init book
** File description:
** init_book
*/

#include "my.h"

int init_build_icons(game_t *game)
{
    sfVector2f pos_1 = {1, 1};
    sfVector2f pos_2 = {2, 2};
    sfVector2f pos_3 = {3, 3};
}

int init_build_menu(game_t *game)
{
    sfVector2f pos = {1000, 30};
    sfVector2f pos_blank = {310, 150};
    sfVector2f scale = {0.2, 0.2};
    sfVector2f scale_blank = {0.4, 0.4};

    game->build_menu->blank_sprite = sfSprite_create();
    game->build_menu->build_sprite = sfSprite_create();
    game->build_menu->blank_texture = sfTexture_createFromFile
                                    ("./utils/imgs/blank.png", NULL);
    game->build_menu->build_texture = sfTexture_createFromFile
                                    ("./utils/imgs/book.png", NULL);
    sfSprite_setTexture(game->build_menu->build_sprite,
                            game->build_menu->build_texture, sfTrue);
    sfSprite_setTexture(game->build_menu->blank_sprite,
                        game->build_menu->blank_texture, sfTrue);
    sfSprite_setPosition(game->build_menu->build_sprite, pos);
    sfSprite_setPosition(game->build_menu->blank_sprite, pos_blank);
    sfSprite_setScale(game->build_menu->build_sprite, scale);
    sfSprite_setScale(game->build_menu->blank_sprite, scale_blank);
    init_build_icons(game);
}