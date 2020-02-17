/*
** EPITECH PROJECT, 2020
** text_pause
** File description:
** text_pause
*/

#include "my.h"

void init_text(game_t *game)
{
    sfVector2f pos = {520, 150};

    game->menu_pause->font = sfFont_createFromFile("./utils/font/horrendo.ttf");
    game->menu_pause->pause_text = sfText_create();
    sfText_setFont(game->menu_pause->pause_text, game->menu_pause->font);
    sfText_setCharacterSize(game->menu_pause->pause_text, 60);
    sfText_setString(game->menu_pause->pause_text, "PAUSE");
    sfText_setPosition(game->menu_pause->pause_text, pos);
}