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

static char *fpath(char const *p, dict_t *env)
{
    char **path = str_to_tab(dict_get(env, "PATH"), ":");
    char *base = 0;

    for (size_t i = 0; path && path[i]; i++) {
        if (path[i])
            base = my_strdup(path[i]);
    }
    free_array(path);
    return my_strcat(my_strcat(my_strcat(gib(sizeof(char) * \
            (my_strlen(base) + my_strlen(p) + 2)), base), "/"), p);
}

char *get_path(char const *p, dict_t *env)
{
    char *base;

    if (is_path(p)) {
        if (*p != '/') {
            base = dict_get(env, "PWD");
            return my_strcat(my_strcat(my_strcat(gib(sizeof(char) * \
                    (my_strlen(base) + my_strlen(p) + 2)), base), "/"), p);
        } else
            return my_strdup(p);
    } else
        return fpath(p, env);
}
