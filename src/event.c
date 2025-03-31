/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** event.c
*/

#include "my_world.h"


void handle_resize_event(game_t *game, map_t *map, int *resized)
{
    if ((game->event.key.code == sfKeyEqual && game->event.key.shift) ||
        game->event.key.code == sfKeyAdd) {
        if (*resized == 0) {
            handle_resize_map(game, map, 1);
            *resized = 1;
        }
    }
    if (game->event.key.code == sfKeyDash ||
        game->event.key.code == sfKeySubtract) {
        if (*resized == 0) {
            handle_resize_map(game, map, 0);
            *resized = 1;
        }
    }
}

void reset_resize_event(game_t *game, int *resized)
{
    if (game->event.type == sfEvtKeyReleased) {
        if (game->event.key.code == sfKeyEqual ||
            game->event.key.code == sfKeyAdd)
            *resized = 0;
    }
    if (game->event.type == sfEvtKeyReleased) {
        if (game->event.key.code == sfKeyDash ||
            game->event.key.code == sfKeySubtract)
            *resized = 0;
    }
}
