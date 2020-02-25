/*
** EPITECH PROJECT, 2020
** money
** File description:
** money
*/

#include "my.h"

int update_money(game_t *game)
{
    char *int_text = my_itoa(game->money->in_bank);
    sfText_setString(game->money->bank_int, int_text);
}

int init_money(game_t *game)
{
    sfVector2f pos = {750, 650};
    char *int_text = NULL;

    game->money->in_bank = 10000;
    int_text = my_itoa(game->money->in_bank);
    game->money->bank_int = sfText_create();
    game->money->bank_text = sfText_create();
    sfText_setPosition(game->money->bank_text, pos);
    sfText_setFont(game->money->bank_text, game->menu_pause->font);
    sfText_setCharacterSize(game->money->bank_text, 40);
    sfText_setString(game->money->bank_text, "In bank :");
    pos.x = 930;
    pos.y = 655;
    sfText_setPosition(game->money->bank_int, pos);
    sfText_setFont(game->money->bank_int, game->menu_pause->font);
    sfText_setCharacterSize(game->money->bank_int, 40);
    sfText_setString(game->money->bank_int, int_text);
}