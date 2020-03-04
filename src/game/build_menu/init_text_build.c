/*
** EPITECH PROJECT, 2020
** init text
** File description:
** init_text_build
*/

#include "my.h"

int init_text_pos(game_t *game)
{
    sfVector2f pos_1 = {430, 230};
    sfVector2f pos_2 = {430, 350};
    sfVector2f pos_3 = {430, 470};

    sfText_setPosition(game->build_menu->text_tower1, pos_1);
    sfText_setPosition(game->build_menu->text_tower2, pos_2);
    sfText_setPosition(game->build_menu->text_tower3, pos_3);
}

int init_text_build(game_t *game)
{
    game->build_menu->text_tower1 = sfText_create();
    game->build_menu->text_tower2 = sfText_create();
    game->build_menu->text_tower3 = sfText_create();
    sfText_setFont(game->build_menu->text_tower1, game->menu_pause->font);
    sfText_setFont(game->build_menu->text_tower2, game->menu_pause->font);
    sfText_setFont(game->build_menu->text_tower3, game->menu_pause->font);
    sfText_setString(game->build_menu->text_tower1, "bite");
    sfText_setString(game->build_menu->text_tower2, "bite");
    sfText_setString(game->build_menu->text_tower3, "bite");
    sfText_setCharacterSize(game->build_menu->text_tower1, 20);
    sfText_setCharacterSize(game->build_menu->text_tower2, 20);
    sfText_setCharacterSize(game->build_menu->text_tower3, 20);
    sfText_setColor(game->build_menu->text_tower1, sfBlack);
    sfText_setColor(game->build_menu->text_tower2, sfBlack);
    sfText_setColor(game->build_menu->text_tower3, sfBlack);
    init_text_pos(game);
}