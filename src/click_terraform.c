/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** click_terraform.c
*/

#include "my_world.h"

double click_tile_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int check_tile_clicked(map_t *map, game_t *game, int i)
{
    for (int j = 0; j < map->map_width; j++) {
        if (click_tile_distance(map->iso_map[i][j].x,
            map->iso_map[i][j].y, game->event.mouseButton.x,
            game->event.mouseButton.y) < 50 && game->help == false &&
            game->event.mouseButton.button == sfMouseLeft) {
            map->iso_map[i][j].y -= 20;
            map->array_map[i][j] += 20;
            continue;
        }
        if (click_tile_distance(map->iso_map[i][j].x,
            map->iso_map[i][j].y, game->event.mouseButton.x,
            game->event.mouseButton.y) < 50 && game->help == false &&
            game->event.mouseButton.button == sfMouseRight) {
            map->iso_map[i][j].y += 20;
            map->array_map[i][j] -= 20;
            continue;
        }
    }
    return 1;
}

sfVector2f **up_or_down_map_tile(map_t *map, game_t *game)
{
    for (int i = 0; i < map->map_height; i++)
        check_tile_clicked(map, game, i);
    return map->iso_map;
}

void view_point_events(map_t *map, game_t *game)
{
    map->iso_map = up_or_down_map_tile(map, game);
}
