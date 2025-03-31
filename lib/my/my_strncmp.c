/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** my_strncmp
*/

#include "my.h"

static int ncomparison(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        if (s1[i] == '\0')
            return -1;
        if (s2[i] == '\0')
            return 1;
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    return ncomparison(s1, s2, n);
}
