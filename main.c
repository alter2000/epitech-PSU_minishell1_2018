/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

static const cmd_t *cmd_builtin = {
    { "setenv",   cmd_setenv,   0, 0, 0},
    { "unsetenv", cmd_unsetenv, 0, 0, 0},
    { "env",      cmd_env,      0, 0, 0},
    { "cd",       cmd_cd,       0, 0, 0},
    { "exit",     cmd_exit,     0, 0, 0},
    { 0, 0, 0, 0, 0 }
};

static int loop(int ac, char **av, sh_t *sh)
{
    cmd_t *curcmd;

    show_tab((const char **)str_to_tab(dict_get(sh->env, "PATH"), ":"), 0);
    if (!(isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) \
                && isatty(STDERR_FILENO))) {
        perror(0);
        exit(84);
    }
    while (!sh->exc) {
        curcmd = prompt(sh);
        if (!cmd_builtins(sh, curcmd, cmd_builtin))
            cmd_exec(sh, curcmd);
        rmcmd(curcmd);
    }
}

int main(int ac, char **av, char **env)
{
    sh_t sh = {mkdict(env), 0, 0};
    int ret = loop(ac, av, &sh);

    rmdict(sh.env);
    return ret;
}
