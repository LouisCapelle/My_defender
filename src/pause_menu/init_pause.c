/*
** EPITECH PROJECT, 2020
** init pause
** File description:
** init_pause
*/

#include "my.h"

int set_position(game_t *game)
{
    sfVector2f pos_play = {500, 330};
    sfVector2f pos_main = {500, 445};
    sfVector2f pos_quit = {500, 560};
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale_button = {0.73, 0.73};

    if (!game)
        return 84;
    sfSprite_setScale(game->menu_pause->back_sprite, scale);
    sfSprite_setScale(game->menu_pause->main_sprite, scale_button);
    sfSprite_setScale(game->menu_pause->quit_sprite, scale_button);
    sfSprite_setScale(game->menu_pause->play_sprite, scale_button);
    sfSprite_setPosition(game->menu_pause->main_sprite, pos_main);
    sfSprite_setPosition(game->menu_pause->play_sprite, pos_play);
    sfSprite_setPosition(game->menu_pause->quit_sprite, pos_quit);
    return 0;
}

int init_highlight(game_t *game)
{
    if (!game)
        return 84;
    game->menu_pause->play_texture_highlight = sfTexture_createFromFile
                                    ("./utils/imgs/start_highlight.png", NULL);
    game->menu_pause->quit_texture_highlight = sfTexture_createFromFile
                                    ("./utils/imgs/quit_highlight.png", NULL);
    game->menu_pause->main_texture_highlight = sfTexture_createFromFile
                            ("./utils/imgs/menu_button_highlight.png", NULL);
    if (!game->menu_pause->play_texture_highlight
    || !game->menu_pause->quit_texture_highlight
    || !game->menu_pause->main_texture_highlight)
        return 84;
    return 0;
}

int init_pos_2(game_t *game)
{
    if (!game || init_highlight(game) == 84)
        return 84;
    game->menu_pause->main_texture = sfTexture_createFromFile
                            ("./utils/imgs/menu_button.png", NULL);
    game->menu_pause->back_texture = sfTexture_createFromFile
                            ("./utils/imgs/pause.png", NULL);
    game->menu_pause->play_texture = sfTexture_createFromFile
                            ("./utils/imgs/start.png", NULL);
    game->menu_pause->quit_texture = sfTexture_createFromFile
                            ("./utils/imgs/quit.png", NULL);
    game->menu_pause->back_sprite = sfSprite_create();
    game->menu_pause->main_sprite = sfSprite_create();
    game->menu_pause->play_sprite = sfSprite_create();
    game->menu_pause->quit_sprite = sfSprite_create();
    if (!game->menu_pause->main_texture || !game->menu_pause->back_texture
    || !game->menu_pause->play_texture || !game->menu_pause->quit_texture
    || !game->menu_pause->back_sprite || !game->menu_pause->main_sprite
    || !game->menu_pause->play_sprite || !game->menu_pause->quit_sprite)
        return 84;
    return 0;
}

int init_pause_menu(game_t *game)
{
    if (!game || init_pos_2(game) == 84 || set_position(game) == 84)
        return 84;
    sfSprite_setTexture(game->menu_pause->play_sprite,
                        game->menu_pause->play_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->main_sprite,
                        game->menu_pause->main_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->back_sprite,
                        game->menu_pause->back_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->quit_sprite,
                        game->menu_pause->quit_texture, sfTrue);
    if (init_text(game) == 84)
        return 84;
    return 0;
}