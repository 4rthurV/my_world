/*
** EPITECH PROJECT, 2024
** my_evil_str
** File description:
** reverse str two by two
*/

#include "my.h"

char *my_revstr(char *str)
{
    int temp;
    int length = my_strlen(str);

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i -1] = temp;
    }
    return str;
}
