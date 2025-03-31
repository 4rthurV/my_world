/*
** EPITECH PROJECT, 2024
** my_strlowcase
** File description:
** my_strlowcase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i;

    if (str == NULL)
        return NULL;
    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + ('a' - 'A');
    }
    return str;
}
