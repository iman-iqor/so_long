/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parssing5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:27:07 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/15 01:16:37 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_map(t_map *map)
{
	get_coordinates_player(map, 'P');
	get_coordinates_exit(map, 'E');
	map->line_count = map_lines_count(map->map_two_d);
}

void	get_coordinates_exit(t_map *map, char c)
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
				map->exit_x = j;
				map->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_exit(t_map *map)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (map->map_two_d[i])
	{
		if (ft_strchr(map->map_two_d[i], 'E') && flag == 0)
			flag = 1;
		else if (ft_strchr(map->map_two_d[i], 'E') && flag == 1)
		{
			write(2, "Error\n : invalid map too many E\n", 33);
			ftt_free(map->map_two_d);
			ftt_free(map->map_two_d2);
			free(map->lines);
			exit(1);
		}
		i++;
	}
	if (!flag)
	{
		check_exit_error(map);
	}
}

void	join_lines_error(char *s, char *str)
{
	write(2, "Error\n :invalid map has newlines\n", 34);
	free(s);
	free(str);
	exit(1);
}
