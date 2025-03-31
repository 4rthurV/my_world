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
        if (free_map_array_error(map, y))
            return NULL;
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = 0;
        }
    }
    return map;
}

void fill_iso_map(game_t *game, sfVector2f **iso_map)
{
    int y = 0;
    int x = 0;
    double base_x = game->window_size.x / 2;
    double base_y = game->window_size.y / 2;
    int **map = create_zeroed_map();

    if (!map)
        return;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            iso_map[y][x].x = base_x +
                project_iso_point_x(game, x * TILE_SIZE, y * TILE_SIZE);
            iso_map[y][x].y = base_y +
                project_iso_point_y(game, x * TILE_SIZE,
                y * TILE_SIZE, map[y][x]);
        }
    }
    for (y = 0; y < MAP_HEIGHT; y++)
        free(map[y]);
    free(map);
}

sfVector2f **create_2d_map(game_t *game)
{
    sfVector2f **iso_map = NULL;

    iso_map = allocate_iso_map_rows();
    if (!iso_map)
        return NULL;
    if (!allocate_iso_map_columns(iso_map))
        return NULL;
    fill_iso_map(game, iso_map);
    return iso_map;
}
