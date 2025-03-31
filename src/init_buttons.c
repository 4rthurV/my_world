/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** init_buttons.c
*/

#include "my_world.h"

void init_zoom_buttons(game_t *game, buttons_t *buttons)
{
    add_button(&buttons, (sfVector2f){game->window_size.x - 110, 210},
        "graphics/idle/", "temp_zoom");
    add_button(&buttons, (sfVector2f){game->window_size.x - 110, 330},
        "graphics/idle/", "temp_dezoom");
}

void init_no_state_buttons(game_t *game, buttons_t *buttons)
{
    add_button(&buttons, (sfVector2f){10, 10}, "graphics/idle/",
        "temp_save");
    add_button(&buttons, (sfVector2f){game->window_size.x - 230, 10},
        "graphics/idle/", "sound");
}

void init_terraform_buttons(buttons_t *buttons)
{
    add_button(&buttons,
        (sfVector2f){10, 150}, "graphics/idle/", "state_terraform");
    add_button(&buttons, (sfVector2f){130, 160},
    "graphics/idle/", "temp_plus");
    add_button(&buttons, (sfVector2f){130, 290},
    "graphics/idle/", "temp_minus");
    add_button(&buttons, (sfVector2f){130, 420},
        "graphics/idle/", "temp_reset");
}

void init_textures_buttons(buttons_t *buttons)
{
    add_button(&buttons,
        (sfVector2f){10, 900}, "graphics/idle/", "state_textures");
    add_button(&buttons,
        (sfVector2f){130, 900}, "graphics/idle/", "state_grass");
    add_button(&buttons,
        (sfVector2f){260, 900}, "graphics/idle/", "state_water");
    add_button(&buttons,
        (sfVector2f){390, 900}, "graphics/idle/", "state_stone");
}
