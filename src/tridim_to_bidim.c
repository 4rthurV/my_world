/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** tridim_to_bidim.c
*/

#include "my.h"
#include "my_world.h"

sfVector2f **allocate_iso_map_rows(int map_height)
{
    sfVector2f **iso_map = malloc(map_height * sizeof(sfVector2f *));

    return iso_map;
}

static void free_iso_map_partial(sfVector2f **iso_map, int num_rows)
{
    for (int j = 0; j < num_rows; j++)
        free(iso_map[j]);
    free(iso_map);
}

bool allocate_iso_map_columns(sfVector2f **iso_map,
    int map_height, int map_width)
{
    for (int y = 0; y < map_height; y++) {
        iso_map[y] = malloc(map_width * sizeof(sfVector2f));
        if (!iso_map[y]) {
            free_iso_map_partial(iso_map, y);
            return false;
        }
    }
    return true;
}

void fill_iso_map(sfVector2f **iso_map, int map_height, int map_width)
{
    int y = 0;
    int x = 0;
    double scaled_x = 0;
    double scaled_y = 0;
    static int map[MAP_Y][MAP_X] = {
        {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 5, 3, 0},
        {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}
    };

    for (y = 0; y < map_height; y++) {
        for (x = 0; x < map_width; x++) {
            scaled_x = x * TILE_SIZE;
            scaled_y = y * TILE_SIZE;
            iso_map[y][x].x = project_iso_point_x(scaled_x, scaled_y);
            iso_map[y][x].y =
                project_iso_point_y(scaled_x, scaled_y, map[y][x]);
        }
    }
}

sfVector2f **create_2d_map(int map_height, int map_width)
{
    sfVector2f **iso_map = NULL;

    iso_map = allocate_iso_map_rows(map_height);
    if (!iso_map)
        return NULL;
    if (!allocate_iso_map_columns(iso_map, map_height, map_width))
        return NULL;
    fill_iso_map(iso_map, map_height, map_width);
    return iso_map;
}
