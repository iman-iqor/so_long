#include"header.h"

void check_is_square(t_map *map)
{
    int len;
    int i;
    i =0;
    len = ft_strlen(map->map_two_d[0]);
    while(map->map_two_d[i])
    {
        if(len != ft_strlen(map->map_two_d[i]))
        {
            write(2,"Error : invalid map\n",20);
            ftt_free(map->map_two_d);
            ftt_free(map->map_two_d2);
            free(map->lines);
            exit(1);
        }
        i++;
    }
}
void init_player(t_player *play)
{
    play->flag = 0;
    play->i = 0;
    play->player = 0;
}

void player_error(t_map *map)
{
    write(2,"Error : wrong map no player\n",28);
        ftt_free(map->map_two_d);
        ftt_free(map->map_two_d2);
        free(map->lines);
        exit(1);
        ftt_free(map->map_two_d2);
}
void check_player(t_map *map)
{
    t_player play;
    init_player(&play);
    while(map->map_two_d[play.i])
    {
        if(ft_strchr(map->map_two_d[play.i],'P') && play.flag == 0)
        {
            play.flag = 1;
            play.player = 1;
        }
        else if(ft_strchr(map->map_two_d[play.i],'P') && play.flag == 1)
        {
            write(2,"Error : wrong map too players\n",30);
            ftt_free(map->map_two_d);
            ftt_free(map->map_two_d2);
            free(map->lines);
            exit(1);
        }
        play.i++;
    }
    if(!play.player)
    {
        player_error(map);
        
    }
}

void check_exit(t_map *map)
{
    int flag;
    int i;
    flag = 0;
    i =  0;
    while(map->map_two_d[i])
    {
        if(ft_strchr(map->map_two_d[i],'E') && flag == 0)
            flag = 1;
        else if(ft_strchr(map->map_two_d[i],'E') && flag == 1)
        {
            write(2,"Error : invalid map too many E\n",31);
            ftt_free(map->map_two_d);
            ftt_free(map->map_two_d2);
            free(map->lines);
            exit(1);
        }
        i++;
    }
    if(!flag)
    {
        write(2,"invalid map no E\n",17);
        ftt_free(map->map_two_d);
        ftt_free(map->map_two_d2);
        free(map->lines);
        exit(1);
    }
}

