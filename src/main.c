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

int process_events(game_t *game, map_t *map, buttons_t *buttons)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            return 84;
        }
        if ((game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyEscape)
            || click_quitbutton(game, buttons))
            sfRenderWindow_close(game->window);
        handle_help_panel(game, buttons);
        handle_zoom_dezoom(map, game, buttons);
        check_hover(game, buttons);
        check_clicks(game, buttons, map);
    }
    return 0;
}

int handle_frame_time(game_t *game, map_t *map, buttons_t *buttons)
{
    sfTime elapsed = sfClock_getElapsedTime(game->clock);
    float delta_time = sfTime_asSeconds(elapsed);

    if (delta_time >= 0.016) {
        if (process_events(game, map, buttons) == 84)
            return 84;
        sfClock_restart(game->clock);
    }
    return 0;
}

void my_world(game_t *game, map_t *map,
    buttons_t *buttons, panel_t *help_panel)
{
    sfColor sfGrey = sfColor_fromRGB(128, 128, 128);

    fill_iso_map(game, map);
    while (sfRenderWindow_isOpen(game->window)) {
        if (handle_frame_time(game, map, buttons) == 84)
            break;
        sfRenderWindow_clear(game->window, sfGrey);
        draw_2d_map(game, map);
        draw_buttons(game, buttons);
        draw_help_panel(game, help_panel);
        sfRenderWindow_display(game->window);
    }
}

int init_structs(game_t *game, map_t **map,
    buttons_t **buttons, panel_t **help_panel)
{
    init_game(game);
    *map = init_map();
    *buttons = init_buttons(game);
    *help_panel = init_help_panel(game);
    if (!(*map) || !(*buttons))
        return 84;
    return 0;
}

static int check_environment(int argc, char **argv, char **env)
{
    if (!env || !isatty(STDIN_FILENO) || getenv("DISPLAY") == NULL
        || (argc > 1 && strcmp(argv[1], "-h") != 0)) {
        return 84;
    }
    return 0;
}

static int initialize_game(game_t **game, map_t **map,
    buttons_t **buttons, panel_t **help_panel)
{
    *game = malloc(sizeof(game_t));
    if (!(*game))
        return 84;
    return init_structs(*game, map, buttons, help_panel);
}

int main(int argc, char **argv, char **env)
{
    game_t *game = NULL;
    map_t *map = NULL;
    buttons_t *buttons = NULL;
    panel_t *help_panel = NULL;

    if (check_environment(argc, argv, env) == 84) {
        free_all(map, buttons, game, help_panel);
        return 84;
    }
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return help_option();
    if (argc == 1 && initialize_game(&game, &map, &buttons, &help_panel) == 0)
        my_world(game, map, buttons, help_panel);
    free_all(map, buttons, game, help_panel);
    return 0;
}
