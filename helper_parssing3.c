/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parssing3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:25:41 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/15 00:25:48 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	countcharinline(char *text, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (text[i])
	{
		if (text[i++] == c)
			count++;
	}
	return (count);
}

void	check_coins(t_map *map)
{
	int	i;

	map->total_c = 0;
	i = 0;
	while (map->map_two_d[i])
	{
		(map->total_c) += countcharinline(map->map_two_d[i], 'C');
		i++;
	}
	if (!(map->total_c))
	{
		write(2, "Error\n : invalid map no coins\n", 31);
		ftt_free(map->map_two_d);
		ftt_free(map->map_two_d2);
		free(map->lines);
		exit(1);
	}
}

void	init_closed(t_closed *closed, char **two_d)
{
	closed->len = 0;
	closed->i = 0;
	closed->j = ft_strlen(*two_d);
}

void	closed_error(t_map *map)
{
	write(1, "Error\n :invalid map not closed\n", 32);
	free(map->lines);
	ftt_free(map->map_two_d);
	ftt_free(map->map_two_d2);
	exit(1);
}

void	is_closed_walls(t_map *map)
{
	t_closed	closed;

	init_closed(&closed, map->map_two_d);
	while (map->map_two_d[closed.len])
	{
		closed.len++;
	}
	closed.len--;
	while (map->map_two_d[0][closed.i])
	{
		if (map->map_two_d[0][closed.i] != '1'
			|| map->map_two_d[closed.len][closed.i] != '1')
			closed_error(map);
		closed.i++;
	}
	closed.i = 0;
	closed.j--;
	while (closed.len >= closed.i)
	{
		if (map->map_two_d[closed.i][0] != '1'
			|| map->map_two_d[closed.i][closed.j] != '1')
			closed_error(map);
		closed.i++;
	}
}
