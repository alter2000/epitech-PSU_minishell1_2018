/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

cmd_t *prompt(sh_t *sh)
{
    cmd_t *cmd;

    my_putstr(SHELL_PS1);
    cmd = mkcmd(getl(STDIN_FILENO));
    return cmd;
}
