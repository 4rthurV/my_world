/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** my_strupcase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i;

    if (str == NULL)
        return NULL;
    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - ('a' - 'A');
    }
    return str;
}
