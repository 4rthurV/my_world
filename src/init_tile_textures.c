/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** init_tile_textures.c
*/

#include "my_world.h"

static bool free_allocated_texture_rows(map_t *map, int y)
{
    for (int j = 0; j < y; j++)
        free(map->tile_textures[j]);
    free(map->tile_textures);
    return false;
}

static bool allocate_texture_row(map_t *map, int y)
{
    map->tile_textures[y] = malloc(sizeof(sfTexture *) * map->map_width);
    if (!map->tile_textures[y])
        return false;
    for (int x = 0; x < map->map_width; x++)
        map->tile_textures[y][x] = NULL;
    return true;
}

bool init_tile_textures(map_t *map)
{
    if (!map)
        return false;
    map->tile_textures = malloc(sizeof(sfTexture **) * map->map_height);
    if (!map->tile_textures)
        return false;
    for (int y = 0; y < map->map_height; y++) {
        if (!allocate_texture_row(map, y))
            return free_allocated_texture_rows(map, y);
    }
    return true;
}

static bool init_map_arrays(map_t *map)
{
    map->array_map = create_zeroed_map(map->map_height, map->map_width);
    if (!map->array_map)
        return false;
    map->iso_map = allocate_iso_map_rows();
    if (!map->iso_map || !allocate_iso_map_columns(map->iso_map)) {
        free(map->array_map);
        return false;
    }
    if (!init_tile_textures(map)) {
        free_maps(map->array_map, map->iso_map, map->map_height);
        return false;
    }
    return true;
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    init_map_dimensions(map);
    if (!init_map_texture(map)) {
        free(map);
        return NULL;
    }
    if (!init_map_arrays(map)) {
        free(map);
        return NULL;
    }
    return map;
}
