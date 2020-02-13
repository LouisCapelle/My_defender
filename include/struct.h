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
    sfTexture *play_texture_highlight;
    sfSprite *quit_sprite;
    sfTexture *quit_texture;
    sfTexture *quit_texture_highlight;
    sfVector2f pos_play;
    sfVector2f pos_quit;
} menu_t;


typedef struct game {
    struct menu_screen *screen;
    struct display *display;
    struct utils *utils;
    int is_alive;
    int in_menu;
} game_t;
