/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** resize_map.c
*/

#include "my_world.h"

static void free_maps(int **array_map, sfVector2f **iso_map, int map_height)
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

bool duplicate_maps_one_bigger(map_t *map, int ***new_array_map,
    sfVector2f ***new_iso_map)
{
    sfVector2f size = {map->map_width + 1, map->map_height + 1};

    if (!allocate_and_copy_array_map(map, new_array_map, size.y, size.x))
        return false;
    if (!allocate_and_copy_iso_map(map, new_iso_map, size, new_array_map))
        return false;
    return true;
}

bool duplicate_maps_one_smaller(map_t *map, int ***new_array_map,
    sfVector2f ***new_iso_map)
{
    sfVector2f size = {map->map_width - 1, map->map_height - 1};

    if (map->map_width <= 1 || map->map_height <= 1)
        return false;
    if (!allocate_and_copy_array_map(map, new_array_map, size.y, size.x))
        return false;
    if (!allocate_and_copy_iso_map(map, new_iso_map, size, new_array_map))
        return false;
    return true;
}

int handle_resize_map(game_t *game, map_t *map, bool increase)
{
    int **new_array_map = NULL;
    sfVector2f **new_iso_map = NULL;
    bool success = 1;

    if (increase)
        success = duplicate_maps_one_bigger(map, &new_array_map, &new_iso_map);
    else
        success = duplicate_maps_one_smaller(map,
            &new_array_map, &new_iso_map);
    if (success) {
        free_maps(map->array_map, map->iso_map, map->map_height);
        map->array_map = new_array_map;
        map->iso_map = new_iso_map;
        map->map_height += increase ? 1 : -1;
        map->map_width += increase ? 1 : -1;
        fill_iso_map(game, map);
    }
    return 0;
}
