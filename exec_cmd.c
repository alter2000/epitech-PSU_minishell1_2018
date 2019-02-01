/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include <sys/wait.h>
#include <string.h>
#include "shell.h"

static void handle_sigs(int s, sh_t *sh)
{
    if (WIFEXITED(s)) {
        sh->exc = WEXITSTATUS(s);
        return;
    }
    if (WIFSIGNALED(s)) {
        my_fputstr(strsignal(WTERMSIG(s)), STDERR_FILENO);
        if (WCOREDUMP(s))
            my_fputstr(" (core dumped)", STDERR_FILENO);
        my_fputstr("\n", STDERR_FILENO);
    }
}

static void forky_exec(char *fp, cmd_t *cmd)
{
    int s = 0;
    pid_t pid = fork();

    if (pid > 0)
        wait(&s);
    if (pid < 0)
        perror("forky_exec");
    if (!pid) {
        execve(fp, cmd->av, env_to_tab(cmd->sh->env));
        perror("forky_exec");
        exit(84);
    }
    handle_sigs(s, cmd->sh);
    rmcmd(cmd);
}

int cmd_exec(cmd_t *cmd)
{
    char *fullpath = get_path(cmd->av[0], cmd->sh->env);

    if (fullpath && *fullpath == '/') {
        forky_exec(fullpath, cmd);
        return 0;
    } else
        return my_fputstr(cmd->av[0], STDERR_FILENO) + \
            my_fputs(": Command not found.", STDERR_FILENO);
}
