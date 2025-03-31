/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** sounds.c
*/

#include "my_world.h"

int init_sounds(game_t *game)
{
    game->sounds->music = sfMusic_createFromFile("audios/music.ogg");
    if (!game->sounds->music)
        return 84;
    sfMusic_setVolume(game->sounds->music, 120);
    game->sounds->click = sfMusic_createFromFile("audios/button_click.ogg");
    if (!game->sounds->click)
        return 84;
    sfMusic_setVolume(game->sounds->click, 80);
    game->sounds->sound_on = true;
    return 0;
}

void switch_sound_state(buttons_t *current)
{
    if (current->phase == 0 || current->phase == 1)
        current->phase = 2;
    else if (current->phase == 2)
        current->phase = 0;
}

void check_sounds(game_t *game, buttons_t *buttons)
{
    buttons_t *current = buttons;

    if (!current || !game->sounds || !game->sounds->music)
        return;
    while (current && current->name) {
        if (strcmp(current->name, "sound") == 0 &&
            button_is_clicked(game, current)) {
            game->sounds->sound_on = !game->sounds->sound_on;
            switch_sound_state(current);
            switch_textures(current);
        }
        current = current->next;
    }
    if (game->sounds->sound_on) {
        if (sfMusic_getStatus(game->sounds->music) == sfPaused ||
            sfMusic_getStatus(game->sounds->music) != sfPlaying)
            sfMusic_play(game->sounds->music);
    } else if (sfMusic_getStatus(game->sounds->music) == sfPlaying)
        sfMusic_pause(game->sounds->music);
}
