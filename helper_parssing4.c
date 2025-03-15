/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parssing4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:26:00 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/15 00:33:05 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_only_charachters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_two_d[i])
	{
		j = 0;
		while (map->map_two_d[i][j])
		{
			if (map->map_two_d[i][j] != '1' && map->map_two_d[i][j] != 'C'
				&& map->map_two_d[i][j] != 'P' && map->map_two_d[i][j] != 'E'
				&& map->map_two_d[i][j] != '0')
			{
				write(1, "Error\n : invalid map strange char\n", 35);
				ftt_free(map->map_two_d);
				ftt_free(map->map_two_d2);
				free(map->lines);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	map_lines_count(char **two_d)
{
	int	i;

	i = 0;
	while (two_d[i])
	{
		i++;
	}
	return (i);
}

void	flood_fill(t_map *map, int x, int y, t_count *count)
{
	if (x < 0 || x > ft_strlen(map->map_two_d[0]) || y < 0
		|| y > map_lines_count(map->map_two_d))
		exit(1);
	if (map->map_two_d[y][x] == '1' || map->map_two_d[y][x] == 'V')
		return ;
	if (map->map_two_d[y][x] == 'C')
		count->c_count++;
	if (map->map_two_d[y][x] == 'E')
		count->e_found = 1;
	map->map_two_d[y][x] = 'V';
	flood_fill(map, x + 1, y, count);
	flood_fill(map, x - 1, y, count);
	flood_fill(map, x, y + 1, count);
	flood_fill(map, x, y - 1, count);
}

void	is_valid_map(t_map *map, t_count *count)
{
	count->c_count = 0;
	count->e_found = 0;
	flood_fill(map, map->player_x, map->player_y, count);
	if (count->c_count != map->total_c || !count->e_found)
	{
		write(2, "Error\n : not valid flood fill\n", 31);
		ftt_free(map->map_two_d);
		ftt_free(map->map_two_d2);
		free(map->lines);
		exit(1);
	}
}

void	get_coordinates_player(t_map *map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_two_d[i])
	{
		j = 0;
		while (map->map_two_d[i][j])
		{
			if (map->map_two_d[i][j] == c)
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
