/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

static bool is_path(char const *p)
{
    for (; p && *p; p++)
        if (*p == '/')
            return true;
    return false;
}

static char *merge_path(char const *base, char const *p)
{
    return my_strcat(my_strcat(my_strcat( \
            gib(sizeof(char) * (my_strlen(base) + my_strlen(p) + 2)), \
            base), "/"), p);
}

static char *fpath(char const *p, dict_t *env)
{
    return 0;
}

char *get_path(char const *p, dict_t *env)
{
    if (is_path(p)) {
        if (*p == '/')
            return my_strdup(p);
        else
            return merge_path(dict_get(env, "PWD"), p);
    } else
        return fpath(p, env);
}