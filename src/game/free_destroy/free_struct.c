/*
** EPITECH PROJECT, 2020
** free
** File description:
** free
*/

#include "my.h"

int destroy_utils(game_t *game, display_t *display)
{
    if (!game)
        return 84;
    sfFont_destroy(game->menu_pause->font);
    sfText_destroy(game->menu_pause->pause_text);
    sfClock_destroy(display->clock);
}

int destroy_sprite(game_t *game, menu_t *screen, display_t *display)
{
    if (!game || !screen || !display)
        return 84;
    sfSprite_destroy(game->menu_pause->back_sprite);
    sfSprite_destroy(game->menu_pause->main_sprite);
    sfSprite_destroy(game->menu_pause->play_sprite);
    sfSprite_destroy(game->menu_pause->quit_sprite);
    sfSprite_destroy(screen->play_sprite);
    sfSprite_destroy(screen->quit_sprite);
    sfSprite_destroy(display->sprite);
    sfSprite_destroy(game->build_menu->blank_sprite);
    sfSprite_destroy(game->build_menu->build_sprite);
    sfSprite_destroy(game->build_menu->tower1_icon);
    sfSprite_destroy(game->build_menu->tower2_icon);
    sfSprite_destroy(game->build_menu->tower3_icon);

}

int destroy_texture(game_t *game, menu_t *screen, display_t *display)
{
    if (!game || !screen || !display)
        return 84;
    sfTexture_destroy(game->settings->highlight);
    sfTexture_destroy(game->menu_pause->play_texture_highlight);
    sfTexture_destroy(game->menu_pause->quit_texture_highlight);
    sfTexture_destroy(game->menu_pause->main_texture_highlight);
    sfTexture_destroy(game->menu_pause->main_texture);
    sfTexture_destroy(game->menu_pause->back_texture);
    sfTexture_destroy(game->menu_pause->play_texture);
    sfTexture_destroy(game->menu_pause->quit_texture);
    sfTexture_destroy(screen->play_texture);
    sfTexture_destroy(screen->play_texture_highlight);
    sfTexture_destroy(screen->quit_texture_highlight);
    sfTexture_destroy(display->texture);
    sfTexture_destroy(game->build_menu->blank_texture);
    sfTexture_destroy(game->build_menu->build_texture);
    sfTexture_destroy(game->build_menu->tower1_texture);
    sfTexture_destroy(game->build_menu->tower2_texture);
    sfTexture_destroy(game->build_menu->tower3_texture);
}

int free_map(game_t *game)
{
    free(game->utils);
    free(game->display);
    free(game->screen);
    free(game->menu_pause);
    free(game->terrain);
    free(game->enemies_one);
    free(game->enemies_two);
    free(game->enemies_three);
    free(game->castle);
    free(game->settings);
    free(game->towers);
    free(game->money);
    free(game->build_menu);
    return 0;
}
int check_malloc_game(game_t *game)
{
    if (!game)
        return 84;
    if (!game->utils || !game->display || !game->screen || !game->menu_pause
    || !game->terrain || !game->enemies_one || !game->enemies_two 
    || !game->enemies_three || !game->castle || !game->settings || !game->towers
    || !game->money || !game->build_menu) {
        free_map(game);
        return 84;
    }
    return 0;
}