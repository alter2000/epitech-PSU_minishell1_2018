/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** essential functions
*/

#include "my.h"

unsigned long long int my_strlen(char const *str)
{
    unsigned long long int i = 0;

    while (str && str[i])
        i++;
    return i;
}

int my_putchar(int const c)
{
    if (!c)
        return 0;
    return write(STDOUT_FILENO, &c, 1);
}

size_t my_putstr(char const *str)
{
    return write(STDOUT_FILENO, str, my_strlen(str));
}

char *my_strdup(char const *src)
{
    return my_strcpy(gib((my_strlen(src) + 1) * sizeof(char)), src);
}
