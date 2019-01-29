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

char **str_to_tab(char const *str, char const *key)
{
    size_t words = count_words(str, key);
    char **arr = gib(sizeof(*arr) * (words + 2));
    size_t i = 0;

    if (!str || !*str) {
        free(arr);
        return 0;
    }
    if (!key)
        key = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r";
    for (size_t word = 0; str && *str; str++, i++, word = 0) {
        for (; *str && is_in(*str, key); str++);
        arr[i] = gib((count_letters(str, key) + 1) * sizeof(*arr[i]));
        for (; *str && !is_in(*str, key); word++, str++)
            arr[i][word] = *str;
        my_puts(arr[i]);
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
