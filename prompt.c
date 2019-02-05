/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

bool setenv_is_sane(char const *val)
{
    if (!my_isupper(*val) && !my_islower(*val))
        return !my_fputs("setenv: Variable name must begin with a letter", \
                STDERR_FILENO);
    for (; val && *val; val++)
        if (!(my_isalpha(*val) || my_isdigit(*val) \
                || *val == '.' || *val == '_'))
            return !my_fputs("setenv: Variable name must contain "
                            "alphanumeric characters", STDERR_FILENO);
    return 1;
}

int sh_setexc(sh_t *sh, int c)
{
    sh->exc = c;
    return sh->exc;
}

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
