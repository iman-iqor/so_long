#include"header.h"

void init_map(t_map *map)
{
    get_coordinates_player(map,'P');
    get_coordinates_exit(map,'E');
    map->line_count = map_lines_count(map->map_two_d);
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