/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** something small
*/

#ifndef SHELL_H
    #define SHELL_H

    #include <signal.h>
    #include "my.h"
    #include "typeshell.h"

    #define SHELL_PS1 ("> ")

dict_t *mkdict(char **);
void rmdict(dict_t *);
char *dict_get(dict_t *, char const *);
dict_t *dict_push(dict_t *, char *, char *);
char *dict_pop(dict_t **, char const *);

char *env_get_key(char *);
char *env_get_val(char *);

cmd_t *mkcmd(sh_t *, char *);
void rmcmd(cmd_t *);

void cmd_setenv(int, char **, sh_t *);
void cmd_unsetenv(int, char **, sh_t *);
void cmd_env(int, char **, sh_t *);
void cmd_cd(int, char **, sh_t *);
void cmd_exit(int, char **, sh_t *);

char *mkpath(char *);
char *get_path(char const *, dict_t *);

cmd_t *prompt(sh_t *);
int cmd_builtins(cmd_t *, cmd_t const *);
int cmd_exec(sh_t *, cmd_t *);
#endif
