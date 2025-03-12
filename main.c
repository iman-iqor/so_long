#include<unistd.h>
#include"header.h"



#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define ESC_KEY 65307  // MacOS: 53, Linux: 65307

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width;
    int     img_height;
}   t_game;

// Print an error message and exit
void error_exit(char *msg)
{
    write(2, msg, strlen(msg));
    exit(1);
}

// Close window when ESC is pressed
int close_window(t_game *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

// Initialize MLX and create a window
void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        error_exit("Error: MLX initialization failed\n");

    game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
    if (!game->win)
        error_exit("Error: Failed to create window\n");
}

// Load image from XPM file
void load_image(t_game *game, char *img_path)
{
    game->img = mlx_xpm_file_to_image(game->mlx, img_path, &game->img_width, &game->img_height);
    if (!game->img)
        error_exit("Error: Could not load image\n");
}

// Render the image in the window
void render_image(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->img, 
                            WIN_WIDTH / 2 - game->img_width / 2, 
                            WIN_HEIGHT / 2 - game->img_height / 2);
}

// Handle keypress events
void handle_events(t_game *game)
{
    mlx_hook(game->win, 17, 0, close_window, game); // Close on window X button
    mlx_hook(game->win, 2, 1L << 0, close_window, game); // Close on ESC key
}

// Run the game loop
void game_loop(t_game *game)
{
    mlx_loop(game->mlx);
}

int main(int argc,char** argv)
{
    char** two_d;
    char* lines;
    t_map map;

    memset(&map,0,sizeof(t_map));
    check_argc(argc);
    check_extention(argv[1]);
    check_if_file_exist(argv[1]);
   
    lines  = join_lines(argv[1]);
    two_d = split_lines(lines,'\n');
    check_is_square(two_d,lines);
    check_player(two_d,lines);
    check_exit(two_d,lines);
    check_coins(two_d,lines,&map.total_c);
    is_closed_walls(two_d,lines);
    check_only_charachters(two_d,lines);
    init_map(&map,two_d,lines);
    is_valid_map(&map, map.player_x, map.player_y, map.total_c);

    t_game game;

    init_game(&game);               // Initialize MLX and create a window
    load_image(&game, "player.xpm"); // Load the XPM image
    render_image(&game);            // Render the image in the window
    handle_events(&game);           // Handle key events
    game_loop(&game);               // Start the event loop
    return 0;
}