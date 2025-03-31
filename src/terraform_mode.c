/*
** EPITECH PROJECT, 2024
** terraform_mode
** File description:
** Handles terraform mode related functions
*/

#include "my_world.h"

static void handle_terraform_exit(game_t *game, buttons_t *current)
{
    current->phase = 0;
    switch_textures(current);
    change_mode_name(game, "view");
}

void reset_map_to_flat(game_t *game, map_t *map)
{
    if (!map || !map->array_map || !map->iso_map)
        return;
    for (int y = 0; y < map->map_height; y++) {
        for (int x = 0; x < map->map_width; x++) {
            map->array_map[y][x] = 0;
        }
    }
    fill_iso_map(game, map);
}

void handle_reset_map(game_t *game, map_t *map, buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyR)) {
        reset_map_to_flat(game, map);
        return;
    }
    while (current && current->name) {
        if (strcmp(current->name, "temp_reset") == 0 &&
            button_is_clicked(game, current))
            reset_map_to_flat(game, map);
        current = current->next;
    }
}

void handle_terraform_mode(game_t *game, buttons_t *buttons, map_t *map)
{
    buttons_t *current = buttons;
    static int resized = 0;

    if (!current)
        return;
    handle_resize_event(game, buttons, map, &resized);
    reset_resize_event(game, buttons, &resized);
    if (game->event.type == sfEvtMouseButtonPressed)
        view_point_events(map, game);
    handle_reset_map(game, map, buttons);
    while (current && current->name) {
        if (strcmp(current->name, "state_terraform") == 0
            && button_is_clicked(game, current) && current->phase == 2) {
            handle_terraform_exit(game, current);
            return;
        }
        current = current->next;
    }
}
