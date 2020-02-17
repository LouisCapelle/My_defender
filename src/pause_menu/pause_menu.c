/*
** EPITECH PROJECT, 2020
** pause
** File description:
** pause
*/

#include "my.h"

int init_pause_menu(game_t *game)
{
    game->menu_pause->play_texture = sfTexture_createFromFile
                            ("./utils/imgs/play_button.jpg", NULL);
    game->menu_pause->main_texture = sfTexture_createFromFile
                            ("./utils/imgs/main_menu.png", NULL);
    game->menu_pause->main_sprite = sfSprite_create();
    game->menu_pause->play_sprite = sfSprite_create();
    sfSprite_setTexture(game->menu_pause->play_sprite,
                        game->menu_pause->play_texture, sfTrue);
    sfSprite_setTexture(game->menu_pause->main_sprite,
                        game->menu_pause->main_texture, sfTrue);
    init_text(game);
    return 0;
}

int pause_menu(game_t *game)
{
    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window, game->display->sprite, NULL);
    sfSprite_setPosition(game->menu_pause->main_sprite, game->screen->pos_quit);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->main_sprite, NULL);
    sfSprite_setPosition(game->menu_pause->play_sprite, game->screen->pos_play);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->menu_pause->play_sprite, NULL);
    sfRenderWindow_drawText(game->utils->window,
                            game->menu_pause->pause_text, NULL);
    return 0;
}