/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** texture_tile.c
*/

#include "my_world.h"

static sfTexture *get_selected_texture(buttons_t *buttons)
{
    buttons_t *current = buttons;
    char *texture_name = NULL;

    while (current) {
        if (current->phase == 2 && (
            strcmp(current->name, "state_grass") == 0 ||
            strcmp(current->name, "state_water") == 0 ||
            strcmp(current->name, "state_stone") == 0 ||
            strcmp(current->name, "state_sand") == 0)) {
            texture_name = current->name + 6;
            return load_texture_by_name(texture_name);
        }
        current = current->next;
    }
    return NULL;
}

static double click_tile_distance_texture(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

static bool is_valid_map_position(map_t *map, int i, int j)
{
    return map && map->iso_map && map->tile_textures &&
            i < map->map_height && map->iso_map[i] &&
            j < map->map_width;
}

static bool is_clicked_distance(map_t *map, game_t *game, int i, int j)
{
    double distance = click_tile_distance_texture(map->iso_map[i][j].x,
        map->iso_map[i][j].y, game->event.mouseButton.x,
        game->event.mouseButton.y);

    return distance < 50 && game->event.mouseButton.button == sfMouseLeft;
}

static int check_texture_tile_clicked(map_t *map, game_t *game,
    int i, sfTexture *texture)
{
    if (!is_valid_map_position(map, i, 0))
        return 0;
    for (int j = 0; j < map->map_width; j++) {
        if (!is_valid_map_position(map, i, j))
            continue;
        if (is_clicked_distance(map, game, i, j) && texture &&
            map->tile_textures && map->tile_textures[i]) {
            map->tile_textures[i][j] = texture;
            return 1;
        }
    }
    return 0;
}

static void apply_texture_to_tile(map_t *map, game_t *game, sfTexture *texture)
{
    for (int i = 0; i < map->map_height; i++) {
        if (check_texture_tile_clicked(map, game, i, texture))
            break;
    }
}

void change_tile_texture(map_t *map, game_t *game, buttons_t *buttons)
{
    sfTexture *selected_texture = NULL;

    if (strcmp(game->state_mode, "textures") != 0)
        return;
    if (game->event.type != sfEvtMouseButtonPressed)
        return;
    if (game->event.mouseButton.button != sfMouseLeft)
        return;
    selected_texture = get_selected_texture(buttons);
    if (selected_texture)
        apply_texture_to_tile(map, game, selected_texture);
}
