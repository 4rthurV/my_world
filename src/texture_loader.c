/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** texture_loader.c
*/

#include "my_world.h"

static sfTexture *create_grass_texture(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "graphics/textures/grass.png", NULL);

    if (texture)
        sfTexture_setRepeated(texture, sfTrue);
    return texture;
}

static sfTexture *create_water_texture(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "graphics/textures/water.png", NULL);

    if (texture)
        sfTexture_setRepeated(texture, sfTrue);
    return texture;
}

static sfTexture *create_sand_texture(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "graphics/textures/sand.png", NULL);

    if (texture)
        sfTexture_setRepeated(texture, sfTrue);
    return texture;
}

static sfTexture *create_stone_texture(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "graphics/textures/stone.png", NULL);

    if (texture)
        sfTexture_setRepeated(texture, sfTrue);
    return texture;
}

sfTexture *load_texture_by_name(char *texture_name)
{
    if (strcmp(texture_name, "grass") == 0)
        return create_grass_texture();
    if (strcmp(texture_name, "water") == 0)
        return create_water_texture();
    if (strcmp(texture_name, "stone") == 0)
        return create_stone_texture();
    if (strcmp(texture_name, "sand") == 0)
        return create_sand_texture();
    return NULL;
}
