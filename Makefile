NAME = fdf
SRCS_NAME =		main.c					\
				draw.c					\
				map.c					\
				parsing.c

OBJS = $(SRCS_NAME:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	clang $(SRCS_NAME) -I libft -L libft -lft -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

clean :
	rm -f $(OBJS)
