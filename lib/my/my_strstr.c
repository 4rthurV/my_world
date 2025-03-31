/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** my_strstr
*/

#include "my.h"

static int next(char *str, char const *to_find, int i)
{
    int j = 0;

    while (to_find[j] != '\0') {
        if (str[i] != to_find[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len_str = my_strlen(str);
    int len_fd = my_strlen(to_find);

    if (len_str < len_fd)
        return NULL;
    while (str[i] != '\0') {
        if (next(str, to_find, i) == 1)
            return &str[i];
        i++;
    }
    return (0);
}
