/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

static bool is_ifs(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

cmd_t *prompt(sh_t *sh)
{
    cmd_t *cmd;
    char *in;

    if (isatty(STDOUT_FILENO))
        my_putstr(SHELL_PS1);
    in = getl(STDIN_FILENO);
    if (!in)
        cmd_exit(0, 0, sh);
    if (isatty(STDOUT_FILENO))
        my_puts("");
    cmd = mkcmd(sh, str_to_tab(in, is_ifs));
    free(in);
    return cmd;
}
