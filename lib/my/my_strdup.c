/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dup;

    if (src == NULL)
        return NULL;
    dup = malloc(my_strlen(src) + 1);
    if (dup == NULL)
        return NULL;
    for (i = 0; src[i]; i++)
        dup[i] = src[i];
    dup[my_strlen(src)] = '\0';
    return dup;
}
