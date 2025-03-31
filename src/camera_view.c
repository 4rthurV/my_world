/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** camera_view.c
*/

#include "my_world.h"

void update_view_key_arrows(game_t *game, map_t *map)
{
    float seconds = 0.0f;
    float rotation_speed = 7.5f;

    if (!game->clock)
        return;
    seconds = sfTime_asSeconds(sfClock_getElapsedTime(game->clock));
    if (seconds < 0.032f)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->angle_x -= rotation_speed;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        game->angle_x += rotation_speed;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        game->angle_y -= rotation_speed;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        game->angle_y += rotation_speed;
    sfClock_restart(game->clock);
    fill_iso_map(game, map);
}
