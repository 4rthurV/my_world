/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** click_quit.c
*/

#include "my_world.h"

int click_quitbutton(game_t *game, buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current)
        return 84;
    while (current && current->name) {
        if (strcmp(current->name, "temp_quit") == 0
        && button_is_clicked(game, current))
            return 1;
        current = current->next;
    }
    return 0;
}
