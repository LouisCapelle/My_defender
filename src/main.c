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
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        to_do();
        return 0;
    }else if (argc == 1){
        return (my_defender());
    }else{
        return 84;
    }
}