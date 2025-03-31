/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** alpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int i;

    if (str == NULL)
        return 1;
    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            str[i] != '_')
            return 0;
    }
    return 1;
}
