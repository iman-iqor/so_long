#include"header.h"

typedef struct s_splayer
{
    int flag;
    int i;
    int player;
}   t_player;

void init_player(t_player *play)
{
    play->flag = 0;
    play->i = 0;
    play->player = 0;
}

void check_player(char** two_d,char* lines)
{
    t_player play;
    init_player(&play);
    while(two_d[play.i])
    {
        if(ft_strchr(two_d[play.i],'P') && play.flag == 0)
        {
            play.flag = 1;
            play.player = 1;
        }
        else if(ft_strchr(two_d[play.i],'P') && play.flag == 1)
        {
            write(2,"wrong map\n",10);
            ftt_free(two_d);
            free(lines);
            exit(1);
        }
        play.i++;
    }
    if(!play.player)
    {
        write(2,"wrong map no player\n",20);
        ftt_free(two_d);
        free(lines);
        exit(1);
    }
}

int main(int argc,char** argv)
{
    char** two_d;
    char* lines;

    check_argc(argc);
    check_extention(argv[1]);
    check_if_file_exist(argv[1]);
   
    lines  = join_lines(argv[1]);
    two_d = split_lines(lines,'\n');
    check_is_square(two_d,lines);
    check_player(two_d,lines);
    free(lines);
    ftt_free(two_d);
    return 0;
}
