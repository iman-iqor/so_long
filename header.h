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

typedef struct s_splayer
{
	int		flag;
	int		i;
	int		player;
}			t_player;

typedef struct s_closed
{
	int		len;
	int		i;
	int		j;
}			t_closed;

typedef struct s_map
{
    int fd;
    int line_count;
    char** map_two_d;
    int player_x;
    int player_y;
    int total_c;
	char* lines;
}   t_map;

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*ft_ssstrjoin(char *save, char *buff);
char		*ftt_free(char **arr);
char		*ft_strncopy(char *str, int start, int end);
int			count_word(char *args, char sep);
void		init_state(t_state *state, char *args, char sep);
char		**split_lines(char *args, char sep);
void		check_extention(char *argv);
void		check_argc(int argc);
int			check_if_file_exist(char *argv);
char		*join_lines(char *argv);
void		check_is_square(char **two_d, char *lines);
void		check_player(char **two_d, char *lines);
void		init_player(t_player *play);
void		check_exit(char **two_d, char *lines);
void		check_coins(char **two_d, char *lines,int* total_coins);
void		init_closed(t_closed *closed, char **two_d);
void		closed_error(char **two_d, char *lines);
void		is_closed_walls(char **two_d, char *lines);
void		check_only_charachters(char **two_d, char *lines);

#endif