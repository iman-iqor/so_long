CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c

NAME  = so_long
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./ft_printf/
	make -C ./libft/
	${CC} ${CFLAGS} ${SRC} ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)


clean:
	make -C ./libft/ clean
	make -C ./ft_printf/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean
	make -C ./ft_printf/ fclean

re: fclean all