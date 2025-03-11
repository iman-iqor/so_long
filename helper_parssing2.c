#include"header.h"

void check_is_square(char** two_d,char* lines)
{
    int len;
    int i;
    i =0;
    len = ft_strlen(two_d[0]);
    while(two_d[i])
    {
        if(len != ft_strlen(two_d[i]))
        {
            write(2,"invalid map\n",12);
            ftt_free(two_d);
            free(lines);
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
void check_exit(char** two_d,char* lines)
{
    int flag;
    int i;
    flag = 0;
    i =  0;
    while(two_d[i])
    {
        if(ft_strchr(two_d[i],'E') && flag == 0)
            flag = 1;
        else if(ft_strchr(two_d[i],'E') && flag == 1)
        {
             write(2,"invalid map too many E\n",23);
            ftt_free(two_d);
            free(lines);
            exit(1);
        }
        i++;
    }
    if(!flag)
    {
        write(2,"invalid map no E\n",17);
        ftt_free(two_d);
        free(lines);
        exit(1);
    }
}

