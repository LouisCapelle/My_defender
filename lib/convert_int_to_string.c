/*
** EPITECH PROJECT, 2020
** itoa
** File description:
** itoa
*/

#include <stdlib.h>

int int_len(int nb)
{
    int	stock = nb;
    int i = 0;

    while (stock >= 10)
    {
        stock /= 10;
        i += 1;
    }
    return (i);
}

char *my_itoa(int nb)
{
    int	len = int_len(nb) + 1;
    char *str;

    str = malloc(sizeof(char) * len + 1);
    str[len] = '\0';
    len = len - 1;
    while (len != -1){
        str[len] = nb % 10  + '0';
        nb /= 10;
        len = len - 1;
    }
    return (str);
}