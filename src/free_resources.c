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
        if (temp->sprite)
            sfSprite_destroy(temp->sprite);
        if (temp->texture)
            sfTexture_destroy(temp->texture);
        if (temp->name)
            free(temp->name);
        free(temp);
    }
}

void free_game(game_t *game)
{
    if (game) {
        if (game->state_mode)
            free(game->state_mode);
        if (game->window)
            sfRenderWindow_destroy(game->window);
        free(game);
    }
}

void free_all(map_t *map, buttons_t *buttons, game_t *game)
{
    if (map)
        free_map(map);
    if (buttons)
        free_buttons(buttons);
    if (game)
        free_game(game);
}
