/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics/Texture.h>
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/SoundBuffer.h>
#include "SFML/Audio.h"
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"
#include "struct_enemies.h"

/*src*/

/* init essentials */
int init_screen_menu(utils_t *utils, menu_t *screen);
sfRenderWindow *init_struct_display(display_t *display, utils_t *utils);
int display_settings_menu(game_t *game);
int init_game(game_t *game);
int init_game_two(game_t *game);

/* essentials */

int my_defender(game_t *game);
int event_type(sfEvent event, utils_t *utils, game_t *game);
sfRenderWindow *create_window(display_t *display);
int to_do(void);
int display_background(game_t *game);
int display_menu(game_t *game);
int navigation_controller(game_t *game);
void display_game(sfRenderWindow *window, game_t *game);

/* welcome menu */
int event_type_menu(sfEvent event, sfVector2i mouse_position, game_t *game);
int display_highlight_play(game_t *game);
int display_highlight_quit(game_t *game);

/* pause menu */
int pause_menu(game_t *game);
int init_pause_menu(game_t *game);
void init_text(game_t *game);
int display_highlight_play_pause(game_t *game);
int set_position(game_t *game);
int display_highlight_quit_pause(game_t *game);
int display_highlight_main_pause(game_t *game);

/* terrain */
int init_terrain(game_t *game);

/* build */
int init_build_menu(game_t *game);
int display_build_icon(game_t *game);
int get_build(game_t *game, sfEvent event, sfVector2i mouse_position);
int display_build_menu(game_t *game);
int init_text_build(game_t *game);

/* enemys */
int move_enemies_one_next(game_t *game, sfClock *clock, int x, int y);
int move_enemies_one(game_t *game, sfClock *clock);
int move_enemies_two(game_t *game, sfClock *clock);
int move_enemies_two_next(game_t *game, sfClock *clock, int x, int y);
int init_castle(game_t *game);
int init_enemies(game_t *game, sfClock *clock);
int init_enemies_two(game_t *game, sfClock *clock);
int init_enemies_one(game_t *game, sfClock *clock);
int init_enemies_three(game_t *game, sfClock *clock);
int move_enemies_three(game_t *game, sfClock *clock);
int move_enemies_three_next(game_t *game, sfClock *clock, int x, int y);
int live_enemies(game_t *game);
int init_shut_enemies(game_t *game);

/* setting */
void init_settings(game_t *game);
int display_settings(game_t *game);
int init_sound_settings(game_t *game);
int display_sound_settings(game_t * game);
int get_click(game_t *game, sfEvent event);

/* towers */
void rotate_tower(game_t *game);
void rotate_tower_two(game_t *game, sfTime time, float seconds);
void init_towers(game_t *game);
int init_tower_icons(game_t *game);
int put_towers(game_t *game, sfEvent event);
int move_towers(game_t *game);
int display_towers(game_t *game);
int init_base_towers(game_t *game);
int display_base_towers(game_t *game);

/*money*/
int init_money(game_t *game);
int update_money(game_t *game);

/*lib*/
void redirect_all_stdout(void);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_itoa(int nb);

/*sound*/
int music_game(game_t *game);

/*castle*/
int live_castle(game_t *game);
int update_live_castle(game_t *game);
int init_live_castle(game_t *game);
void display_text_castle(game_t *game);

/*destroy*/
int destroy_all(game_t *game);

#endif /* !MY_H */
