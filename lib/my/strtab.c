/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** change string to word array
*/

#include <stdlib.h>
#include "my.h"

static size_t count_letters(char const *str, bool (*keyv)(char))
{
    size_t letters = 0;

    for (; str && str[letters] && !keyv(str[letters]); letters++);
    return letters;
}

static size_t count_words(char const *str, bool (*keyv)(char))
{
    size_t words = 0;

    for (size_t i = 0; str && str[i]; i++)
        words += !!keyv(str[i]);
    return words;
}

char **str_to_tab(char const * const str, bool (*keyv)(char))
{
    char **arr;
    size_t i = 0;
    char const *sc = str;

    if (!sc || !*sc)
        return 0;
    arr = gib(sizeof(*arr) * (count_words(sc, keyv) + 2));
    for (size_t word = 0; *sc; i++, word = 0) {
        for (; *sc && keyv(*sc); sc++);
        if (*sc)
            arr[i] = gib(sizeof(*arr[i]) * (count_letters(sc, keyv) + 1));
        else
            break;
        for (; *sc && !keyv(*sc); word++, sc++)
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
