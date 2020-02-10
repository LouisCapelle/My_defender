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
		src/init_struct.c \

CFLAGS	=	-I ./include

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window $(CFLAGS)
		@rm -rf $(OBJ)

debug:	$(OBJ)
		gcc -o debug $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window $(CFLAGS) -g
		@rm -rf $(OBJ)

re:	fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
