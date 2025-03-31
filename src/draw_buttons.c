/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** draw_buttons.c
*/

#include "my_world.h"


void draw_terraform_buttons(game_t *game, buttons_t *current)
{
    if (strcmp(game->state_mode, "terraform") == 0) {
        if (strcmp(current->name, "temp_plus") == 0 || strcmp(current->name,
            "temp_minus") == 0 || strcmp(current->name, "temp_reset") == 0)
            sfRenderWindow_drawSprite(game->window, current->sprite, NULL);
    }
}

void draw_texture_buttons(game_t *game, buttons_t *current)
{
    if (strcmp(game->state_mode, "textures") == 0) {
        if (strcmp(current->name, "state_grass") == 0 ||
            strcmp(current->name, "state_water") == 0 ||
            strcmp(current->name, "state_stone") == 0)
            sfRenderWindow_drawSprite(game->window, current->sprite, NULL);
    }
}

void draw_no_state_buttons(game_t *game, buttons_t *current)
{
    if (strcmp(current->name, "temp_quit") == 0 || strcmp(current->name,
        "sound") == 0 || strcmp(current->name, "state_terraform") == 0 ||
        strcmp(current->name, "state_textures") == 0 || strcmp(current->name,
        "temp_save") == 0 || strcmp(current->name, "temp_zoom") == 0 ||
        strcmp(current->name, "temp_dezoom") == 0)
        sfRenderWindow_drawSprite(game->window, current->sprite, NULL);
}

void draw_buttons(game_t *game, buttons_t *buttons)
{
    buttons_t *current = NULL;

    current = buttons;
    while (current) {
        draw_terraform_buttons(game, current);
        draw_texture_buttons(game, current);
        draw_no_state_buttons(game, current);
        current = current->next;
    }
}
