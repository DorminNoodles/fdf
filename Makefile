NAME = fdf
NAME_SRCS =		main.c					\
				draw.c					\
				map.c					\
				parsing.c				\
				color.c					\
				init.c					\
				free.c					\
				controller.c

OBJS = $(NAME_SRCS:.c=.o)
SRCS = $(addprefix srcs/,$(NAME_SRCS))
CC = clang
INC = -I includes

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	clang $(SRCS) $(INC) -I libft/includes -L libft -lft -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : srcs/%.c includes/fdf.h
	$(CC) -c $< -o $@ -I includes -I libft/includes

clean :
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -f $(OBJS)

re : fclean all
	make -C libft/ re

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

test :

.PHONY : all, clean, fclean, test, re
