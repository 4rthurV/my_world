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

void free_tile_textures(map_t *map)
{
    if (!map || !map->tile_textures)
        return;
    for (int y = 0; y < map->map_height; y++) {
        if (map->tile_textures[y])
            free(map->tile_textures[y]);
    }
    free(map->tile_textures);
}

void free_maps(int **array_map, sfVector2f **iso_map, int map_height)
{
    if (array_map) {
        for (int y = 0; y < map_height; y++)
            free(array_map[y]);
        free(array_map);
    }
    if (iso_map) {
        for (int y = 0; y < map_height; y++)
            free(iso_map[y]);
        free(iso_map);
    }
}
