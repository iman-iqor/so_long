#ifndef HEADER_H
# define HEADER_H

typedef struct s_state
{
	int		i;
	int		cw;
	int		start;
	int		end;
	int		k;
	char	**two_d;
}			t_state;

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*ft_ssstrjoin(char *save, char *buff);
char		*ftt_free(char **arr);
char		*ft_strncopy(char *str, int start, int end);
int			count_word(char *args,char sep);
void	init_state(t_state *state, char *args,char sep);
char	**split_lines(char *args,char sep);
void check_extention(char *argv);
void check_argc(int argc);
int check_if_file_exist(char* argv);
char* join_lines(char* argv);
void check_is_square(char** two_d,char* lines);

#endif