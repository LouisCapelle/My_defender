/*
** EPITECH PROJECT, 2020
** free
** File description:
** free
*/

#include "my.h"

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