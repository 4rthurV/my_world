/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** init_ressources.c
*/

#include "my_world.h"

void init_game(game_t *game)
{
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->mode, "my_world",
        sfResize | sfClose | sfFullscreen, NULL);
    game->window_size = (sfVector2f){1920, 1080};
    game->angle_x = 30;
    game->angle_y = 20;
}
