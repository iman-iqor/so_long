#include"header.h"

void init_map(t_map *map,char** two_d,char* lines)
{
    map->map_two_d = two_d;
    map->lines = lines;
    // map->player_x = 5;
    get_coordinates(map,'P');
    // printf("x %i\n",map->player_x);
    // printf("y %i\n",map->player_y);
    map->line_count = map_lines_count(two_d);
    // map->player_y = 1;
}