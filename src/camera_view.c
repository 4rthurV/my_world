/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** camera_view.c
*/

#include "my_world.h"

void update_view_key_arrows(game_t *game, map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->angle_x -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        game->angle_x += 5;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        game->angle_y -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        game->angle_y += 5;
    fill_iso_map(game, map);
}
