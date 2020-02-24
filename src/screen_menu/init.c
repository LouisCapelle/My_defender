/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

sfRenderWindow *init_struct_display(display_t *display, utils_t *utils)
{
    sfVector2f pos = {0, 0};
    sfVector2f offset = {5, 0};

    display->texture = sfTexture_createFromFile("utils/imgs/background.jpg",
                                                                    NULL);
    display->sprite = sfSprite_create();
    display->clock = sfClock_create();
    if (!display->sprite || !display->texture || !display->clock)
        return NULL;
    display->pos = pos;
    display->offset = offset;
    utils->video_mode.width = 1200;
    utils->video_mode.height = 700;
    utils->video_mode.bitsPerPixel = 32;

    utils->window = sfRenderWindow_create(utils->video_mode,
                "MyDefender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(utils->window, 60);
    return (utils->window);
}

int init_screen_menu(utils_t *utils, menu_t *screen)
{
    screen->play_texture = sfTexture_createFromFile
                ("./utils/imgs/start.png", NULL);
    screen->play_texture_highlight = sfTexture_createFromFile
                ("./utils/imgs/start_highlight.png", NULL);
    screen->quit_texture = sfTexture_createFromFile
                ("./utils/imgs/quit.png", NULL);
    screen->quit_texture_highlight = sfTexture_createFromFile
                ("./utils/imgs/quit_highlight.png", NULL);
    if (!screen->play_texture || !screen->quit_texture)
        return 84;
    screen->play_sprite = sfSprite_create();
    screen->quit_sprite = sfSprite_create();
    sfSprite_setTexture(screen->play_sprite, screen->play_texture, sfTrue);
    sfSprite_setTexture(screen->quit_sprite, screen->quit_texture, sfTrue);
    return 0;
}

int init_game(game_t *game)
{
    game->utils = malloc(sizeof(utils_t));
    game->display = malloc(sizeof(display_t));
    game->screen = malloc(sizeof(menu_t));
    game->menu_pause = malloc(sizeof(menu_pause_t));
    game->terrain = malloc(sizeof(terrain_t));
    game->enemies_one = malloc(sizeof(enemies_one_t));
    game->enemies_two = malloc(sizeof(enemies_two_t));
    game->enemies_three = malloc(sizeof(enemies_three_t));
    game->castle = malloc(sizeof(castle_t));
    game->settings = malloc(sizeof(settings_t));
    game->towers = malloc(sizeof(towers_t));
    game->is_alive = 1;
    game->in_menu = 1;
    game->in_pause = 0;
    game->in_settings = 0;
    init_game_two(game);
    return 0;
}

int init_game_two(game_t *game)
{
    game->utils->window = init_struct_display(game->display, game->utils);
    game->settings->highlight = sfTexture_createFromFile
        ("utils/imgs/settings_highlight.png", NULL);
    init_pause_menu(game);
    init_terrain(game);
    init_screen_menu(game->utils, game->screen);
    init_enemies_one(game, game->display->clock);
    init_enemies_two(game, game->display->clock);
    init_enemies_three(game, game->display->clock);
    init_castle(game);
    return 0;
}