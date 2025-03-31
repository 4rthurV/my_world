/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** hover.c
*/

#include "my_world.h"

void replace_texture(buttons_t *current, char *state)
{
    char *full_path = NULL;

    full_path = concat_image_path(state, current->name);
    if (!full_path)
        return;
    if (current->texture)
        sfTexture_destroy(current->texture);
    current->texture = sfTexture_createFromFile(full_path, NULL);
    free(full_path);
    if (!current->texture)
        return;
    sfSprite_setTexture(current->sprite, current->texture, sfTrue);
    sfSprite_setScale(current->sprite, (sfVector2f){6.0f, 6.0f});
    sfSprite_setPosition(current->sprite, current->pos);
}

void switch_textures(buttons_t *current)
{
    char *state = NULL;

    if (current->phase == 0)
        state = "graphics/idle/";
    else if (current->phase == 1)
        state = "graphics/hover/";
    if (state)
        replace_texture(current, state);
}

void update_button_state(buttons_t *current, sfFloatRect button_bounds,
    sfVector2i mouse_pos)
{
    if (sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y)) {
        if (current->phase == 0) {
            current->phase = 1;
            switch_textures(current);
        }
    } else {
        if (current->phase == 1) {
            current->phase = 0;
            switch_textures(current);
        }
    }
}

void check_hover(game_t *game, buttons_t *buttons)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    buttons_t *current = buttons;
    sfFloatRect button_bounds = {0, 0, 0, 0};

    if (!buttons)
        return;
    while (current && current->sprite && current->name) {
        button_bounds = sfSprite_getGlobalBounds(current->sprite);
        update_button_state(current, button_bounds, mouse_pos);
        current = current->next;
    }
}
