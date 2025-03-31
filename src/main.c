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

void my_world(game_t *game)
{
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);
    sfVector2f **tile_map = NULL;

    init_game(game);
    tile_map = create_2d_map(game);
    if (!tile_map) {
        write(2, "Failed to create 2D map.\n", 26);
        return;
    }
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        sfRenderWindow_clear(game->window, sfGrey);
        draw_2d_map(game, tile_map);
        sfRenderWindow_display(game->window);
    }
    free_tile_map(tile_map, MAP_HEIGHT);
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
