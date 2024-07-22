##
## EPITECH PROJECT, 2023
## B-MUL-100-TLS-1-1-myradar-dytoma.batogouma
## File description:
## Makefile
##

# SRC	=	main.c	\
# 		button_events.c	\
# 		design.c	\
# 		button_png_txt.c	\
# 		destroy_elements.c	\
# 		draw_elements.c	\
# 		button_svg.c	\
# 		events.c	\
# 		my_str_capitalize.c	\
# 		drop_menu.c	\
# 		top_menu.c	\
# 		drop_menu_txt.c	\
# 		draw_components.c	\
# 		destroy_components.c	\
# 		init_pixels.c	\
# 		draw_on_board.c	\
# 		save_file.c	\

SRC =	$(wildcard src/*.c) 

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm -Iinclude/

NAME	=	my_paint

$(NAME):    make_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./ -lmy -Iinclude/

all:    $(NAME)

make_lib:
	make -C ./printf
	mv ./printf/libmy.a ./
	make fclean -C ./printf

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f '#*#'
	clear

fclean: clean
	rm -f $(NAME)
	clear

re:	fclean all
