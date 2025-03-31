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

void process_events(game_t *game, map_t *map, buttons_t *buttons)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            free_all(map, buttons, game);
            sfRenderWindow_close(game->window);
        }
        if ((game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyEscape)
            || click_quitbutton(game, buttons))
            sfRenderWindow_close(game->window);
        handle_zoom_dezoom(map, game, buttons);
        check_hover(game, buttons);
        check_clicks(game, buttons, map);
    }
}

void my_world(game_t *game, map_t *map, buttons_t *buttons)
{
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);

    fill_iso_map(game, map);
    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game, map, buttons);
        sfRenderWindow_clear(game->window, sfGrey);
        draw_2d_map(game, map);
        draw_buttons(game, buttons);
        sfRenderWindow_display(game->window);
    }
}

int main(int argc, char **argv, char **env)
{
    game_t *game = malloc(sizeof(game_t));
    map_t *map = NULL;
    buttons_t *buttons = NULL;

    if (!env || !isatty(STDIN_FILENO)
        || (argc > 1 && strcmp(argv[1], "-h") != 0) || !game)
        return 84;
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return help_option();
    if (argc == 1) {
        init_game(game);
        map = init_map();
        buttons = init_buttons(game);
        if (!map || !buttons)
            return 84;
        my_world(game, map, buttons);
    }
    free_all(map, buttons, game);
    return 0;
}
