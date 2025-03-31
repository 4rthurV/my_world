/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** draw_map.c
*/

#include "my_world.h"

sfVertexArray *create_quad(sfVector2f *p1, sfVector2f *p2,
    sfVector2f *p3, sfVector2f *p4)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor color_1 = sfColor_fromRGB(100, 100, 255);
    sfColor color_2 = sfColor_fromRGB(150, 150, 200);
    sfColor color_3 = sfColor_fromRGB(120, 120, 120);
    sfColor color_4 = sfColor_fromRGB(80, 255, 255);
    sfVertex v1 = {.position = *p1, .color = color_1};
    sfVertex v2 = {.position = *p2, .color = color_2};
    sfVertex v3 = {.position = *p3, .color = color_3};
    sfVertex v4 = {.position = *p4, .color = color_4};

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
    sfColor border_color = sfWhite;
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

int create_map_grid(game_t *game, sfVertexArray *quad,
    sfVector2f **map, int y)
{
    sfVector2f *quad_points[4] = {NULL, NULL, NULL, NULL};

    for (int x = 0; x < MAP_HEIGHT - 1; x++) {
        quad = create_quad(&map[y][x], &map[y][x + 1],
            &map[y + 1][x + 1], &map[y + 1][x]);
        if (!quad)
            return 84;
        sfRenderWindow_drawVertexArray(game->window, quad, NULL);
        sfVertexArray_destroy(quad);
        quad_points[0] = &map[y][x];
        quad_points[1] = &map[y][x + 1];
        quad_points[2] = &map[y + 1][x + 1];
        quad_points[3] = &map[y + 1][x];
        draw_quad_outline(game, quad_points);
    }
    return 0;
}

int draw_2d_map(game_t *game, sfVector2f **map)
{
    sfVertexArray *quad = NULL;

    for (int y = 0; y < MAP_WIDTH - 1; y++) {
        if (create_map_grid(game, quad, map, y) == 84)
            return 84;
    }
    return 0;
}
