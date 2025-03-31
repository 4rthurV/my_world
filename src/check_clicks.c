/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** check_clicks.c
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

void handle_terraform_mode(game_t *game, buttons_t *buttons, map_t *map)
{
    buttons_t *current = buttons;
    static int resized = 0;

    if (!current)
        return;
    handle_resize_event(game, buttons, map, &resized);
    reset_resize_event(game, buttons, &resized);
    if (game->event.type == sfEvtMouseButtonPressed)
        view_point_events(map, game);
    while (current && current->name) {
        if (strcmp(current->name, "state_terraform") == 0
            && button_is_clicked(game, current) && current->phase == 2) {
            current->phase = 0;
            switch_textures(current);
            change_mode_name(game, "view");
            return;
        }
        current = current->next;
    }
}

void check_clicks(game_t *game, buttons_t *buttons, map_t *map)
{
    update_view_key_arrows(game, map);
    if (strcmp(game->state_mode, "view") == 0)
        handle_view_mode(game, buttons);
    else if (strcmp(game->state_mode, "terraform") == 0)
        handle_terraform_mode(game, buttons, map);
}
