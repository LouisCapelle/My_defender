/*
** EPITECH PROJECT, 2020
** live
** File description:
** live
*/

#include "my.h"

int display_text_castle(game_t *game)
{
    if (!game)
        return 84;
    sfRenderWindow_drawText(game->utils->window, game->castle->live_text, NULL);
    sfRenderWindow_drawText(game->utils->window, game->castle->live_int, NULL);
    return 0;
}

int live_castle(game_t *game)
{
    if (!game || init_live_castle(game) == 84)
        return 84;
    if (sfSprite_getPosition(game->enemies_three->sprite).x >= 985) {
        game->castle->alive = game->castle->alive - 10;
    }
    update_live_castle(game);
    if (sfSprite_getPosition(game->enemies_one->sprite).x >= 985) {
        game->castle->alive = game->castle->alive - 10;
    }
    update_live_castle(game);
    if (live_castle_next(game) == 84)
        return 84;
    return 0;
}

int live_castle_next(game_t *game)
{
    if (!game)
        return 84;
    if (sfSprite_getPosition(game->enemies_two->sprite).x >= 985) {
        game->castle->alive = game->castle->alive - 10;
    }
    update_live_castle(game);
    if (game->castle->alive == 0) {
        game->is_alive = 0;
        game->in_menu = 1;
        game->castle->alive = 50;
    }
    update_live_castle(game);
    return 0;
}

int update_live_castle(game_t *game)
{
    char *int_text = my_itoa(game->castle->alive);
    sfText_setString(game->castle->live_int, int_text);
}

int init_live_castle(game_t *game)
{
    sfVector2f pos = {500, 650};
    char *int_text = NULL;

    if (!game)
        return 84;
    int_text = my_itoa(game->castle->alive);
    game->castle->live_int = sfText_create();
    game->castle->live_text = sfText_create();
    sfText_setPosition(game->castle->live_text, pos);
    sfText_setFont(game->castle->live_text, game->menu_pause->font);
    sfText_setCharacterSize(game->castle->live_text, 40);
    sfText_setString(game->castle->live_text, "Life :");
    pos.x = 610;
    pos.y = 655;
    sfText_setPosition(game->castle->live_int, pos);
    sfText_setFont(game->castle->live_int, game->menu_pause->font);
    sfText_setCharacterSize(game->castle->live_int, 40);
    sfText_setString(game->castle->live_int, int_text);
    return 0;
}