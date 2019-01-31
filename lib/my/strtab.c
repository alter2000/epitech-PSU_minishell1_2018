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

    for (size_t i = 0; str && str[i]; words += is_in(str[i], key), i++);
    return words;
}

char **str_to_tab(char const * const str, char const *key)
{
    size_t words;
    char **arr;
    size_t i = 0;
    char const *sc = str;

    if (!sc || !*sc)
        return 0;
    if (!key)
        key = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r";
    words = count_words(sc, key);
    arr = gib(sizeof(*arr) * (words + 2));
    for (size_t word = 0; sc && *sc; sc++, i++, word = 0) {
        for (; *sc && is_in(*sc, key); sc++);
        arr[i] = gib((count_letters(sc, key) + 1) * sizeof(*arr[i]));
        for (; *sc && !is_in(*sc, key); word++, sc++)
            arr[i][word] = *str;
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
    uint_t i = 0;

    for (; m[i]; i++)
        free(m[i]);
    free(m[i]);
    free(m);
}
