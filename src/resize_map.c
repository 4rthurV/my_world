/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** event.c
*/

#include "my_world.h"

void up_map_size(game_t *game, buttons_t *current,
    map_t *map, int *resized)
{
    if ((strcmp(current->name, "temp_plus") == 0 &&
        button_is_clicked(game, current)) ||
        (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyAdd)) {
        if (*resized == 0) {
            handle_resize_map(game, map, 1);
            *resized = 1;
        }
    }
}

void down_map_size(game_t *game, buttons_t *current,
    map_t *map, int *resized)
{
    if ((strcmp(current->name, "temp_minus") == 0 &&
        button_is_clicked(game, current)) ||
        (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySubtract)) {
        if (*resized == 0) {
            handle_resize_map(game, map, 0);
            *resized = 1;
        }
    }
}

void handle_resize_event(game_t *game, buttons_t *buttons,
    map_t *map, int *resized)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current && current->name) {
        up_map_size(game, current, map, resized);
        down_map_size(game, current, map, resized);
        current = current->next;
    }
}

void reset_resize_event(game_t *game, buttons_t *buttons, int *resized)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current && current->name) {
        if (strcmp(current->name, "temp_plus") == 0 &&
            !button_is_clicked(game, current))
            *resized = 0;
        if (strcmp(current->name, "temp_minus") == 0 &&
            !button_is_clicked(game, current))
            *resized = 0;
        current = current->next;
    }
}

int handle_resize_map(game_t *game, map_t *map, bool increase)
{
    int **new_array_map = NULL;
    sfVector2f **new_iso_map = NULL;
    bool success = 1;

    if (increase)
        success = duplicate_maps_one_bigger(map, &new_array_map, &new_iso_map);
    else
        success = duplicate_maps_one_smaller(map,
            &new_array_map, &new_iso_map);
    if (success) {
        free_maps(map->array_map, map->iso_map, map->map_height);
        map->array_map = new_array_map;
        map->iso_map = new_iso_map;
        map->map_height += increase ? 1 : -1;
        map->map_width += increase ? 1 : -1;
        fill_iso_map(game, map);
    }
    return 0;
}
