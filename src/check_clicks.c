/*
** EPITECH PROJECT, 2024
** check_clicks
** File description:
** Handles click events
*/

#include "my_world.h"

void flip_other_buttons_state(buttons_t *buttons, char *new_button_state)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current && current->name) {
        if (strncmp(current->name, "state_", 6) == 0
            && strcmp(current->name, new_button_state) != 0) {
            current->phase = 0;
        }
        current = current->next;
    }
}

static void handle_mode(game_t *game, buttons_t *buttons, map_t *map)
{
    if (strcmp(game->state_mode, "terraform") == 0) {
        handle_terraform_mode(game, buttons, map);
        return;
    }
    if (strcmp(game->state_mode, "textures") == 0) {
        handle_texture_mode(game, buttons);
        change_tile_texture(map, game, buttons);
        return;
    }
    handle_view_mode(game, buttons);
}

void check_clicks(game_t *game, buttons_t *buttons, map_t *map)
{
    update_view_key_arrows(game, map);
    handle_mode(game, buttons, map);
}
