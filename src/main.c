/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

int to_do(void)
{
    if (my_putstr("You have to defend your castle\n") == 84
    || my_putstr("Buy some buildings to block or kill your enemies\n") == 84
    || my_putstr("If the enemies touch the castle you lost !\n") == 84)
        return 84;
    return 0;
}

int check_error_defender(game_t *game, display_t *display, menu_t *screen)
{
    if (my_defender(game) == 84) {
        destroy_all(game, display, screen);
        return 84;
    }
    destroy_all(game, display, screen);
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    game_t *game = malloc(sizeof(game_t));
    display_t *display = malloc(sizeof(display_t));
    menu_t *screen = malloc(sizeof(menu_t));

    if (!game || !display || !screen)
        return 84;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        to_do();
        return 0;
    } else if (argc == 1){
        if (check_error_defender(game, display, screen) == 84)
            return 84;
    } else {
        sfMusic_destroy(game->utils->song);
        sfRenderWindow_destroy(game->utils->window);
        return 84;
    }
    return 0;
}