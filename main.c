/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

/* static const cmd_t * const builtins = { */
/*     { "setenv", cmd_setenv, 0, 0, 0}, */
/*     { "unsetenv", cmd_unsetenv,0, 0, 0}, */
/*     { "env", cmd_env, 0, 0, 0}, */
/*     { "cd", cmd_cd, 0, 0, 0}, */
/*     { "exit", cmd_exit, 0, 0, 0}, */
/*     { 0, 0, 0, 0, 0} */
/* }; */

static void loop(int ac, char **av, sh_t *sh)
{
    get_var_path(dict_get(sh->env, "PATH"));
    return;
    if (!(isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) \
                && isatty(STDERR_FILENO))) {
        perror(0);
        exit(84);
    }
    while (!sh->exc) {
        
    }
}

int main(int ac, char **av, char **env)
{
    sh_t sh = {mkdict(env), 0};

    loop(ac, av, &sh);
    rmdict(sh.env);
    return 0;
}
