
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
	check_is_square(&map);
	check_player(&map);
	check_exit(&map);
	check_coins(&map);
	is_closed_walls(&map);
	check_only_charachters(&map);
	init_map(&map);
	is_valid_map(&map);

	init_game(&game, map.map_two_d2);
	load_image(&ahmed);
	render_image(&game, map.map_two_d2);
	mlx_key_hook(game.win, key_handler, &ahmed);
	mlx_hook(game.win, 17, 0, close_window, &ahmed);
	mlx_loop(game.mlx);

	return (0);
}
