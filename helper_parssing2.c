/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parssing2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:25:26 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/15 00:31:36 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_is_square(t_map *map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(map->map_two_d[0]);
	while (map->map_two_d[i])
	{
		if (len != ft_strlen(map->map_two_d[i]))
		{
			write(2, "Error\n : invalid map\n", 22);
			ftt_free(map->map_two_d);
			ftt_free(map->map_two_d2);
			free(map->lines);
			exit(1);
		}
		i++;
	}
}

void	init_player(t_player *play)
{
	play->flag = 0;
	play->i = 0;
	play->player = 0;
}

void	player_error(t_map *map)
{
	write(2, "Error\n : wrong map no player\n", 30);
	ftt_free(map->map_two_d);
	ftt_free(map->map_two_d2);
	free(map->lines);
	exit(1);
	ftt_free(map->map_two_d2);
}

void	check_player(t_map *map)
{
	t_player	play;

	init_player(&play);
	while (map->map_two_d[play.i])
	{
		if (ft_strchr(map->map_two_d[play.i], 'P') && play.flag == 0)
		{
			play.flag = 1;
			play.player = 1;
		}
		else if (ft_strchr(map->map_two_d[play.i], 'P') && play.flag == 1)
		{
			write(2, "Error\n : wrong map too players\n", 32);
			ftt_free(map->map_two_d);
			ftt_free(map->map_two_d2);
			free(map->lines);
			exit(1);
		}
		play.i++;
	}
	if (!play.player)
	{
		player_error(map);
	}
}

void	check_exit_error(t_map *map)
{
	write(2, "Error\ninvalid map no E\n", 24);
	ftt_free(map->map_two_d);
	ftt_free(map->map_two_d2);
	free(map->lines);
	exit(1);
}
