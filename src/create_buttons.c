/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** init_buttons.c
*/

#include "my_world.h"

char *concat_image_path(char *image_path, char *name)
{
    size_t path_len = strlen(image_path) + strlen(name) + 5;
    char *full_path = NULL;

    if (!image_path || !name)
        return NULL;
    full_path = malloc(path_len);
    if (!full_path)
        return NULL;
    strcpy(full_path, image_path);
    strcat(full_path, name);
    strcat(full_path, ".png");
    return full_path;
}

void setup_button_sprite(buttons_t *new_button,
    sfVector2f button_pos, char *name)
{
    new_button->sprite = sfSprite_create();
    sfSprite_setTexture(new_button->sprite, new_button->texture, sfTrue);
    sfSprite_setScale(new_button->sprite, (sfVector2f){6.0f, 6.0f});
    sfSprite_setPosition(new_button->sprite, button_pos);
    new_button->phase = 0;
    new_button->pos = button_pos;
    new_button->name = strdup(name);
    new_button->next = NULL;
}

buttons_t *create_button(sfVector2f button_pos,
    char *image_path, char *name)
{
    buttons_t *new_button = malloc(sizeof(buttons_t));
    char *full_path = NULL;

    if (!new_button || !image_path || !name)
        return NULL;
    full_path = concat_image_path(image_path, name);
    if (!full_path) {
        free(new_button);
        return NULL;
    }
    new_button->texture = sfTexture_createFromFile(full_path, NULL);
    free(full_path);
    if (!new_button->texture) {
        free(new_button);
        return NULL;
    }
    setup_button_sprite(new_button, button_pos, name);
    return new_button;
}

void add_button(buttons_t **head, sfVector2f pos,
    char *image_path, char *name)
{
    buttons_t *new_button = create_button(pos, image_path, name);
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
        "graphics/idle/", "temp_quit");
    add_button(&buttons,
        (sfVector2f){10, 10},
        "graphics/idle/", "temp_save");
    add_button(&buttons,
        (sfVector2f){game->window_size.x - 230, 10},
        "graphics/idle/", "sound");
    init_terraform_buttons(buttons);
    init_textures_buttons(buttons);
    return buttons;
}
