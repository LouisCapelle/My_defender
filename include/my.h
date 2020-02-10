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
int my_defender(void);
void event_type(sfEvent event, utils_t *utils);
sfRenderWindow *create_window(display_t *display);
void to_do(void);
int display_background(utils_t *utils, display_t *display, menu_t *screen);
int display_menu(utils_t *utils, menu_t *screen);
int init_screen_menu(utils_t *utils, menu_t *screen);
sfRenderWindow *init_struct_display(display_t *display, utils_t *utils);

/*lib*/
void redirect_all_stdout(void);
int my_putchar(char c);
int my_putstr(char const *str);

#endif /* !MY_H */
