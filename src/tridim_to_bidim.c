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

static void free_iso_map_partial(sfVector2f **iso_map, int num_rows)
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

int **create_zeroed_map(void)
{
    int **map = malloc(MAP_HEIGHT * sizeof(int *));

    if (!map)
        return NULL;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        map[y] = malloc(MAP_WIDTH * sizeof(int));
        if (!map[y]) {
            free_map_array_error(map, y);
            return NULL;
        }
        for (int x = 0; x < MAP_WIDTH; x++)
            map[y][x] = 0;
    }
    return map;
}

void fill_iso_map(game_t *game, map_t *map)
{
    int y = 0;
    int x = 0;
    double base_x = game->window_size.x / 2;
    double base_y = game->window_size.y / 2;

    if (!game || !map || !map->array_map)
        return;
    for (y = 0; y < map->map_height; y++) {
        for (x = 0; x < map->map_width; x++) {
            map->iso_map[y][x].x = base_x +
                project_iso_point_x(game, x * TILE_SIZE, y * TILE_SIZE);
            map->iso_map[y][x].y = base_y +
                project_iso_point_y(game, x * TILE_SIZE,
                y * TILE_SIZE, map->array_map[y][x]);
        }
    }
}
