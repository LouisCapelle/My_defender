/*
** EPITECH PROJECT, 2020
** pause
** File description:
** pause
*/

#include "my.h"

int set_position(game_t *game)
{
    sfVector2f pos_play = {435, 450};
    sfVector2f pos_main = {435, 550};
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale_button = {0.855, 0.855};

    sfSprite_setScale(game->menu_pause->back_sprite, scale);
    sfSprite_setScale(game->menu_pause->main_sprite, scale_button);
    sfSprite_setPosition(game->menu_pause->main_sprite, pos_main);
    sfSprite_setPosition(game->menu_pause->play_sprite, pos_play);
}

int init_pause_menu(game_t *game)
{
    game->menu_pause->play_texture = sfTexture_createFromFile
                            ("./utils/imgs/play_button.jpg", NULL);
    game->menu_pause->main_texture = sfTexture_createFromFile
                            ("./utils/imgs/main_menu.png", NULL);
    game->menu_pause->back_texture = sfTexture_createFromFile
                            ("./utils/imgs/pause.png", NULL);
    game->menu_pause->back_sprite = sfSprite_create();
    game->menu_pause->main_sprite = sfSprite_create();
    game->menu_pause->play_sprite = sfSprite_create();
    sfSprite_setTexture(game->menu_pause->play_sprite,
                        game->menu_pause->play_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->main_sprite,
                        game->menu_pause->main_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->back_sprite,
                        game->menu_pause->back_texture, sfTrue);
    init_text(game);
    return 0;
}

int pause_menu(game_t *game)
{
    sfRenderWindow_clear(game->utils->window, sfBlack);
    set_position(game);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->back_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->main_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->play_sprite, NULL);
    sfRenderWindow_drawText(game->utils->window,
                            game->menu_pause->pause_text, NULL);
    return 0;
}