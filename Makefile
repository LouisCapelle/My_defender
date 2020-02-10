##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles libmy
##

SRC	=	lib/my_putchar.c \
		lib/my_putstr.c \
		src/main.c \
		src/my_defender.c \
		src/screen_menu/init.c \
		src/screen_menu/display.c \

CFLAGS	=	-I ./include -g

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
