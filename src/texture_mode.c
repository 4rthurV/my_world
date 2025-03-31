/*
** EPITECH PROJECT, 2024
** texture_mode
** File description:
** Handles texture mode related functions
*/

#include "my_world.h"

static void reset_texture_states(buttons_t *buttons)
{
    buttons_t *temp = buttons;

    while (temp) {
        if (strcmp(temp->name, "state_grass") == 0 ||
            strcmp(temp->name, "state_water") == 0 ||
            strcmp(temp->name, "state_stone") == 0 ||
            strcmp(temp->name, "state_sand") == 0 ||
            strcmp(temp->name, "state_textures") == 0) {
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
            strcmp(temp->name, "state_stone") == 0 ||
            strcmp(temp->name, "state_sand") == 0) &&
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
            strcmp(current->name, "state_stone") == 0 ||
            strcmp(current->name, "state_sand") == 0) &&
            button_is_clicked(game, current)) {
            handle_texture_button_click(buttons, current);
            return;
        }
        current = current->next;
    }
}

static void exit_texture_mode(game_t *game, buttons_t *current,
    buttons_t *buttons, char *new_mode)
{
    current->phase = 0;
    switch_textures(current);
    change_mode_name(game, new_mode);
    reset_texture_states(buttons);
}

void turn_terraform_mode(buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current) {
        if (strcmp(current->name, "state_terraform") == 0) {
            current->phase = 2;
            switch_textures(current);
            flip_other_buttons_state(buttons, current->name);
            return;
        }
        current = current->next;
    }
}

void handle_texture_mode(game_t *game, buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current && current->name) {
        if (strcmp(current->name, "state_textures") == 0
            && button_is_clicked(game, current)) {
            exit_texture_mode(game, current, buttons, "view");
            return;
        }
        if (strcmp(current->name, "state_terraform") == 0
            && button_is_clicked(game, current)) {
            exit_texture_mode(game, current, buttons, "terraform");
            turn_terraform_mode(buttons);
            return;
            }
        current = current->next;
    }
    if (strcmp(game->state_mode, "textures") == 0)
        handle_texture_buttons(game, buttons);
}
