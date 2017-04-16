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

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	clang $(SRCS) $(INC) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : srcs/%.c includes/fdf.h
	$(CC) -c $< -o $@ -I includes -I libft/includes

clean :
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -f $(OBJS)

re : all

test :

.PHONY : all, clean, fclean, test, re
