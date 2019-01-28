/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** something small
*/

#ifndef TYPESHELL_H
    #define TYPESHELL_H

struct dict {
    struct dict *next;
    char *k;
    char *v;
};
typedef struct dict dict_t;

typedef struct env {
    dict_t *h;
} env_t;

typedef struct cmd {
    env_t *env;
    char **av;
    int ac;
} cmd_t;

#endif
