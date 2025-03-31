##
## EPITECH PROJECT, 2024
## makefile
## File description:
## for compilation
##

SRC	=	my_put_nbr.c\
		my_putchar.c\
		my_putstr.c\
		my_revstr.c\
		my_str_isalpha.c\
		my_str_islower.c\
		my_str_isnum.c\
		my_str_isprintable.c\
		my_str_isupper.c\
		my_str_to_word_array.c\
		my_strcat.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strdup.c\
		my_strlen.c\
		my_strlowcase.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\
		my_strstr.c\
		my_strupcase.c\

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

CFLAGS =	-Wall -Wextra -I.

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
