CC = cc  -g3
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS_MAC = -framework OpenGL -framework AppKit -L./minilibx -lmlx
MLX_FLAGS_LINUX = -lmlx -lXext -lX11
SRC = main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c split.c helper_parssing1.c \
helper_parssing2.c helper_parssing3.c helper_parssing4.c helper_parssing5.c exec1.c exec2.c

NAME  = so_long
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	make -C ./ft_printf/
	# make -C ./minilibx/  
	${CC} ${SRC} ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME) ${CFLAGS} ${MLX_FLAGS_LINUX}


clean:
	make -C ./libft/ clean
	make -C ./ft_printf/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean
	make -C ./ft_printf/ fclean

re: fclean all
