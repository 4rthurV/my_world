/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** zoom_dezoom.c
*/

#include "my_world.h"

void change_tile_size(map_t *map, int delta)
{
    if (delta < 0) {
        if (map->tile_size < 200)
            map->tile_size *= 1.1;
        if (map->tile_size > 200)
            map->tile_size = 200;
    }
    if (delta > 0) {
        if (map->tile_size > 10)
            map->tile_size *= 0.9;
        if (map->tile_size < 10)
            map->tile_size = 10;
    }
}

void handle_zoom_dezoom(map_t *map, game_t *game, buttons_t *buttons)
{
    float delta = 0.0f;

    if (game->event.type == sfEvtMouseWheelScrolled)
        delta = game->event.mouseWheelScroll.delta;
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (check_click_on_button(game, buttons, "temp_zoom"))
            delta = -1;
        if (check_click_on_button(game, buttons, "temp_dezoom"))
            delta = 1;
    }
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyZ)
            delta = 1;
        if (game->event.key.code == sfKeyD)
            delta = -1;
    }
    change_tile_size(map, delta);
}
