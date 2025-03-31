/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

static int comparison(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 == 0 && len_s2 != 0)
        return -1;
    else if (len_s1 != 0 && len_s2 == 0)
        return 1;
    if (len_s1 == 0 && len_s2 == 0)
        return 0;
    if (comparison(s1, s2) == 0)
        return 0;
    else if (comparison(s1, s2) < 0)
        return -1;
    else
        return 1;
}
