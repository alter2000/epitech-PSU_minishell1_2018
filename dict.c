/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

dict_t *mkdict(char **env)
{
    dict_t *dict = gib(sizeof(*dict));

    if (!env || !*env)
        return 0;
    dict->k = env_get_key(*env);
    dict->v = env_get_val(*env);
    dict->next = mkdict(env + 1);
    return dict;
}

void rmdict(dict_t *dict)
{
    dict_t *tmp;

    if (!dict)
        return;
    free(dict->k);
    free(dict->v);
    tmp = dict->next;
    free(dict);
    rmdict(tmp);
}

char *dict_get(dict_t *d, char const *k)
{
    for (; d; d = d->next)
        if (!my_strcmp(d->k, k))
            return d->v;
    return 0;
}

char *dict_pop(dict_t **d, char const *k)
{
    char *ret = 0;

    for (dict_t *tmp; (*d) && (*d)->next; (*d) = (*d)->next)
        if (!my_strcmp((*d)->next->k, k)) {
            ret = (*d)->next->v;
            tmp = (*d)->next->next;
            free((*d)->next->k);
            free((*d)->next);
            (*d)->next = tmp;
        }
    return ret;
}

dict_t *dict_push(dict_t *d, char *key, char *val)
{
    dict_t *tmp;

    for (tmp = d; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->k, key))
            return d;
    tmp->next = gib(sizeof(*tmp->next));
    tmp->k = key;
    tmp->v = val;
    return d;
}
