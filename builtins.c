/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

void cmd_setenv(int ac, char **av, sh_t *sh)
{
    if (ac == 1) {
        for (dict_t *d = sh->env; d; d = d->next)
            my_printf("%s=%r\n", d->k, d->v);
        sh->exc = 0;
    } else if (ac == 3) {
        dict_push(sh->env, my_strdup(av[1]), my_strdup(av[2]));
        sh->exc = 0;
    } else {
        sh->exc = 1;
        perror("setenv");
    }
}

void cmd_unsetenv(int ac, char **av, sh_t *sh)
{
    if (ac == 1) {
        perror("unsetenv");
        sh->exc = 1;
        return;
    }
    dict_pop(&sh->env, av[1]);
    sh->exc = 0;
}

void cmd_exit(int ac, char **av, sh_t *sh)
{
    my_puts("exit");
    sh->exc = INT_MAX;
    sh->eof = true;
}

void cmd_cd(int ac, char **av, sh_t *sh)
{
}

void cmd_env(int ac, char **av, sh_t *sh)
{
    for (dict_t *d = sh->env; d; d = d->next)
        my_printf("%s=%s\n", d->k, d->v);
    sh->exc = 0;
}
