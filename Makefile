##
## EPITECH PROJECT, 2024
## makefile
## File description:
## for compilation
##

SRC	=	src/main.c \
        src/tridim_to_bidim.c \
        src/free.c \
        src/tile.c \
        src/init_resources.c \
        src/draw_map.c \
        src/camera_view.c \
        src/click_terraform.c \
        src/duplicate_map.c \
        src/resize_map.c \
        src/create_buttons.c \
        src/hover.c \
        src/click_quit.c \
        src/check_clicks.c \
        src/terraform_mode.c \
        src/texture_mode.c \
        src/view_mode.c \
        src/init_buttons.c \
        src/draw_buttons.c \
        src/zoom_dezoom.c \
        src/button_clicked.c \
        src/texture_tile.c \
        src/texture_loader.c \
        src/free_resources.c \
        src/help.c \
        src/sounds.c

OBJ	=	$(SRC:.c=.o)

EXE_NAME	=	my_world

CFLAGS	+=	-Wall -Wextra -Iinclude -g
CSFMLFLAGS	=  -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:	$(EXE_NAME)

$(EXE_NAME): $(OBJ)
	gcc -o $(EXE_NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS)

debug: CFLAGS += -g
debug: re
	valgrind ./$(EXE_NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE_NAME)

re: fclean all
