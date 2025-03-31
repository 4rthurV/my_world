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

void process_events(game_t *game, map_t *map)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window);
        update_view_key_arrows(game, map);
        if (game->event.type == sfEvtMouseButtonPressed)
            view_point_events(map, game);
    }
}

void my_world(game_t *game, map_t *map)
{
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);

    init_game(game);
    fill_iso_map(game, map);
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game, map);
        sfRenderWindow_clear(game->window, sfGrey);
        draw_2d_map(game, map);
        sfRenderWindow_display(game->window);
    }
}

int main(int argc, char **argv, char **env)
{
    game_t *game = malloc(sizeof(game_t));
    map_t *map = NULL;

    if (!env || !isatty(STDIN_FILENO)
        || (argc > 1 && strcmp(argv[1], "-h") != 0) || !game)
        return 84;
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return help_option();
    if (argc == 1) {
        map = init_map();
        if (!map) {
            write(2, "Failed to initialize map.\n", 26);
            return 84;
        }
        my_world(game, map);
    }
    free_map(map);
    free(game);
    return 0;
}
