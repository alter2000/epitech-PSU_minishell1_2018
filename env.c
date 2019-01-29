/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

char *env_get_key(char *s)
{
    int idx = is_in('=', s);

    return my_strncpy(gib(sizeof(char) * (idx + 1)), s, idx);
}

char *env_get_val(char *s)
{
    int idx = is_in('=', s) + 1;

    return my_strcpy(gib(sizeof(char) * (my_strlen(s + idx) + 1)), s + idx);
}
