/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:27:29 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/14 20:27:35 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	success(t_data *data, int new_x, int new_y)
{
	char	e;

	e = data->map->map_two_d2[new_y][new_x];
	if (e == 'E' && data->map->total_c == data->map->c_count)
	{
		write(1, "success!\n", 9);
		close_window(data);
		exit(0);
	}
}

void	fix_door(t_data *data, int new_x, int new_y)
{
	char	e;

	e = data->map->map_two_d2[new_y][new_x];
	if (e != data->map->map_two_d2[data->map->exit_y][data->map->exit_x])
		data->map->map_two_d2[data->map->exit_y][data->map->exit_x] = 'E';
}

void	move_player(t_data *data, int x, int y)
{
	static int	moves;
	int			new_x;
	int			new_y;
	char		*number;

	new_x = data->map->player_x + x;
	new_y = data->map->player_y + y;
	if (data->map->map_two_d2[new_y][new_x] == '1')
		return ;
	ft_printf("Moves: %d\n", ++moves);
	success(data, new_x, new_y);
	if (data->map->map_two_d2[new_y][new_x] == 'C')
		data->map->c_count++;
	data->map->map_two_d2[data->map->player_y][data->map->player_x] = '0';
	data->map->player_x = new_x;
	data->map->player_y = new_y;
	data->map->map_two_d2[new_y][new_x] = 'P';
	fix_door(data, new_x, new_y);
	render_image(data->game, data->map->map_two_d2);
	number = ft_itoa(moves);
	if (number)
		mlx_string_put(data->game->mlx, data->game->win, 10, 10, 0xff0000,
			number);
	free(number);
}
int	close_window(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	ftt_free(data->map->map_two_d);
	ftt_free(data->map->map_two_d2);
	mlx_destroy_image(data->game->mlx, data->game->player_img);
	mlx_destroy_image(data->game->mlx, data->game->coin_img);
	mlx_destroy_image(data->game->mlx, data->game->exit_img);
	mlx_destroy_image(data->game->mlx, data->game->wall_img);
	mlx_destroy_image(data->game->mlx, data->game->background_img);
	mlx_destroy_window(data->game->mlx, data->game->win);
	mlx_destroy_display(data->game->mlx);
	free(data->game->mlx);
	free(data->map->lines);
	exit(0);
}
