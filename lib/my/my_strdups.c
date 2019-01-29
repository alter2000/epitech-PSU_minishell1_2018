/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** concatenate two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    char *len = dest + my_strlen(dest);

    for (; src && src[i]; i++)
        len[i] = src[i];
    len[i] = 0;
    return dest;
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    if (!src)
        return dest;
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}

int my_strcmp(char const *s1, char const *s2)
{
    while (*s2) {
        if (*s1 == *s2)
            return my_strcmp((s1 + 1), (s2 + 1));
        else
            return *s1 - *s2;
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2, size_t const n)
{
    while (*s2 && n) {
        if (*s1 == *s2)
            return my_strncmp((s1 + 1), (s2 + 1), n - 1);
        else
            return *s1 - *s2;
    }
    return 0;
}
