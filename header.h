#ifndef HEADER_H
# define HEADER_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "minilibx/mlx.h"

# define ESC 65307 // MacOS: 53, Linux: 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*coin_img;
	void	*wall_img;
	void	*exit_img;
	void	*background_img;
	int		img_width;
	int		img_height;
	void	*var;
}			t_game;

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
	int		fd;
	int		line_count;
	char	**map_two_d;
	char	**map_two_d2;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		total_c;
	int		c_count;
	char	*lines;

}			t_map;

typedef struct
{
	t_game	*game;
	t_map	*map;
}			t_imane;

typedef struct s_count
{
	int		c_count;
	int		E_found;

}			t_count;

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
void		check_is_square(t_map *map);
void		check_player(t_map *map);
void		init_player(t_player *play);
void		check_exit(t_map *map);
void		check_coins(t_map *map);
void		init_closed(t_closed *closed, char **two_d);
void		closed_error(t_map *map);
void		is_closed_walls(t_map *map);
void		check_only_charachters(t_map *map);
int			map_lines_count(char **two_d);
void		flood_fill(t_map *map, int x, int y, t_count *count);
void		is_valid_map(t_map *map);
void		get_coordinates_player(t_map *map, char c);
void		init_map(t_map *map);
void		init_game(t_game *game, char **two_d);
void		load_image(t_imane *t_imane);
void		render_image(t_game *game, char **two_d);
void		get_coordinates_exit(t_map *map, char c);
int			key_handler(int keycode, t_imane *imane);
int			close_window(void *ptr);
void		success(t_imane *imane, int new_x, int new_y);
void		fix_door(t_imane *imane, int new_x, int new_y);
void		move_player(t_imane *imane, int x, int y);
void		player_error(t_map *map);
void		image_fail_to_load(t_imane *imane);
#endif