/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

int change_cwd(sh_t *sh, char *dirto)
{
    if (chdir(dirto)) {
        perror("cd");
        return 0;
    }
    return 1;
}
