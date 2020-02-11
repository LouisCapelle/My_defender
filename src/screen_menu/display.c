/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_background(game_t *game)
{
    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfSprite_setTexture(game->display->sprite, game->display->texture, sfFalse);
    sfSprite_setPosition(game->display->sprite, game->display->pos);
    sfRenderWindow_drawSprite(game->utils->window, game->display->sprite, NULL);
    display_highlight_play(game);
    display_highlight_quit(game);
    display_menu(game);
    return 0;
}

int display_menu(game_t *game)
{
    sfVector2f scale_play;
    sfVector2f scale_quit;
    scale_play.x = 0.6;
    scale_play.y = 0.9;
    scale_quit.x = 0.73;
    scale_quit.y = 0.73;
    game->screen->pos_play.x = 480;
    game->screen->pos_play.y = 470;
    game->screen->pos_quit.x = 470;
    game->screen->pos_quit.y = 570;
    sfSprite_setScale(game->screen->play_sprite, scale_play);
    sfSprite_setScale(game->screen->quit_sprite, scale_quit);
    sfSprite_setPosition(game->screen->play_sprite, game->screen->pos_play);
    sfRenderWindow_drawSprite(game->utils->window,
    game->screen->play_sprite, NULL);
    sfSprite_setPosition(game->screen->quit_sprite, game->screen->pos_quit);
    sfRenderWindow_drawSprite(game->utils->window,
    game->screen->quit_sprite, NULL);
}