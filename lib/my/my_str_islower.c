/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** my_str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i;

    if (str == NULL)
        return 1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
