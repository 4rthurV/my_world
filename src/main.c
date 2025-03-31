/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** main.c
*/

#include "my_world.h"

//void display_tile_vectors(int map_height,
//  int map_width, sfVector2f **tile_map)
//{
//    for (int y = 0; y < map_height; y++) {
//        for (int x = 0; x < map_width; x++) {
//            printf("Tile at (%.2f, %.2f)\n",
//                tile_map[y][x].x, tile_map[y][x].y);
//        }
//    }
//}

static int help_option(void)
{
    write(0, "USAGE:\n  ./my_world\n  ./my_world -h\n", 36);
    return 0;
}

void process_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window);
    }
}

void init_game(game_t *game)
{
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->mode, "my_world",
        sfResize | sfClose | sfFullscreen, NULL);
}

void my_world(game_t *game)
{
    init_game(game);
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_display(game->window);
    }
}

int main(int argc, char **argv, char **env)
{
    int map_height = MAP_Y;
    int map_width = MAP_X;
    sfVector2f **tile_map = NULL;
    game_t *game = malloc(sizeof(game_t));

    if (!env || !isatty(STDIN_FILENO)
        || (argc > 1 && strcmp(argv[1], "-h") != 0) || !game)
        return 84;
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return help_option();
    if (argc == 1) {
        tile_map = create_2d_map(map_height, map_width);
        if (!tile_map) {
            write(2, "Failed to create 2D map.\n", 26);
            return 84;
        }
        my_world(game);
        return free_tile_map(tile_map, map_height);
    }
}
