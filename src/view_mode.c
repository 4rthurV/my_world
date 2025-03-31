/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** view_mode.c
*/

#include "my_world.h"

void change_mode_name(game_t *game, char *new_mode)
{
    free(game->state_mode);
    game->state_mode = strdup(new_mode);
}

void handle_view_mode(game_t *game, buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current && current->name) {
        if (strcmp(current->name, "state_terraform") == 0
        && button_is_clicked(game, current)) {
            current->phase = 2;
            switch_textures(current);
            flip_other_buttons_state(buttons, current->name);
            change_mode_name(game, "terraform");
            return;
        }
        current = current->next;
    }
}
