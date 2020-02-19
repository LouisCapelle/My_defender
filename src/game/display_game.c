/*
** EPITECH PROJECT, 2020
** display_game
** File description:
** display_game
*/

#include "my.h"

void init_terrain(game_t *game)
{
    init_towers(game);
    game->terrain->clock = sfClock_create();
    game->terrain->background_sprite = sfSprite_create();
    game->terrain->background_texture = sfTexture_createFromFile
                                    ("./utils/imgs/terrain.jpg", NULL);
    sfSprite_setTexture(game->terrain->background_sprite,
                        game->terrain->background_texture, sfTrue);
}

int init_enemys(game_t *game, sfClock *clock)
{
    sfVector2f pos  = {0, 470};
    sfVector2f scale = {0.2, 0.2};

    game->enemys->sprite = sfSprite_create();
    game->enemys->texture = sfTexture_createFromFile
    ("utils/imgs/Square.png", NULL);
    sfSprite_setScale(game->enemys->sprite, scale);
    sfSprite_setTexture(game->enemys->sprite, game->enemys->texture, sfTrue);
    game->enemys->pos = pos;
    return 0;
}

void display_game(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->terrain->background_sprite, NULL);
    rotate_tower(game);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->terrain->tower1_sprite, NULL);
    move_enemys(game, game->display->clock);
    init_castle(game);
}