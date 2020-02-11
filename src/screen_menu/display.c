/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_background(utils_t *utils, display_t *display, menu_t *screen)
{
    sfRenderWindow_clear(utils->window, sfBlack);
    sfSprite_setTexture(display->sprite, display->texture, sfFalse);
    sfSprite_setPosition(display->sprite, display->pos);
    sfRenderWindow_drawSprite(utils->window, display->sprite, NULL);
    display_highlight_play(utils->window, screen, display);
    display_highlight_quit(utils->window, screen, display);
    display_menu(utils, screen);
    return 0;
}

int display_menu(utils_t *utils, menu_t *screen)
{
    sfVector2f scale_play;
    sfVector2f scale_quit;
    scale_play.x = 0.6;
    scale_play.y = 0.9;
    scale_quit.x = 0.73;
    scale_quit.y = 0.73;
    screen->pos_play.x = 480;
    screen->pos_play.y = 470;
    screen->pos_quit.x = 470;
    screen->pos_quit.y = 570;
    sfSprite_setScale(screen->play_sprite, scale_play);
    sfSprite_setScale(screen->quit_sprite, scale_quit);
    sfSprite_setPosition(screen->play_sprite, screen->pos_play);
    sfRenderWindow_drawSprite(utils->window, screen->play_sprite, NULL);
    sfSprite_setPosition(screen->quit_sprite, screen->pos_quit);
    sfRenderWindow_drawSprite(utils->window, screen->quit_sprite, NULL);
}