/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** free.c
*/

#include "my_world.h"

int free_tile_map(sfVector2f **tile_map, int map_height)
{
    for (int y = 0; y < map_height; y++) {
        if (tile_map[y])
            free(tile_map[y]);
    }
    if (tile_map)
        free(tile_map);
    return 0;
}

void free_map(map_t *map)
{
    if (map) {
        free_tile_map(map->iso_map, map->map_height);
        if (map->array_map)
            free(map->array_map);
        free(map);
    }
}

void free_buttons(buttons_t *buttons)
{
    buttons_t *temp;

    while (buttons) {
        temp = buttons;
        buttons = buttons->next;
        sfSprite_destroy(temp->sprite);
        sfTexture_destroy(temp->texture);
        free(temp->name);
        free(temp);
    }
}

void free_all(map_t *map, buttons_t *buttons, game_t *game)
{
    if (map)
        free_map(map);
    if (buttons)
        free_buttons(buttons);
    if (game)
        free(game);
}
