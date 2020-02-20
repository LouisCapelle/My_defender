/*
** EPITECH PROJECT, 2020
** sound
** File description:
** sound
*/

#include "my.h"

int music_game(game_t *game)
{
    game->utils->song = sfMusic_createFromFile("utils/music/music.ogg");
    if (!game->utils->song)
        return 84;
    sfMusic_setVolume(game->utils->song, 40);
    sfMusic_play(game->utils->song);
    sfMusic_setLoop(game->utils->song, sfTrue);
    return 0;
}