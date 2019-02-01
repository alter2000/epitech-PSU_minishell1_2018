/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include <sys/wait.h>
#include <string.h>
#include "shell.h"

static void handle_sigs(int s)
{
    if (WIFSIGNALED(s))
        my_fputs((char const *)strsignal(WTERMSIG(s)), STDERR_FILENO);
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
    handle_sigs(s);
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
