/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** resize_map.c
*/

#include "my_world.h"

static void copy_iso_map_values(map_t *map, sfVector2f ***new_iso_map,
    int y, int x)
{
    if (y < map->map_height && x < map->map_width)
        (*new_iso_map)[y][x] = map->iso_map[y][x];
    else
        (*new_iso_map)[y][x] = (sfVector2f){0, 0};
}

bool allocate_and_copy_iso_map(map_t *map, sfVector2f ***new_iso_map,
    sfVector2f size, int ***new_array_map)
{
    *new_iso_map = malloc(sizeof(sfVector2f *) * size.y);
    if (!(*new_iso_map)) {
        free_maps(*new_array_map, NULL, size.y);
        return false;
    }
    for (int y = 0; y < size.y; y++) {
        (*new_iso_map)[y] = malloc(sizeof(sfVector2f) * size.x);
        if (!(*new_iso_map)[y]) {
            free_maps(*new_array_map, *new_iso_map, y);
            return false;
        }
        for (int x = 0; x < size.x; x++)
            copy_iso_map_values(map, new_iso_map, y, x);
    }
    return true;
}

static void copy_array_map_values(map_t *map, int ***new_array_map,
    int y, int x)
{
    if (y < map->map_height && x < map->map_width)
        (*new_array_map)[y][x] = map->array_map[y][x];
    else
        (*new_array_map)[y][x] = 0;
}

bool allocate_and_copy_array_map(map_t *map, int ***new_array_map,
    int height, int width)
{
    *new_array_map = malloc(sizeof(int *) * height);
    if (!(*new_array_map))
        return false;
    for (int y = 0; y < height; y++) {
        (*new_array_map)[y] = malloc(sizeof(int) * width);
        if (!(*new_array_map)[y]) {
            free_maps(*new_array_map, NULL, y);
            return false;
        }
        for (int x = 0; x < width; x++)
            copy_array_map_values(map, new_array_map, y, x);
    }
    return true;
}

static bool handle_texture_copy(map_t *map, sfTexture ****new_tile_textures,
    int y, int x)
{
    if (y < map->map_height && x < map->map_width)
        (*new_tile_textures)[y][x] = map->tile_textures[y][x];
    else
        (*new_tile_textures)[y][x] = NULL;
    return true;
}

static bool free_allocated_textures(sfTexture ****new_tile_textures, int y)
{
    for (int j = 0; j < y; j++)
        free((*new_tile_textures)[j]);
    free(*new_tile_textures);
    return false;
}

static bool allocate_texture_row(sfTexture ****new_tile_textures,
    int y, float width)
{
    (*new_tile_textures)[y] = malloc(sizeof(sfTexture *) * width);
    if (!(*new_tile_textures)[y])
        return false;
    return true;
}

bool allocate_and_copy_tile_textures(map_t *map,
    sfTexture ****new_tile_textures, sfVector2f size)
{
    *new_tile_textures = malloc(sizeof(sfTexture **) * size.y);
    if (!(*new_tile_textures))
        return false;
    for (int y = 0; y < size.y; y++) {
        if (!allocate_texture_row(new_tile_textures, y, size.x))
            return free_allocated_textures(new_tile_textures, y);
        for (int x = 0; x < size.x; x++)
            handle_texture_copy(map, new_tile_textures, y, x);
    }
    return true;
}

bool duplicate_maps_one_bigger(map_t *map, int ***new_array_map,
    sfVector2f ***new_iso_map)
{
    sfVector2f size = {map->map_width + 1, map->map_height + 1};
    sfTexture ***new_tile_textures = NULL;

    if (!allocate_and_copy_array_map(map, new_array_map, size.y, size.x))
        return false;
    if (!allocate_and_copy_iso_map(map, new_iso_map, size, new_array_map))
        return false;
    if (!allocate_and_copy_tile_textures(map, &new_tile_textures, size)) {
        free_maps(*new_array_map, *new_iso_map, size.y);
        return false;
    }
    map->tile_textures = new_tile_textures;
    return true;
}

bool duplicate_maps_one_smaller(map_t *map, int ***new_array_map,
    sfVector2f ***new_iso_map)
{
    sfVector2f size = {map->map_width - 1, map->map_height - 1};
    sfTexture ***new_tile_textures = NULL;

    if (map->map_width <= 1 || map->map_height <= 1)
        return false;
    if (!allocate_and_copy_array_map(map, new_array_map, size.y, size.x))
        return false;
    if (!allocate_and_copy_iso_map(map, new_iso_map, size, new_array_map))
        return false;
    if (!allocate_and_copy_tile_textures(map, &new_tile_textures, size)) {
        free_maps(*new_array_map, *new_iso_map, size.y);
        return false;
    }
    map->tile_textures = new_tile_textures;
    return true;
}
