/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#define STRUCT_H_

typedef struct display {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *sprite;
    sfClock *clock;
    sfTexture *texture;
    sfVector2f offset;
    sfVector2f pos;
    sfVector2f pos_two;
}display_t;