#include"header.h"


void check_only_charachters(char** two_d,char* lines)
{
    int i;
    int j;
    i = 0;
    while(two_d[i])
    {
        j = 0;
        while(two_d[i][j])
        {
            if(two_d[i][j] != '1' && two_d[i][j] != 'C' && two_d[i][j] != 'P' && two_d[i][j] != 'E' && two_d[i][j] != '0')
            {
                write(1,"invalid map strange char\n",25);
                ftt_free(two_d);
                free(lines);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

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

void is_valid_map(t_map * map, int player_x, int player_y, int total_C)
{
    t_count count;
    count.c_count = 0;
    count.E_found = 0;
    flood_fill(map, player_x, player_y, &count);
    if (count.c_count != total_C && !count.E_found)
    {
        write(2,"not valid\n",10);
        ftt_free(map->map_two_d);
        free(map->lines);
        exit(1);
    }
}

void get_coordinates(t_map *map,char c)
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
                map->player_x = j;
                map->player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}


