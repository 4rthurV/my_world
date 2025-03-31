/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** tridim_to_bidim.c.c
*/

#include "my.h"
#include "my_world.h"

sfvector_t **allocate_iso_map_rows(int map_height)
{
    sfvector_t **iso_map = malloc(map_height * sizeof(sfvector_t *));
    return iso_map;
}

static void free_iso_map_partial(sfvector_t **iso_map, int num_rows)
{
    for (int j = 0; j < num_rows; j++)
        free(iso_map[j]);
    free(iso_map);
}

bool allocate_iso_map_columns(sfvector_t **iso_map,
    int map_height, int map_width)
{
    int y = 0;
    
    for (y = 0; y < map_height; y++) {
        iso_map[y] = malloc(map_width * sizeof(sfvector_t));
        if (!iso_map[y]) {
            free_iso_map_partial(iso_map, y);
            return false;
        }
    }
    return true;
}

void fill_iso_map(sfvector_t **iso_map, int map_height, int map_width)
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
            scaled_x = x * MAP_X;
            scaled_y = y * MAP_Y;
            iso_map[y][x].x = project_iso_point_x(scaled_x, scaled_y);
            iso_map[y][x].y = project_iso_point_y(scaled_x, scaled_y, map[y][x]);
        }
    }
}

sfvector_t **create_twod_map(int map_height, int map_width)
{
    sfvector_t **iso_map = NULL;
    
    iso_map = allocate_iso_map_rows(map_height);
    if (!iso_map)
        return NULL;
    if (!allocate_iso_map_columns(iso_map, map_height, map_width))
        return NULL;
    fill_iso_map(iso_map, map_height, map_width);
    return iso_map;
}

tile_t *generate_tile_map(int map[MAP_Y][MAP_X])
{
    tile_t *head = NULL;
    tile_t *current = NULL;
    tile_t *new_tile = NULL;

    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x < MAP_X; x++) {
            new_tile = create_tile(x, y, map[y][x]);
            if (!new_tile)
                return NULL;
            if (!head)
                head = new_tile;
            else
                current->next = new_tile;
            current = new_tile;
        }
    }
    return head;
}
