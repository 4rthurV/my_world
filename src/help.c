/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** help.c
*/

#include "my_world.h"

void draw_help_panel(game_t *game, panel_t *help_panel)
{
    if (game->help == true)
        sfRenderWindow_drawSprite(game->window, help_panel->sprite, NULL);
}

void handle_help_panel(game_t *game, buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current)
        return;
    while (current && current->name) {
        if (strcmp(current->name, "temp_help") == 0 &&
            button_is_clicked(game, current)) {
            game->help = !game->help;
        }
        current = current->next;
    }
}

static void setup_panel_sprite(panel_t *panel, game_t *game)
{
    sfVector2u texture_size;
    sfVector2f position = {0.0f, 0.0f};
    sfVector2f scale = {4.0f, 4.0f};

    sfSprite_setScale(panel->sprite, scale);
    texture_size = sfTexture_getSize(panel->texture);
    position.x = (game->window_size.x - (texture_size.x * scale.x)) / 2;
    position.y = (game->window_size.y - (texture_size.y * scale.y)) / 2;
    sfSprite_setPosition(panel->sprite, position);
}

panel_t *init_help_panel(game_t *game)
{
    panel_t *panel = malloc(sizeof(panel_t));

    if (!panel)
        return NULL;
    panel->texture = sfTexture_createFromFile("graphics/panel.png", NULL);
    if (!panel->texture) {
        free(panel);
        return NULL;
    }
    panel->sprite = sfSprite_create();
    if (!panel->sprite) {
        sfTexture_destroy(panel->texture);
        free(panel);
        return NULL;
    }
    sfSprite_setTexture(panel->sprite, panel->texture, sfTrue);
    setup_panel_sprite(panel, game);
    return panel;
}
