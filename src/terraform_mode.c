/*
** EPITECH PROJECT, 2024
** terraform_mode
** File description:
** Handles terraform mode related functions
*/

#include "my_world.h"

static void handle_terraform_exit(game_t *game, buttons_t *current)
{
    current->phase = 0;
    switch_textures(current);
    change_mode_name(game, "view");
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
            handle_terraform_exit(game, current);
            return;
        }
        current = current->next;
    }
}
