/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

static const cmd_t builtins[] = {
    { "setenv",   cmd_setenv,   0, 0, 0 },
    { "unsetenv", cmd_unsetenv, 0, 0, 0 },
    { "env",      cmd_env,      0, 0, 0 },
    { "cd",       cmd_cd,       0, 0, 0 },
    { "exit",     cmd_exit,     0, 0, 0 },
    { 0, 0, 0, 0, 0 }
};

static int loop(int ac, char **av, sh_t *sh)
{
    cmd_t *curcmd;

    while (!sh->eof) {
        curcmd = prompt(sh);
        if (!cmd_builtins(curcmd, builtins) && curcmd->ac)
            cmd_exec(curcmd);
    }
    return 0;
}

void sighandle_int(int sig)
{
    if (sig != SIGINT)
        return;
    my_printf("\n%s", SHELL_PS1);
}

int main(int ac, char **av, char **env)
{
    sh_t sh = {mkdict(env), 0, false};
    int ret;

    signal(SIGINT, sighandle_int);
    ret = loop(ac, av, &sh);
    rmdict(sh.env);
    return ret;
}
