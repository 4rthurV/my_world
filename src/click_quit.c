/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** click_quit.c
*/

#include "my_world.h"

int button_is_clicked(game_t *game, buttons_t *current)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect button_bounds = sfSprite_getGlobalBounds(current->sprite);

    if (sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y)
        && game->event.type == sfEvtMouseButtonPressed
        && game->event.mouseButton.button == sfMouseLeft)
        return 1;
    return 0;
}

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
