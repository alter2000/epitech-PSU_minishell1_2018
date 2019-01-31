/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** change string to word array
*/

#include <stdlib.h>
#include "my.h"

static size_t count_letters(char const *str, char const *key)
{
    size_t letters = 0;

    for (; str && str[letters] && !is_in(str[letters], key); letters++);
    return letters;
}

static size_t count_words(char const *str, char const *key)
{
    size_t words = 0;

    for (size_t i = 0; str && str[i]; i++)
        words += is_in(str[i], key);
    return words;
}

char **str_to_tab(char const * const str, char const *key)
{
    char **arr;
    size_t i = 0;
    char const *sc = str;

    if (!sc || !*sc)
        return 0;
    if (!key || !*key)
        key = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r";
    arr = gib(sizeof(*arr) * (count_words(sc, key) + 2));
    for (size_t word = 0; sc && *sc; sc++, i++, word = 0) {
        for (; *sc && is_in(*sc, key); sc++);
        arr[i] = gib(sizeof(*arr[i]) * (count_letters(sc, key) + 1));
        for (; *sc && !is_in(*sc, key); word++, sc++)
            arr[i][word] = *sc;
    }
    arr[i] = 0;
    return arr;
}

int show_tab(char const **tab, char const *sep)
{
    int res = 0;

    if (!sep)
        sep = "\n";
    for (uint_t i = 0; tab && tab[i]; i++) {
        res += my_putstr(tab[i]);
        res += my_putstr(sep);
    }
    return res;
}

void free_array(char **m)
{
    size_t i = 0;

    if (!m)
        return;
    if (*m) {
        for (; m[i]; i++)
            free(m[i]);
        free(m[i]);
    }
    free(m);
}
