/*
** EPITECH PROJECT, 2020
** struct_two
** File description:
** struct_two
*/

#include "my.h"

typedef struct enemies_one {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int alive;
    sfText *live_text;
    sfText *live_int;
    sfSprite *shut;
    sfTexture *shut_texture;
} enemies_one_t;

typedef struct enemies_two {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int alive;
    sfText *live_text;
    sfText *live_int;
} enemies_two_t;

typedef struct enemies_three {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int alive;
    sfText *live_text;
    sfText *live_int;
} enemies_three_t;