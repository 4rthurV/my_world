/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** my_world.h
*/

#ifndef MY_WORLD
    #define MY_WORLD
    #define MAP_X   6
    #define MAP_Y   6
    #define TILE_SIZE   64
    #define M_PI 3.14159265358979323846

#include <stdbool.h>

typedef struct sfvector_s {
    float x;
    float y;
} sfvector_t;

typedef struct tile_s {
    double tile_x;
    double tile_y;
    struct tile_s *next;
} tile_t;

tile_t *generate_tile_map(int map[MAP_Y][MAP_X]);
sfvector_t **create_twod_map(int map_height, int map_width);
int free_tile_map(sfvector_t **tile_map, int map_height);
tile_t *create_tile(int x, int y, int z);
double project_iso_point_x(int x, int y);
double project_iso_point_y(int x, int y, int z);
#endif
