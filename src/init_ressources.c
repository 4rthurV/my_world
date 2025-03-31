/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** init_ressources.c
*/

#include "my_world.h"

void init_game(game_t *game)
{
    char *mode = malloc(sizeof(char) * 5);

    game->mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->mode, "my_world",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->window_size = (sfVector2f){1920, 1080};
    game->angle_x = 30;
    game->angle_y = 20;
    mode = strdup("view");
    game->state_mode = strdup(mode);
    free(mode);
}

int init_map_texture(map_t *map)
{
    map->texture =
        sfTexture_createFromFile("graphics/textures/grass.png", NULL);
    if (!map->texture) {
        printf("Error: Failed to load texture\n");
        return 0;
    }
    sfTexture_setRepeated(map->texture, sfTrue);
    return 1;
}

void init_map_dimensions(map_t *map)
{
    map->map_height = MAP_HEIGHT;
    map->map_width = MAP_WIDTH;
    map->tile_size = TILE_SIZE;
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    init_map_dimensions(map);
    if (!init_map_texture(map))
        return NULL;
    map->array_map = create_zeroed_map(map->map_height, map->map_width);
    if (!map->array_map) {
        free(map);
        return NULL;
    }
    map->iso_map = allocate_iso_map_rows();
    if (!map->iso_map || !allocate_iso_map_columns(map->iso_map)) {
        free(map->array_map);
        free(map);
        return NULL;
    }
    return map;
}
