#include"header.h"

void init_game(t_game *game,char** two_d)
{
    int rows;
    int columns;
    rows = map_lines_count(two_d);
    columns = ft_strlen(two_d[0]);
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        write(2,"failed to init mlx\n",19);
        exit(1);
    }

    game->win = mlx_new_window(game->mlx, columns*67, rows*67, "so_long");
    if (!game->win)
    {
        write(2,"failed to create window\n",24);
        exit(1);
    }
}
void load_image(t_game *game)
{
    game->player_img = mlx_xpm_file_to_image(game->mlx, "pics/player1.xpm", &game->img_width, &game->img_height);
    game->coin_img = mlx_xpm_file_to_image(game->mlx, "pics/coin1.xpm", &game->img_width, &game->img_height);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "pics/wall1.xpm", &game->img_width, &game->img_height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "pics/door1.xpm", &game->img_width, &game->img_height);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "pics/background1.xpm", &game->img_width, &game->img_height);

    if (!game->player_img || !game->coin_img|| !game->wall_img || !game->exit_img || !game->floor_img)
    {
        write(2,"could not load one or more images\n",34);
        exit(1);
    }
}

void render_image(t_game *game,char** two_d)
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
                game->var= game->player_img;
            else if (two_d[y][x] == 'C')
                game->var= game->coin_img;
            else if (two_d[y][x] == '0')
                game->var= game->floor_img;
            else if (two_d[y][x] == '1')
                game->var= game->wall_img;
            else if (two_d[y][x] == 'E')
                game->var= game->exit_img;
            if (game->var)
                mlx_put_image_to_window(game->mlx, game->win,game->var, x * 67, y * 67);

            x++;
        }
        y++;
    }
}