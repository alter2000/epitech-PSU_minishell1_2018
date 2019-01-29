/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** something small
*/

#ifndef SHELL_H
    #define SHELL_H

    #include "my.h"
    #include "typeshell.h"

dict_t *mkdict(char **);
void rmdict(dict_t *);
char *dict_get(dict_t *, char const *);
dict_t *dict_push(dict_t *, char *, char *);
char *dict_pop(dict_t **, char const *);

char *env_get_key(char *);
char *env_get_val(char *);

cmd_t *mkcmd(char *);
void rmcmd(cmd_t *);

void cmd_setenv(int, char **, sh_t *);
void cmd_unsetenv(int, char **, sh_t *);
void cmd_env(int, char **, sh_t *);
void cmd_cd(int, char **, sh_t *);
void cmd_exit(int, char **, sh_t *);

char *mkpath(char *);

#endif
