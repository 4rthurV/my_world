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

LIB_NAME	=	lib/my/libmy.a

CFLAGS	+=	-Wall -Wextra -Iinclude -Ilib/my -lm

all:	$(EXE_NAME)

$(EXE_NAME): $(LIB_NAME) $(OBJ)
	gcc -o $(EXE_NAME) $(OBJ) -Llib/my -lmy $(CFLAGS) -g

$(LIB_NAME):
	make -C lib/my

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(EXE_NAME)
	make -C lib/my fclean

re: fclean all
