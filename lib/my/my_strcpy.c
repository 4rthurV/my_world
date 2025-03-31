/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copys string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
