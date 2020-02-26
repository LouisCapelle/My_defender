/*
** EPITECH PROJECT, 2020
** init pause
** File description:
** init_pause
*/

#include "my.h"

int set_position(game_t *game)
{
    sfVector2f pos_play = {435, 430};
    sfVector2f pos_main = {435, 580};
    sfVector2f pos_quit = {500, 500};
    sfVector2f scale = {1.5, 1.5};
    sfVector2f quit_scale = {1, 1};
    sfVector2f scale_button = {0.8, 0.8};

    sfSprite_setScale(game->menu_pause->back_sprite, scale);
    sfSprite_setScale(game->menu_pause->main_sprite, scale_button);
    sfSprite_setScale(game->menu_pause, quit_scale);
    sfSprite_setPosition(game->menu_pause->main_sprite, pos_main);
    sfSprite_setPosition(game->menu_pause->play_sprite, pos_play);
    sfSprite_setPosition(game->menu_pause->quit_sprite, pos_quit);
}

int init_pos_2(game_t *game)
{
    game->menu_pause->main_texture = sfTexture_createFromFile
                            ("./utils/imgs/main_menu.png", NULL);
    game->menu_pause->back_texture = sfTexture_createFromFile
                            ("./utils/imgs/pause.png", NULL);
    game->menu_pause->back_sprite = sfSprite_create();
    game->menu_pause->main_sprite = sfSprite_create();
    game->menu_pause->play_sprite = sfSprite_create();
    game->menu_pause->quit_sprite = sfSprite_create();
}

int init_pause_menu(game_t *game)
{
    set_position(game);
    init_pos_2(game);
    sfSprite_setTexture(game->menu_pause->play_sprite,
                        game->screen->play_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->main_sprite,
                        game->menu_pause->main_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->back_sprite,
                        game->menu_pause->back_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->quit_sprite,
                        game->screen->quit_texture, sfTrue);
    init_text(game);
    return 0;
}