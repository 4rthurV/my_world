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

static void exit_texture_mode(game_t *game, buttons_t *current,
    buttons_t *buttons)
{
    current->phase = 0;
    switch_textures(current);
    change_mode_name(game, "view");
    reset_texture_states(buttons);
}

void handle_texture_mode(game_t *game, buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current && current->name) {
        if (strcmp(current->name, "state_textures") == 0
            && button_is_clicked(game, current)) {
            exit_texture_mode(game, current, buttons);
            return;
        }
        current = current->next;
    }
    if (strcmp(game->state_mode, "textures") == 0) {
        handle_texture_buttons(game, buttons);
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
        return;
    }
    handle_view_mode(game, buttons);
}

void check_clicks(game_t *game, buttons_t *buttons, map_t *map)
{
    update_view_key_arrows(game, map);
    handle_mode(game, buttons, map);
}
