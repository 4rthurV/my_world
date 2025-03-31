/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** main.c
*/

#include "my.h"
#include "my_world.h"

void display_tile_vectors(int map_height, int map_width,
    sfvector_t **tile_map)
{
    for (int y = 0; y < map_height; y++) {
        for (int x = 0; x < map_width; x++) {
            printf("Tile at (%.2f, %.2f)\n",
                tile_map[y][x].x, tile_map[y][x].y);
        }
    }
}

static int help_option(void)
{
    write(0, "USAGE:\n  ./my_world\n  ./my_world -h\n", 36);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    int map_height = MAP_Y;
    int map_width = MAP_X;
    sfvector_t **tile_map = NULL;

    if (!env || !isatty(STDIN_FILENO))
        return 84;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return help_option();
    if (argc == 1) {
        tile_map = create_twod_map(map_height, map_width);
        if (!tile_map) {
            write(2, "Failed to create 2D map.\n", 26);
            return 84;
        }
        display_tile_vectors(map_height, map_width, tile_map);
        return free_tile_map(tile_map, map_height);
    } else {
        write(2, "my_world: Too many arguments.\n", 30);
        return 84;
    }
}
