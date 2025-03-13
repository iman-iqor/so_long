
#include "header.h"









int	main(int argc, char **argv)
{
	t_map map;
	t_game game;
	t_imane ahmed;
	ahmed.game = &game;
	ahmed.map = &map;

	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&game, 0, sizeof(t_game));

	check_argc(argc);

	check_extention(argv[1]);
	check_if_file_exist(argv[1]);

	map.lines = join_lines(argv[1]);

	map.map_two_d = split_lines(map.lines, '\n');
	map.map_two_d2 = split_lines(map.lines, '\n');
	check_is_square(map.map_two_d, map.lines);
	check_player(map.map_two_d, map.lines);
	check_exit(map.map_two_d, map.lines);
	check_coins(map.map_two_d, map.lines, &map.total_c);
	is_closed_walls(map.map_two_d, map.lines);
	check_only_charachters(map.map_two_d, map.lines);
	init_map(&map, map.map_two_d, map.lines);
	is_valid_map(&map, map.player_x, map.player_y, map.total_c);
	// check the lngh is not greater than something chi haja

	init_game(&game, map.map_two_d2);
	load_image(&ahmed);
	render_image(&game, map.map_two_d2);
	mlx_key_hook(game.win, key_handler, &ahmed);
	mlx_hook(game.win, 17, 0, close_window, &ahmed);
	mlx_loop(game.mlx);

	return (0);
}