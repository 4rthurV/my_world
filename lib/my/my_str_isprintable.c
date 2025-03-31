/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** my_str_isprintable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i;

    if (str == NULL)
        return 1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126)
            return 0;
    }
    return 1;
}
