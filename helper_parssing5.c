#include"header.h"

void init_map(t_map *map,char** two_d,char* lines)
{
    map->map_two_d = two_d;
    map->lines = lines;
    // map->player_x = 5;
    get_coordinates_player(map,'P');
    get_coordinates_exit(map,'E');

    // printf("x %i\n",map->player_x);
    // printf("y %i\n",map->player_y);
    map->line_count = map_lines_count(two_d);
    // map->player_y = 1;
}

void get_coordinates_exit(t_map *map,char c)
{
    int i;
    int j;
    i = 0;
    while(map->map_two_d[i])
    {
        j = 0;
        while(map->map_two_d[i][j])
        {
            if(map->map_two_d[i][j] == c)
            {
                map->exit_x = j;
                map->exit_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}