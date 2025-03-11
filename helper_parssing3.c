#include"header.h"

void check_coins(char** two_d,char* lines)
{
    int flag;
    int i;
    flag  = 0;
    i = 0;
    while(two_d[i])
    {
        if(ft_strchr(two_d[i],'C'))
            flag = 1;
        i++;
    }
    if(!flag)
    {
        write(2,"invalid map no coins\n",21);
        ftt_free(two_d);
        free(lines);
        exit(1);
    }
}