/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** tridim_to_bidim.c
*/

#include "my_world.h"

sfVector2f **allocate_iso_map_rows(void)
{
    sfVector2f **iso_map = malloc(MAP_HEIGHT * sizeof(sfVector2f *));

    if (!iso_map)
        return NULL;
    for (int i = 0; i < MAP_HEIGHT; i++)
        iso_map[i] = NULL;
    return iso_map;
}

void free_iso_map_partial(sfVector2f **iso_map, int num_rows)
{
    for (int j = 0; j < num_rows; j++)
        free(iso_map[j]);
    free(iso_map);
}

bool allocate_iso_map_columns(sfVector2f **iso_map)
{
    for (int y = 0; y < MAP_HEIGHT; y++) {
        iso_map[y] = malloc(MAP_WIDTH * sizeof(sfVector2f));
        if (!iso_map[y]) {
            free_iso_map_partial(iso_map, y);
            return false;
        }
    }
    return true;
}

static int free_map_array_error(int **map, int y)
{
    if (!map[y]) {
        for (int i = 0; i < y; i++)
            free(map[i]);
        free(map);
        return 1;
    }
    return 0;
}

int **create_zeroed_map(int width, int height)
{
    int **map = malloc(height * sizeof(int *));

    if (!map)
        return NULL;
    for (int y = 0; y < height; y++) {
        map[y] = malloc(width * sizeof(int));
        if (!map[y]) {
            free_map_array_error(map, y);
            return NULL;
        }
        for (int x = 0; x < width; x++)
            map[y][x] = 0;
    }
    return map;
}

static void place_every_tile(game_t *game, map_t *map, int x, int y)
{
    double base_x = game->window_size.x / 2;
    double base_y = game->window_size.y / 2;
    int size = map->tile_size;

    if (y < map->map_height && x < map->map_width) {
        map->iso_map[y][x].x = base_x +
            project_iso_point_x(game, x * size, y * size);
        map->iso_map[y][x].y = base_y +
            project_iso_point_y(game, x * size, y * size,
            map->array_map[y][x]);
    }
}

void fill_iso_map(game_t *game, map_t *map)
{
    if (!game || !map || !map->array_map || !map->iso_map)
        return;
    for (int y = 0; y < map->map_height; y++) {
        for (int x = 0; x < map->map_width; x++)
            place_every_tile(game, map, x, y);
    }
}
