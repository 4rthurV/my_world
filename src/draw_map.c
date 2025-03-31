/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** draw_map.c
*/

#include "my_world.h"

sfVertexArray *draw_quad(sfVector2f *points[4], const sfTexture *texture)
{
    sfVector2u tex_size = sfTexture_getSize(texture);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex v1 = {.position = *points[0], .texCoords = {0, 0}};
    sfVertex v2 = {.position = *points[1], .texCoords = {tex_size.x, 0}};
    sfVertex v3 = {.position = *points[2],
        .texCoords = {tex_size.x, tex_size.y}};
    sfVertex v4 = {.position = *points[3], .texCoords = {0, tex_size.y}};

    v1.color = sfWhite;
    v2.color = sfWhite;
    v3.color = sfWhite;
    v4.color = sfWhite;
    if (!vertex_array)
        return NULL;
    sfVertexArray_append(vertex_array, v1);
    sfVertexArray_append(vertex_array, v2);
    sfVertexArray_append(vertex_array, v3);
    sfVertexArray_append(vertex_array, v4);
    sfVertexArray_setPrimitiveType(vertex_array, sfTriangleFan);
    return vertex_array;
}

void draw_quad_outline(game_t *game, sfVector2f *points[4])
{
    sfVertexArray *line = sfVertexArray_create();
    sfColor border_color = sfBlack;
    sfVertex v1 = {.position = *points[0], .color = border_color};
    sfVertex v2 = {.position = *points[1], .color = border_color};
    sfVertex v3 = {.position = *points[2], .color = border_color};
    sfVertex v4 = {.position = *points[3], .color = border_color};
    sfVertex v5 = {.position = *points[0], .color = border_color};

    sfVertexArray_append(line, v1);
    sfVertexArray_append(line, v2);
    sfVertexArray_append(line, v3);
    sfVertexArray_append(line, v4);
    sfVertexArray_append(line, v5);
    sfVertexArray_setPrimitiveType(line, sfLineStrip);
    sfRenderWindow_drawVertexArray(game->window, line, NULL);
    sfVertexArray_destroy(line);
}

static sfTexture *get_tile_texture(map_t *map, int y, int x)
{
    if (!map || !map->tile_textures || y >= map->map_height ||
        x >= map->map_width || !map->tile_textures[y])
        return map->texture;
    if (map->tile_textures[y][x])
        return map->tile_textures[y][x];
    return map->texture;
}

static void draw_quad_for_tile(game_t *game, map_t *map, int y, int x)
{
    sfVector2f *quad_points[4] = {NULL, NULL, NULL, NULL};
    sfRenderStates states;
    sfVertexArray *quad;

    quad_points[0] = &map->iso_map[y][x];
    quad_points[1] = &map->iso_map[y][x + 1];
    quad_points[2] = &map->iso_map[y + 1][x + 1];
    quad_points[3] = &map->iso_map[y + 1][x];
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = get_tile_texture(map, y, x);
    states.shader = NULL;
    quad = draw_quad(quad_points, states.texture);
    if (!quad)
        return;
    sfRenderWindow_drawVertexArray(game->window, quad, &states);
    sfVertexArray_destroy(quad);
    draw_quad_outline(game, quad_points);
}

int create_map_grid(game_t *game, map_t *map, int y)
{
    if (!map || !map->iso_map || y >= map->map_height - 1)
        return 84;
    for (int x = 0; x < map->map_width - 1; x++) {
        if (!map->iso_map[y] || !map->iso_map[y + 1] ||
            x >= map->map_width - 1)
            continue;
        draw_quad_for_tile(game, map, y, x);
    }
    return 0;
}

int draw_2d_map(game_t *game, map_t *map)
{
    for (int y = 0; y < map->map_height - 1; y++) {
        if (create_map_grid(game, map, y) == 84)
            return 84;
    }
    return 0;
}
