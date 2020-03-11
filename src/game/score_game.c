/*
** EPITECH PROJECT, 2020
** score
** File description:
** score
*/

#include "my.h"

int display_score(game_t *game)
{
    if (!game)
        return 84;
    sfRenderWindow_drawText(game->utils->window, game->score_game->live_text, NULL);
    sfRenderWindow_drawText(game->utils->window, game->score_game->live_int, NULL);
    return 0;
}

int score(game_t *game)
{
    if (!game || init_score_game(game) == 84)
        return 84;
    game->score_game->score += 1;
    update_live_castle(game);
    return 0;
}

int update_score(game_t *game)
{
    char *int_text = my_itoa(game->score_game->score);
    sfText_setString(game->score_game->live_int, int_text);
}

int init_score_game(game_t *game)
{
    sfVector2f pos = {30, 650};
    char *int_text = NULL;

    if (!game)
        return 84;
    int_text = my_itoa(game->score_game->score);
    game->score_game->live_int = sfText_create();
    game->score_game->live_text = sfText_create();
    sfText_setPosition(game->score_game->live_text, pos);
    sfText_setFont(game->score_game->live_text, game->menu_pause->font);
    sfText_setCharacterSize(game->score_game->live_text, 40);
    sfText_setString(game->score_game->live_text, "Score :");
    pos.x = 170;
    pos.y = 655;
    sfText_setPosition(game->score_game->live_int, pos);
    sfText_setFont(game->score_game->live_int, game->menu_pause->font);
    sfText_setCharacterSize(game->score_game->live_int, 40);
    sfText_setString(game->score_game->live_int, int_text);
    return 0;
}