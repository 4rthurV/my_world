/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** free_resources.c
*/

#include "my_world.h"

void free_map(map_t *map)
{
    free_tile_map(map->iso_map, map->map_height);
    if (map->array_map)
        free(map->array_map);
    free_tile_textures(map);
    sfTexture_destroy(map->texture);
    free(map);
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
