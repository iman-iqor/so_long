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
		write(2, "failed to create window\n", 24);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}

void	image_fail_to_load(t_imane *imane)
{
	t_game	*game;

	game = imane->game;
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
		mlx_destroy_display(imane->game->mlx);
		free(imane->game->mlx);
		free(imane->map->lines);
		ftt_free(imane->map->map_two_d2);
		ftt_free(imane->map->map_two_d);
		exit(1);
	}
}

void	load_image(t_imane *imane)
{
	t_game	*game;

	game = imane->game;
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
	image_fail_to_load(imane);
}

void	render_image(t_game *game, char **two_d)
{
	int x, y;
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

int	key_handler(int keycode, t_imane *imane)
{
	if (keycode == 65307)
	{
		close_window(imane);
	}
	if (keycode == 'w' || keycode == UP)
		move_player(imane, 0, -1);
	else if (keycode == 's' || keycode == DOWN)
		move_player(imane, 0, 1);
	else if (keycode == 'd' || keycode == RIGHT)
		move_player(imane, 1, 0);
	else if (keycode == 'a' || keycode == LEFT)
		move_player(imane, -1, 0);
	return (0);
}

int	close_window(void *ptr)
{
	t_imane *imane;

	imane = (t_imane *)ptr;
	ftt_free(imane->map->map_two_d);
	ftt_free(imane->map->map_two_d2);
	mlx_destroy_image(imane->game->mlx, imane->game->player_img);
	mlx_destroy_image(imane->game->mlx, imane->game->coin_img);
	mlx_destroy_image(imane->game->mlx, imane->game->exit_img);
	mlx_destroy_image(imane->game->mlx, imane->game->wall_img);
	mlx_destroy_image(imane->game->mlx, imane->game->background_img);
	mlx_destroy_window(imane->game->mlx, imane->game->win);
	mlx_destroy_display(imane->game->mlx);
	free(imane->game->mlx);
	free(imane->map->lines);
	exit(0);
}