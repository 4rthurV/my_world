/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** button_clicked.c
*/

#include "my_world.h"

int button_is_clicked(game_t *game, buttons_t *current)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect button_bounds = sfSprite_getGlobalBounds(current->sprite);

    if (sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y)
        && game->event.type == sfEvtMouseButtonPressed
        && game->event.mouseButton.button == sfMouseLeft) {
        if (game->sounds->sound_on == true)
            sfMusic_play(game->sounds->click);
        return 1;
    }
    return 0;
}

bool check_click_on_button(game_t *game, buttons_t *buttons,
    char *button_name)
{
    buttons_t *current = buttons;

    while (current) {
        if (strcmp(current->name, button_name) == 0 &&
            button_is_clicked(game, current)) {
            return true;
        }
        current = current->next;
    }
    return false;
}
