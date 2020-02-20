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

typedef struct settings {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *esc_sprite;
    sfTexture *esc_texture;
    sfText *esc_text;
    sfVector2f pos;
    sfVector2f pos_esc;
    sfVector2f pos_text;
    sfTexture *highlight;
    sfFont *font;
} settings_t;

typedef struct menu_pause {
    sfSprite *play_sprite;
    sfTexture *play_texture;
    sfTexture *play_texture_highlight;
    sfSprite *main_sprite;
    sfTexture *main_texture;
    sfTexture *main_texture_highlight;
    sfSprite *back_sprite;
    sfTexture *back_texture;
    sfFont *font;
    sfText *pause_text;
    sfEvent event;
} menu_pause_t;

typedef struct terrain{
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfSprite *tower1_sprite;
    sfTexture *tower1_texture;
    sfClock *clock;
    int rotation;
    int go_to_zero;
    int go_to_base;
    sfEvent event;
} terrain_t;

typedef struct enemys {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} enemys_t;

typedef struct castle {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} castle_t;

typedef struct game {
    struct castle *castle;
    struct enemys *enemys;
    struct menu_screen *screen;
    struct display *display;
    struct settings *settings;
    struct utils *utils;
    struct menu_pause *menu_pause;
    struct terrain *terrain;
    int is_alive;
    int money;
    int in_menu;
    int in_pause;
    int in_game;
    int in_settings;
} game_t;
