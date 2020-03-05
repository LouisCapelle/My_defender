/*
** EPITECH PROJECT, 2020
** display_game
** File description:
** display_game
*/

#include "my.h"

int display_highlight_settings(game_t *game, sfVector2i position)
{
    if (!game)
        return 84;
    if ((position.x >= 1100 && position.x <= 1160
        && game->in_game == 1)
        && (position.y >= 35 && position.y <= 82)) {
        sfSprite_setTexture(game->settings->sprite,
                        game->settings->highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->settings->sprite,
                        game->settings->texture, sfTrue);
    }
    return 0;
}

int init_terrain(game_t *game)
{
    sfVector2f scale = {0.65, 0.65};

    if (!game || !init_towers(game) == 84 || init_tower_icons(game) == 84)
        return 84;
    game->towers->clock = sfClock_create();
    game->terrain->background_sprite = sfSprite_create();
    game->terrain->background_texture = sfTexture_createFromFile
                                    ("./utils/imgs/terrain.png", NULL);
    if (!game->towers->clock || !game->terrain->background_sprite
    || !game->terrain->background_texture)
        return 84;
    sfSprite_setScale(game->terrain->background_sprite, scale);
    sfSprite_setTexture(game->terrain->background_sprite,
                        game->terrain->background_texture, sfTrue);
    return 0;
}

int init_castle(game_t *game)
{
    sfVector2f pos = {1250, 230};
    sfVector2f scale = {0.4, 0.4};
    sfVector2f scale_castle = {1.25, 1.25};
    static int alive = 50;

    if (!game)
        return 84;
    game->castle->alive = alive;
    game->castle->sprite = sfSprite_create();
    game->castle->texture = sfTexture_createFromFile
            ("utils/imgs/castle.png", NULL);
    if (!game->castle->sprite || !game->castle->texture)
        return 84;
    sfSprite_setScale(game->enemies_one->sprite, scale);
    sfSprite_setScale(game->enemies_two->sprite, scale);
    sfSprite_setScale(game->enemies_three->sprite, scale);
    sfSprite_setScale(game->castle->sprite, scale_castle);
    sfSprite_rotate(game->castle->sprite, 90);
    sfSprite_setTexture(game->castle->sprite, game->castle->texture, sfTrue);
    sfSprite_setPosition(game->castle->sprite, pos);
    return 0;
}

void display_text(game_t *game)
{
    sfRenderWindow_drawText(game->utils->window, game->money->bank_text, NULL);
    sfRenderWindow_drawText(game->utils->window, game->money->bank_int, NULL);
}

int display_game(sfRenderWindow *window, game_t *game)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(game->utils->window);

    if (!game)
        return 84;
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->terrain->background_sprite, NULL);
    if (rotate_tower(game) == 84 || display_towers(game) == 84
    || display_highlight_settings(game, position) == 84)
        return 84;
    sfRenderWindow_drawSprite(game->utils->window,
                            game->settings->sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->castle->sprite, NULL);
    if (display_game_next(game) == 84)
        return 84;
    return 0;
}

int display_game_next(game_t *game)
{
    if (!game)
        return 84;
    if (move_enemies_one(game, game->display->clock) == 84
    || move_enemies_two(game, game->display->clock) == 84
    || move_enemies_three(game, game->display->clock) == 84)
        return 84;
    display_text(game);
    if (live_castle(game) == 84 || display_text_castle(game) == 84
    || display_build_icon(game) == 84 || live_enemies(game) == 84)
        return 84;
    return 0;
}