/*
** EPITECH PROJECT, 2020
** init book
** File description:
** init_book
*/

#include "my.h"

int init_build_menu(game_t *game)
{
    sfVector2f pos = {1000, 30};
    sfVector2f scale = {0.2, 0.2};

    game->build_menu->blank_sprite = sfSprite_create();
    game->build_menu->build_sprite = sfSprite_create();
    game->build_menu->blank_texture = sfTexture_createFromFile
                                    ("./utils/imgs/blank.png", NULL);
    game->build_menu->build_texture = sfTexture_createFromFile
                                    ("./utils/imgs/book.png", NULL);
    sfSprite_setTexture(game->build_menu->build_sprite,
                            game->build_menu->build_texture, sfTrue);
    sfSprite_setPosition(game->build_menu->build_sprite, pos);
    sfSprite_setScale(game->build_menu->build_sprite, scale);
}