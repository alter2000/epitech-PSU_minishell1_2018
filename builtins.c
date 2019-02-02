/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

int cmd_setenv(int ac, char **av, sh_t *sh)
{
    if (ac == 1) {
        for (dict_t *d = sh->env; d; d = d->next)
            my_printf("%s=%r\n", d->k, d->v);
        sh->exc = 0;
        return 0;
    } else if (ac == 2 || ac == 3) {
        dict_push(sh->env, my_strdup(av[1]), my_strdup(ac == 2 ? "" : av[2]));
        sh->exc = 0;
        return 0;
    } else {
        my_fputs("setenv: Too many arguments.", STDERR_FILENO);
        sh->exc = 1;
        return 1;
    }
}

int cmd_unsetenv(int ac, char **av, sh_t *sh)
{
    if (ac == 1) {
        my_fputs("unsetenv: Too few arguments.", STDERR_FILENO);
        sh->exc = 1;
        return 0;
    }
    dict_pop(&sh->env, av[1]);
    sh->exc = 0;
    return 0;
}

int cmd_exit(int ac, char **av, sh_t *sh)
{
    if (isatty(STDOUT_FILENO))
        my_puts("exit");
    sh->exc = INT_MAX;
    sh->eof = true;
    return 0;
}

int cmd_cd(int ac, char **av, sh_t *sh)
{
    char up[PATH_MAX] = {0};

    if (ac == 1 || (ac == 2 && !my_strcmp(av[1], "~")))
        return change_cwd(sh, dict_get(sh->env, "HOME"));
    if (ac > 2)
        return !my_fputs("cd: Too many arguments.", STDERR_FILENO);
    if (!my_strcmp(av[1], "-"))
        return change_cwd(sh, dict_get(sh->env, "OLDPWD"));
    if (ac == 2 && my_strcmp(av[1], "-"))
        return change_cwd(sh, av[1]);
    if (ac == 2 && av[1][1] && *av[1] == '~')
        return change_cwd(sh, my_strcat(my_strcat(up, "/home/"), av[1] + 1));
    return 0;
}

int cmd_env(int ac, char **av, sh_t *sh)
{
    for (dict_t *d = sh->env; d; d = d->next)
        my_printf("%s=%s\n", d->k, d->v);
    sh->exc = 0;
    return 0;
}
