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

/*src*/

/* init essentials */
int init_screen_menu(utils_t *utils, menu_t *screen);
sfRenderWindow *init_struct_display(display_t *display, utils_t *utils);
int init_game(game_t *game);

/* essentials */

int my_defender(void);
int event_type(sfEvent event, utils_t *utils, game_t *game);
sfRenderWindow *create_window(display_t *display);
void to_do(void);
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

/* terrain */
void init_terrain(game_t *game);

/* enemys */
int move_enemys(game_t *game, sfClock *clock);
int move_enemys_two(game_t *game, sfClock *clock);
int move_enemies_two(game_t *game, sfClock *clock, int x, int y);
int init_castle(game_t *game);
int init_enemys(game_t *game, sfClock *clock);

/* setting */
int init_settings(game_t *game);
int display_settings(game_t *game);

/* towers */
void rotate_tower(game_t *game);
void init_towers(game_t *game);

/*lib*/
void redirect_all_stdout(void);
int my_putchar(char c);
int my_putstr(char const *str);

#endif /* !MY_H */
