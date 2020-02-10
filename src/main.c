/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

void to_do(void)
{
    my_putstr("You have to defend your castle\n");
    my_putstr("Buy and place some buildings to block or kill your enemies\n");
    my_putstr("If the enemies touch the castle you lost, so be careful !\n");
}

int main(int argc, char **argv, char **envp)
{
    sfRenderWindow *window;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        to_do();
        return 0;
    }
    if (my_defender(window) == 84) {
        return 84;
    }
    return 0;
}