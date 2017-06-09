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
INC = -I includes -I minilibx_macos -I libft/includes
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	clang $(SRCS) $(FLAGS) $(INC) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : srcs/%.c includes/fdf.h
	$(CC) $(FLAGS) -c $< -o $@ -I includes -I libft/includes -I minilibx_macos

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
