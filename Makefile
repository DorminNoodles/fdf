NAME = fdf
SRCS_NAME =		main.c					\
				draw.c

OBJS = $(SRCS_NAME:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C minilibx_macos/
	clang $(SRCS_NAME) -lmlx -framework OpenGL -framework AppKit

clean :
	rm -f $(OBJS)
