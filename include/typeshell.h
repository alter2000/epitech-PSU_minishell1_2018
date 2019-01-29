/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** something small
*/

#ifndef TYPESHELL_H
    #define TYPESHELL_H

    #include <stdbool.h>

struct dict {
    struct dict *next;
    char *k;
    char *v;
};
typedef struct dict dict_t;

typedef struct sh {
    dict_t *env;
    int exc;
    bool eof;
} sh_t;

typedef struct cmd {
    char *name;
    void (*func)(int, char **, sh_t *);
    sh_t *sh;
    char **av;
    int ac;
} cmd_t;

#endif
