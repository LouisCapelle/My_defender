/*
** EPITECH PROJECT, 2020
** text_pause
** File description:
** text_pause
*/

#include "my.h"

int init_text(game_t *game)
{
    sfVector2f pos = {470, 150};

    if (!game)
        return 84;
    game->menu_pause->font = sfFont_createFromFile("./utils/font/horrendo.ttf");
    game->menu_pause->pause_text = sfText_create();
    if (!game->menu_pause->font || !game->menu_pause->pause_text)
        return 84;
    sfText_setFont(game->menu_pause->pause_text, game->menu_pause->font);
    sfText_setCharacterSize(game->menu_pause->pause_text, 90);
    sfText_setString(game->menu_pause->pause_text, "PAUSE");
    sfText_setPosition(game->menu_pause->pause_text, pos);
    return 0;
}