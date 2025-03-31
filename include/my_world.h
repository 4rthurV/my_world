/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** my_world.h
*/

#ifndef MY_WORLD
    #define MY_WORLD
    #define MAP_WIDTH   15
    #define MAP_HEIGHT   15
    #define TILE_SIZE   32
    #define M_PI 3.14159265358979323846

    #include <stdbool.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <float.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <math.h>
    #include <string.h>

typedef struct tile_s {
    double tile_x;
    double tile_y;
    struct tile_s *next;
} tile_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfVector2f window_size;
    int angle_x;
    int angle_y;
} game_t;

typedef struct map_s {
    int **array_map;
    int map_height;
    int map_width;
    sfVector2f **iso_map;
} map_t;

tile_t *generate_tile_map(int map[MAP_HEIGHT][MAP_WIDTH]);
sfVector2f **create_2d_map(game_t *game, map_t *map);
int free_tile_map(sfVector2f **tile_map, int map_height);
tile_t *create_tile(sfVector2f new_tile, int z);
double project_iso_point_x(game_t *game, int x, int y);
double project_iso_point_y(game_t *game, int x, int y, int z);
void fill_iso_map(game_t *game, map_t *map);
void init_game(game_t *game);
sfVertexArray *create_quad(sfVector2f *p1, sfVector2f *p2,
    sfVector2f *p3, sfVector2f *p4);
void draw_quad_outline(game_t *game, sfVector2f *points[4]);
int create_map_grid(game_t *game, sfVertexArray *quad, map_t *map, int y);
int draw_2d_map(game_t *game, map_t *map);
sfVector2f **allocate_iso_map_rows(void);
bool allocate_iso_map_columns(sfVector2f **iso_map);
int **create_zeroed_map(void);
void free_map(map_t *map);
map_t *init_map(void);
void update_view_key_arrows(game_t *game, map_t *map);
void view_point_events(map_t *map, game_t *game);
#endif
