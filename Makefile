CC = cc  
CFLAGS = -Wall -Wextra -Werror 
MLX_FLAGS_MAC = -framework OpenGL -framework AppKit -L./minilibx -lmlx
MLX_FLAGS_LINUX = -lmlx -lXext -lX11
SRC = main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c split.c helper_parssing1.c \
helper_parssing2.c helper_parssing3.c helper_parssing4.c helper_parssing5.c 

NAME  = so_long
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	make -C ./minilibx
	${CC} ${SRC} ./libft/libft.a  ./minilibx/libmlx.a -o $(NAME) ${CFLAGS} ${MLX_FLAGS_MAC}


clean:
	make -C ./libft/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean

re: fclean all