/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:22:39 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/15 01:14:01 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_game(t_game *game, char **two_d)
{
	int	rows;
	int	columns;

	rows = map_lines_count(two_d);
	columns = ft_strlen(two_d[0]);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error \n:failed to init mlx\n", 28);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, columns * 67, rows * 67, "so_long");
	if (!game->win)
	{
		write(2, "Error\nfailed to create window\n", 32);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}

void	image_fail_to_load(t_data *data)
{
	t_game	*game;

	game = data->game;
	if (!game->player_img || !game->coin_img || !game->wall_img
		|| !game->exit_img || !game->background_img)
	{
		write(2, "Error\n :could not load one or more images\n", 43);
		if (game->coin_img)
			mlx_destroy_image(game->mlx, game->coin_img);
		if (game->player_img)
			mlx_destroy_image(game->mlx, game->player_img);
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
		if (game->background_img)
			mlx_destroy_image(game->mlx, game->background_img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(data->game->mlx);
		free(data->game->mlx);
		free(data->map->lines);
		ftt_free(data->map->map_two_d2);
		ftt_free(data->map->map_two_d);
		exit(1);
	}
}

void	load_image(t_data *data)
{
	t_game	*game;

	game = data->game;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "pics/player1.xpm",
			&game->img_width, &game->img_height);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "pics/coin1.xpm",
			&game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "pics/wall1.xpm",
			&game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "pics/door1.xpm",
			&game->img_width, &game->img_height);
	game->background_img = mlx_xpm_file_to_image(game->mlx,
			"pics/background1.xpm", &game->img_width, &game->img_height);
	image_fail_to_load(data);
}

void	render_image(t_game *game, char **two_d)
{
	int (x), (y);
	y = 0;
	game->var = NULL;
	while (two_d[y])
	{
		x = 0;
		while (two_d[y][x])
		{
			if (two_d[y][x] == 'P')
				game->var = game->player_img;
			else if (two_d[y][x] == 'C')
				game->var = game->coin_img;
			else if (two_d[y][x] == '0')
				game->var = game->background_img;
			else if (two_d[y][x] == '1')
				game->var = game->wall_img;
			else if (two_d[y][x] == 'E')
				game->var = game->exit_img;
			if (game->var)
				mlx_put_image_to_window(game->mlx, game->win, game->var, x * 67,
					y * 67);
			x++;
		}
		y++;
	}
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		close_window(data);
	}
	if (keycode == 'w' || keycode == UP)
		move_player(data, 0, -1);
	else if (keycode == 's' || keycode == DOWN)
		move_player(data, 0, 1);
	else if (keycode == 'd' || keycode == RIGHT)
		move_player(data, 1, 0);
	else if (keycode == 'a' || keycode == LEFT)
		move_player(data, -1, 0);
	return (0);
}
