/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** main.c
*/

#include "my_world.h"

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

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};

    if (!vertex_array)
        return NULL;
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return vertex_array;
}

int draw_2d_map(game_t *game, sfVector2f **map,
    int map_width, int map_height)
{
    sfVertexArray *line = NULL;

    for (int y = 0; y < map_height; y++) {
        for (int x = 0; x < map_width; x++) {
            if (x < map_width - 1) {
                line = create_line(&map[y][x], &map[y][x + 1]);
                if (!line)
                    return 84;
                sfRenderWindow_drawVertexArray(game->window, line, NULL);
                sfVertexArray_destroy(line);
            }
            if (y < map_height - 1) {
                line = create_line(&map[y][x], &map[y + 1][x]);
                if (!line)
                    return 84;
                sfRenderWindow_drawVertexArray(game->window, line, NULL);
                sfVertexArray_destroy(line);
            }
        }
    }
    return 0;
}

void my_world(game_t *game)
{
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);
    sfVector2f **tile_map = NULL;

    init_game(game);
    tile_map = create_2d_map(game, MAP_Y, MAP_X);
    if (!tile_map) {
        write(2, "Failed to create 2D map.\n", 26);
        return;
    }
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        sfRenderWindow_clear(game->window, sfGrey);
        draw_2d_map(game, tile_map, MAP_X, MAP_Y);
        sfRenderWindow_display(game->window);
    }
    free_tile_map(tile_map, MAP_Y);
}

int main(int argc, char **argv, char **env)
{
    game_t *game = malloc(sizeof(game_t));

    if (!env || !isatty(STDIN_FILENO)
        || (argc > 1 && strcmp(argv[1], "-h") != 0) || !game)
        return 84;
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return help_option();
    if (argc == 1)
        my_world(game);
    return 0;
}
