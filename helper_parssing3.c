#include"header.h"

int countcharinline(char* text,char c)
{
    int i = 0;
    int count = 0;
    while (text[i])
    {
        if(text[i++] == c)count++;
    }
    return count;
}

void check_coins(char** two_d,char* lines,int *total_c)
{
    int flag;
    int i;
    *total_c = 0;
    flag  = 0;
    i = 0;
    while(two_d[i])
    {
        (*total_c)+=countcharinline(two_d[i],'C');
        i++;
    }
    if(!(*total_c))
    {
        write(2,"invalid map no coins\n",21);
        ftt_free(two_d);
        free(lines);
        exit(1);
    }
}

void init_closed(t_closed* closed,char** two_d)
{
    closed->len = 0;
    closed->i = 0;
    closed->j = ft_strlen(*two_d);
}

void closed_error(char** two_d,char* lines)
{
    write(1,"invalid map not closed\n",23);
    free(lines);
    ftt_free(two_d);
    exit(1);
}

void is_closed_walls(char** two_d,char* lines)
{
    t_closed closed;
    init_closed(&closed,two_d);
    while(two_d[closed.len])
    {
        closed.len ++;
    }
    closed.len--;
    while(two_d[0][closed.i])
    {
        if(two_d[0][closed.i] != '1' || two_d[closed.len][closed.i] != '1')
            closed_error(two_d,lines);
        closed.i++;
    }
    closed.i = 0;
    closed.j--;
    while(closed.len >= closed.i)
    {
        if(two_d[closed.i][0] != '1' || two_d[closed.i][closed.j] != '1')
        closed_error(two_d,lines);
        closed.i++;
    }
}
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
