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

    my_puts("cd: got path	");
    my_puts(dirto);
    if (chdir(dirto) || !pkek) {
        perror("cd");
        return 0;
    }
    dict_push(sh->env, "OLDPWD", my_strdup(p));
    dict_push(sh->env, "PWD", my_strdup(getcwd(p, sizeof(p))));
    return 1;
}
