
#include"header.h"

int	exit_window(int keycode, t_game *game)
{
	int	i;

	if (keycode == ESC)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}

int	on_keypress(int key, t_game *data)
{
	if (key == ESC)
		exit_window(ESC, data);
	else if (key == 'w' || key == UP)
		move_player(data, 0, -1);
	else if (key == 's' || key == DOWN)
		move_player(data, 0, 1);
	else if (key == 'd' || key == RIGHT)
		move_player(data, 1, 0);
	else if (key == 'a' || key == LEFT)
		move_player(data, -1, 0);
	return (0);
}

int main(int argc,char** argv)
{
    t_map map;
    t_game game;

    ft_memset(&map,0,sizeof(t_map));
    ft_memset(&map,0,sizeof(t_game));

    check_argc(argc);
    check_extention(argv[1]);
    check_if_file_exist(argv[1]);
   
    map.lines  = join_lines(argv[1]);
    map.map_two_d = split_lines(map.lines,'\n');
    map.map_two_d2=split_lines(map.lines,'\n');
    check_is_square(map.map_two_d,map.lines);
    check_player(map.map_two_d,map.lines);
    check_exit(map.map_two_d,map.lines);
    check_coins(map.map_two_d,map.lines,&map.total_c);
    is_closed_walls(map.map_two_d,map.lines);
    check_only_charachters(map.map_two_d,map.lines);
    init_map(&map,map.map_two_d,map.lines);
    is_valid_map(&map, map.player_x, map.player_y, map.total_c);





    init_game(&game,map.map_two_d2);
    load_image(&game);
    render_image(&game, map.map_two_d2); 
   
    return 0;
}