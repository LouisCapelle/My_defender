##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles libmy
##

SRC	=	lib/my_putchar.c \
		lib/my_putstr.c \
		lib/convert_int_to_string.c \
		src/main.c \
		src/my_defender.c \
		src/screen_menu/init.c \
		src/screen_menu/highlight.c \
		src/navigation_controller.c \
		src/game/display_game.c \
		src/screen_menu/display.c \
		src/pause_menu/highlight.c \
		src/event_type.c \
		src/pause_menu/text_pause.c \
		src/pause_menu/pause_menu.c \
		src/game/towers/towers.c \
		src/settings/settings.c \
		src/game/enemies/move_enemies.c \
		src/sound/sound.c \
		src/game/money/money.c \
		src/game/towers/put_towers.c \
		src/game/towers/init_base_towers.c \
		src/game/towers/display_towers.c \
		src/game/towers/display_base_towers.c \
		src/settings/sound_setting.c \
		src/pause_menu/init_pause.c \
		src/game/build_menu/init_build_menu.c \
		src/game/build_menu/display_build_menu.c \
		src/game/enemies/display_enemies.c \
		src/game/enemies/move_enemies_next.c \
		src/game/enemies/live_enemies.c \
		src/game/build_menu/init_text_build.c \
		src/game/castle/live.c \

CFLAGS	=	-I ./include -g -Wno-deprecated

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window $(CFLAGS)
		@rm -rf $(OBJ)

re:	fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
