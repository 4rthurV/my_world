/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** init_buttons.c
*/

#include "my_world.h"

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
        (sfVector2f){10, 960}, "graphics/idle/", "state_textures");
    add_button(&buttons,
        (sfVector2f){130, 960}, "graphics/idle/", "state_grass");
    add_button(&buttons,
        (sfVector2f){260, 960}, "graphics/idle/", "state_water");
    add_button(&buttons,
        (sfVector2f){390, 960}, "graphics/idle/", "state_stone");
}
