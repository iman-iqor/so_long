/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:39:51 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/15 01:16:20 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft(t_data *data)
{
	data->map->map_two_d = split_lines(data->map->lines, '\n');
	data->map->map_two_d2 = split_lines(data->map->lines, '\n');
	check_is_square(data->map);
	check_player(data->map);
	check_exit(data->map);
	check_coins(data->map);
	is_closed_walls(data->map);
	check_only_charachters(data->map);
	init_map(data->map);
	is_valid_map(data->map, data->count);
	init_game(data->game, data->map->map_two_d2);
	load_image(data);
	render_image(data->game, data->map->map_two_d2);
	mlx_key_hook(data->game->win, key_handler, data);
	mlx_hook(data->game->win, 17, 0, close_window, data);
	mlx_loop(data->game->mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;
	t_count	count;
	t_data	data;

	data.game = &game;
	data.map = &map;
	data.count = &count;
	ft_memset(data.map, 0, sizeof(t_map));
	ft_memset(data.game, 0, sizeof(t_game));
	check_argc(argc);
	check_extention(argv[1]);
	check_if_file_exist(argv[1]);
	data.map->lines = join_lines(argv[1]);
	ft(&data);
	return (0);
}
