/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);

    for (int i = 0; src[i] && i < nb; i++)
        dest[len_dest + i] = src[i];
    return dest;
}
