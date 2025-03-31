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

OBJ	=	$(SRC:.c=.o)

EXE_NAME	=	my_world

CFLAGS	+=	-Wall -Wextra -Iinclude
CSFMLFLAGS	=  -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:	$(EXE_NAME)

$(EXE_NAME): $(OBJ)
	gcc -o $(EXE_NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE_NAME)

re: fclean all
