CC = cc  
CFLAGS = -Wall -Wextra -Werror -lmlx -lXext -lX11
SRC = main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c split.c helper_parssing1.c \
helper_parssing2.c helper_parssing3.c helper_parssing4.c helper_parssing5.c 

NAME  = so_long
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	${CC} ${SRC} ./libft/libft.a -o $(NAME) ${CFLAGS} 


clean:
	make -C ./libft/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean

re: fclean all