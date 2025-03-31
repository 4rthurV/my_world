/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** free.c
*/

#include "my_world.h"

int free_tile_map(sfVector2f **tile_map, int map_height)
{
    for (int y = 0; y < map_height; y++) {
        if (tile_map[y])
            free(tile_map[y]);
    }
    if (tile_map)
        free(tile_map);
    return 0;
}

void free_map(map_t *map)
{
    if (map) {
        free_tile_map(map->iso_map, map->map_height);
        if (map->array_map)
            free(map->array_map);
        free(map);
    }
}
