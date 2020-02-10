/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#define STRUCT_H_

typedef struct display {
    sfSprite *sprite;
    sfClock *clock;
    sfTexture *texture;
    sfVector2f offset;
    sfVector2f pos;
} display_t;

typedef struct utils {
    sfRenderWindow *window;
    sfVideoMode video_mode;
} utils_t;

typedef struct menu_screen {
    sfSprite *play_sprite;
    sfTexture *play_texture;
    sfSprite *quit_sprite;
    sfTexture *quit_texture;
    sfVector2f pos_play;
    sfVector2f pos_quit;
} menu_t;
