#include<unistd.h>
#include"header.h"



int map_lines_count(char** two_d)
{
    int i;
    i = 0;
    while(two_d[i])
    {
        i++;
    } 

    return i;
}

typedef struct s_count
{
    int c_count;
    int E_found;

}   t_count;

void flood_fill(t_map *map, int x, int y,t_count* count)
{
    if(x < 0 || x  > ft_strlen(map->map_two_d[0]) || y <0 || y > map_lines_count(map->map_two_d))
        exit(1);
    if (map->map_two_d[y][x] == '1' || map->map_two_d[y][x] == 'V') // Walls or already visited
        return;
    
    if (map->map_two_d[y][x] == 'C') // Found a collectible
        count->c_count++;

    if (map->map_two_d[y][x] == 'E') // Found the exit
        count->E_found++;

    map->map_two_d[y][x] = 'V'; // Mark as visited

    flood_fill(map, x + 1, y, count);
    flood_fill(map, x - 1, y, count);
    flood_fill(map, x, y + 1, count);
    flood_fill(map, x, y - 1, count);
}

int is_valid_map(t_map * map, int player_x, int player_y, int total_C)
{
    t_count count;
    count.c_count = 0;
    count.E_found = 0;
    flood_fill(map, player_x, player_y, &count);
    if (count.c_count == total_C && count.E_found)
        return 1;
    return 0;
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
    map.map_two_d = two_d;
    map.player_x = 5;
    map.player_y = 1;
    int i;
    i = is_valid_map(&map, map.player_x, map.player_y, map.total_c);
    if(!i)
    {
        write(2,"not valid\n",10);
    }

    

    free(lines);
    ftt_free(two_d);
    return 0;
}
