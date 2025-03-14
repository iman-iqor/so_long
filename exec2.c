#include "header.h"

void	success(t_imane *imane, int new_x, int new_y)
{
	char	e;

	e = imane->map->map_two_d2[new_y][new_x];
	if (e == 'E' && imane->map->total_c == imane->map->c_count)
	{
		write(1, "success!\n", 9);
		close_window(imane);
		
		exit(0);
	}
}

void	fix_door(t_imane *imane, int new_x, int new_y)
{
	char	e;

	e = imane->map->map_two_d2[new_y][new_x];
	if (e != imane->map->map_two_d2[imane->map->exit_y][imane->map->exit_x])
		imane->map->map_two_d2[imane->map->exit_y][imane->map->exit_x] = 'E';
}

void	move_player(t_imane *imane, int x, int y)
{
	static int moves;
	int new_x;
	int new_y;

	printf("Moves: %d\n", ++moves);
	new_x = imane->map->player_x + x;
	new_y = imane->map->player_y + y;
	if (imane->map->map_two_d2[new_y][new_x] == '1')
		return ;
	success(imane, new_x, new_y);
	if (imane->map->map_two_d2[new_y][new_x] == 'C')
		imane->map->c_count++;
	imane->map->map_two_d2[imane->map->player_y][imane->map->player_x] = '0';
	imane->map->player_x = new_x;
	imane->map->player_y = new_y;
	imane->map->map_two_d2[new_y][new_x] = 'P';
	fix_door(imane, new_x, new_y);
	render_image(imane->game, imane->map->map_two_d2);
}
