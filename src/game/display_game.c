/*
** EPITECH PROJECT, 2020
** display_game
** File description:
** display_game
*/

#include "my.h"

void init_towers(game_t *game)
{
    sfVector2f pos_tower1 = {330, 540};
    sfVector2f origin = {64, 64};

    game->terrain->tower1_sprite = sfSprite_create();
    game->terrain->tower1_texture = sfTexture_createFromFile
                                ("./utils/imgs/tower1.png", NULL);
    sfSprite_setTexture(game->terrain->tower1_sprite,
                        game->terrain->tower1_texture, sfTrue);
    sfSprite_setPosition(game->terrain->tower1_sprite, pos_tower1);
    sfSprite_setOrigin(game->terrain->tower1_sprite, origin);
}

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

void rotate_tower(game_t *game)
{
    sfTime time;
    float seconds = 0;
    float position = sfSprite_getRotation(game->terrain->tower1_sprite);

    time = sfClock_getElapsedTime(game->terrain->clock);
    seconds = time.microseconds / 100000.0;
    if (seconds > 4.5) {
        if (position >= 3) {
            sfSprite_rotate(game->terrain->tower1_sprite, position - 0.1);
        }else if (position >= -25) {
            sfSprite_rotate(game->terrain->tower1_sprite, position + 0.1);
        }
        sfClock_restart(game->terrain->clock);
    }
}

void display_game(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->terrain->background_sprite, NULL);
    rotate_tower(game);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->terrain->tower1_sprite, NULL);
}