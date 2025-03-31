/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** init_buttons.c
*/

#include "my_world.h"

buttons_t *create_button(sfVector2f button_pos, char *text_path)
{
    buttons_t *new_button = malloc(sizeof(buttons_t));

    if (!new_button || !text_path)
        return NULL;
    new_button->texture = sfTexture_createFromFile(text_path, NULL);
    if (!new_button->texture) {
        free(new_button);
        return NULL;
    }
    new_button->sprite = sfSprite_create();
    sfSprite_setTexture(new_button->sprite, new_button->texture, sfTrue);
    sfSprite_setScale(new_button->sprite, (sfVector2f){1.75f, 1.75f});
    sfSprite_setPosition(new_button->sprite, button_pos);
    new_button->state = 0;
    new_button->next = NULL;
    return new_button;
}

void add_button(buttons_t **head, sfVector2f pos, char *text_path)
{
    buttons_t *new_button = create_button(pos, text_path);
    buttons_t *temp = NULL;

    if (!new_button)
        return;
    if (*head == NULL) {
        *head = new_button;
        return;
    }
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_button;
}

buttons_t *init_buttons(game_t *game)
{
    buttons_t *buttons = NULL;

    if (!game)
        return buttons;
    add_button(&buttons,
        (sfVector2f){game->window_size.x - 110, 10},
        "graphics/quit_button.png");
    add_button(&buttons,
        (sfVector2f){game->window_size.x - 220, 10},
        "graphics/sound_on_button.png");
    add_button(&buttons,
        (sfVector2f){10, 10},
        "graphics/sound_off_button.png");
    return buttons;
}
