/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** tile.c
*/

#include "my_world.h"

double project_iso_point_x(game_t *game, int x, int y)
{
    double angle_x = game->angle_x * M_PI / 180.0;

    return cos(angle_x) * x - cos(angle_x) * y;
}

double project_iso_point_y(game_t *game, int x, int y, int z)
{
    double angle_y = game->angle_y * M_PI / 180.0;

    return sin(angle_y) * y + sin(angle_y) * x - z;
}
