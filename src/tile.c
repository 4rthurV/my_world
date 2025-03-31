/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** tile.c
*/

#include "my_world.h"

double project_iso_point_x(int x, int y)
{
    double angle_x = 30 * M_PI / 180.0;

    return cos(angle_x) * x - cos(angle_x) * y;
}

double project_iso_point_y(int x, int y, int z)
{
    double angle_y = 35 * M_PI / 180.0;

    return sin(angle_y) * y + sin(angle_y) * x - z;
}

tile_t *create_tile(sfVector2f new_tile, int z)
{
    double scaled_x = new_tile.x * TILE_SIZE;
    double scaled_y = new_tile.y * TILE_SIZE;
    tile_t *tile = malloc(sizeof(tile_t));

    if (!tile)
        return NULL;
    tile->tile_x = project_iso_point_x(scaled_x, scaled_y);
    tile->tile_y = project_iso_point_y(scaled_x, scaled_y, z);
    tile->next = NULL;
    return tile;
}
