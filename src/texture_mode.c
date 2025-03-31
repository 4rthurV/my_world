/*
** EPITECH PROJECT, 2024
** texture_mode
** File description:
** Handles texture mode related functions
*/

#include "my_world.h"

void reset_texture_states(buttons_t *buttons)
{
    buttons_t *temp = buttons;

    while (temp) {
        if (strcmp(temp->name, "state_grass") == 0 ||
            strcmp(temp->name, "state_water") == 0 ||
            strcmp(temp->name, "state_stone") == 0) {
            temp->phase = 0;
            switch_textures(temp);
        }
        temp = temp->next;
    }
}

static void update_button_states(buttons_t *buttons, buttons_t *current)
{
    buttons_t *temp = buttons;

    while (temp) {
        if ((strcmp(temp->name, "state_grass") == 0 ||
            strcmp(temp->name, "state_water") == 0 ||
            strcmp(temp->name, "state_stone") == 0) &&
            temp != current) {
            temp->phase = 0;
            switch_textures(temp);
        }
        temp = temp->next;
    }
    current->phase = 2;
    switch_textures(current);
}

static void handle_texture_button_click(buttons_t *buttons,
    buttons_t *current)
{
    if (current->phase == 2) {
        current->phase = 0;
        switch_textures(current);
        return;
    }
    update_button_states(buttons, current);
}

void handle_texture_buttons(game_t *game, buttons_t *buttons)
{
    buttons_t *current = buttons;

    while (current && current->name) {
        if ((strcmp(current->name, "state_grass") == 0 ||
            strcmp(current->name, "state_water") == 0 ||
            strcmp(current->name, "state_stone") == 0) &&
            button_is_clicked(game, current)) {
            handle_texture_button_click(buttons, current);
            return;
        }
        current = current->next;
    }
}
