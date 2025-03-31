/*
** EPITECH PROJECT, 2024
** G-ING-200-LIL-2-1-myworld-arthur.vignes
** File description:
** my_world.h
*/

#ifndef MY_WORLD
    #define MY_WORLD
    #define MAP_WIDTH   11
    #define MAP_HEIGHT   11
    #define TILE_SIZE   64
    #define M_PI 3.14159265358979323846

    #include <stdbool.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <float.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <math.h>
    #include <string.h>
    #include <stdbool.h>

typedef struct tile_s {
    double tile_x;
    double tile_y;
    struct tile_s *next;
} tile_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfVector2f window_size;
    int angle_x;
    int angle_y;
    char *state_mode;
} game_t;

typedef struct map_s {
    int **array_map;
    int map_height;
    int map_width;
    int tile_size;
    sfVector2f **iso_map;
    sfTexture *texture;
    sfTexture ***tile_textures;
} map_t;

typedef struct buttons_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    char *name;
    int phase;
    int temp;
    struct buttons_s *next;
} buttons_t;

tile_t *generate_tile_map(int map[MAP_HEIGHT][MAP_WIDTH]);
sfVector2f **create_2d_map(game_t *game, map_t *map);
int free_tile_map(sfVector2f **tile_map, int map_height);
tile_t *create_tile(sfVector2f new_tile, int z);
double project_iso_point_x(game_t *game, int x, int y);
double project_iso_point_y(game_t *game, int x, int y, int z);
void fill_iso_map(game_t *game, map_t *map);
void init_game(game_t *game);
sfVertexArray *create_quad(sfVector2f *p1, sfVector2f *p2,
    sfVector2f *p3, sfVector2f *p4);
void draw_quad_outline(game_t *game, sfVector2f *points[4]);
int create_map_grid(game_t *game, map_t *map, int y);
int draw_2d_map(game_t *game, map_t *map);
sfVector2f **allocate_iso_map_rows(void);
bool allocate_iso_map_columns(sfVector2f **iso_map);
int **create_zeroed_map(int width, int height);
void free_map(map_t *map);
map_t *init_map(void);
void update_view_key_arrows(game_t *game, map_t *map);
void view_point_events(map_t *map, game_t *game);
bool resize_iso_map(game_t *game, map_t *map);
bool resize_array_map(map_t *map, int new_width, int new_height);
void free_iso_map_partial(sfVector2f **iso_map, int num_rows);
int handle_resize_map(game_t *game, map_t *map, bool increase);
void reset_resize_event(game_t *game, buttons_t *buttons, int *resized);
void handle_resize_event(game_t *game, buttons_t *buttons,
    map_t *map, int *resized);
buttons_t *init_buttons(game_t *game);
void free_buttons(buttons_t *buttons);
void free_all(map_t *map, buttons_t *buttons, game_t *game);
void check_hover(game_t *game, buttons_t *buttons);
char *concat_image_path(char *image_path, char *name);
int click_quitbutton(game_t *game, buttons_t *buttons);
void check_clicks(game_t *game, buttons_t *buttons, map_t *map);
void switch_textures(buttons_t *current);
int button_is_clicked(game_t *game, buttons_t *current);
void flip_other_buttons_state(buttons_t *buttons, char *new_button_state);
void handle_view_mode(game_t *game, buttons_t *buttons);
void change_mode_name(game_t *game, char *new_mode);
bool duplicate_maps_one_smaller(map_t *map, int ***new_array_map,
    sfVector2f ***new_iso_map);
bool duplicate_maps_one_bigger(map_t *map, int ***new_array_map,
    sfVector2f ***new_iso_map);
void free_maps(int **array_map, sfVector2f **iso_map, int map_height);
void add_button(buttons_t **head, sfVector2f pos,
    char *image_path, char *name);
void init_terraform_buttons(buttons_t *buttons);
void init_no_state_buttons(game_t *game, buttons_t *buttons);
void init_zoom_buttons(game_t *game, buttons_t *buttons);
void draw_buttons(game_t *game, buttons_t *buttons);
void handle_texture_mode(game_t *game, buttons_t *buttons);
void init_textures_buttons(buttons_t *buttons);
void handle_texture_buttons(game_t *game, buttons_t *buttons);
void handle_terraform_mode(game_t *game, buttons_t *buttons, map_t *map);
void handle_zoom_dezoom(map_t *map, game_t *game, buttons_t *buttons);
bool check_click_on_button(game_t *game, buttons_t *buttons,
    char *button_name);
void change_tile_texture(map_t *map, game_t *game, buttons_t *buttons);
sfTexture *load_texture_by_name(char *texture_name);
void free_tile_textures(map_t *map);
#endif
