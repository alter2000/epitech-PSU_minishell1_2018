/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

int change_cwd(sh_t *sh, char *dirto)
{
    char p[PATH_MAX * 2] = {0};
    char *pkek = getcwd(p, sizeof(p));

    if (chdir(dirto) || !pkek) {
        perror(dirto);
        return sh_setexc(sh, 1);
    }
    dict_push(sh->env, "OLDPWD", my_strdup(p));
    dict_push(sh->env, "PWD", my_strdup(getcwd(p, sizeof(p))));
    return 0;
}
