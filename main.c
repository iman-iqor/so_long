#include<unistd.h>
#include"header.h"






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
    
    

    free(lines);
    ftt_free(two_d);
    return 0;
}

