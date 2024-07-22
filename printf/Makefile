##
## EPITECH PROJECT, 2023
## MAKEFILE_INSTRUCTIONS
## File description:
## Build library
##

SRC	=	my_put_s.c	\
		my_put_e.c	\
		my_put_float.c	\
		my_put_hex.c	\
		my_put_nbr.c	\
		my_put_oct.c	\
		my_put_ptr.c	\
		put_zero.c	\
		display.c	\
		my_printf.c	\
		operations.c	\
		my_put_nbr_hex_neg.c	\
		my_put_global.c	\
		print_width.c	\
		print_short.c	\
		print_n_flag.c	\
		print_long.c	\
		print_hashtag.c	\
		print_fplus.c	\
		print_plus.c	\
		print_precision.c	\
		precision.c	\
		my_strlen.c	\
		my_strdup.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strcat.c	\
		my_strncat.c	\
		my_arrdup.c	\
		my_strncmp.c	\
		print_content.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f '#*#'

fclean: clean
	rm -f $(NAME)

re:	fclean all
